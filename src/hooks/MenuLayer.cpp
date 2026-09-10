#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayer) {
  bool init() {

    if (!MenuLayer::init()) {
      return false;
    }

    auto menu = this->getChildByID("main-menu");

    if (menu) {
      //menu->removeChildByID("editor-button");
      auto grayFrame = CCSpriteGrayscale::createWithSpriteFrameName("GJ_creatorBtn_001.png");
      auto editorBtn = typeinfo_cast<CCMenuItemSpriteExtra*>(menu->getChildByID("editor-button"));
      if (editorBtn) {
         editorBtn->setSprite(grayFrame);
      }
      
    }

    auto gsm = GameStatsManager::sharedState();

    int coinsStat = gsm->getStat("8");
    int coinsSaved = Mod::get()->getSavedValue<int>("secret-coins");
    int newCoins = coinsStat - coinsSaved;

    if (newCoins < 0) {
      newCoins = 0;
    }

    Mod::get()->setSavedValue("secret-coins", coinsStat);

    if (newCoins > 0) {
      this->showCoins(newCoins, coinsSaved);
    }

    return true;
  }

  void showCoins(int newCoins, int oldCoins) {

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto centerX = winSize.width / 2;
    auto centerY = winSize.height / 2;

    auto bg = CCLayerColor::create();
    bg->setColor(ccBLACK);
    bg->setContentSize(winSize);

    this->setKeypadEnabled(false);  

    CCDirector::sharedDirector()->getTouchDispatcher()->setDispatchEvents(false); //JESUS CHRIST, WHY SETTOUCHENABLED DOESN'T WORK
    this->addChild(bg, 200);

    bg->runAction(CCFadeTo::create(0.3f, 180));

    auto secretCoin =
        CCSprite::createWithSpriteFrameName("secretCoin_01_001.png");
    secretCoin->setPosition({centerX, centerY});
    secretCoin->setScale(0);
    bg->addChild(secretCoin, 210);

    secretCoin->runAction(CCSequence::create(
        CCScaleTo::create(1.5f, 0.5f),
        CCEaseBackOut::create(CCScaleTo::create(0.5f, 1.5f)), nullptr));

    FMODAudioEngine::sharedEngine()->playEffect("unlockGauntlet.ogg");

    auto lbl1 = CCLabelBMFont::create(fmt::format("New coins collected: {}",newCoins).c_str(),
        "bigFont.fnt");

    lbl1->setPosition({centerX, centerY + 80});
    lbl1->setOpacity(0);
    lbl1->setScale(0.5f);

    bg->addChild(lbl1, 210);

    lbl1->runAction(CCSequence::create(CCDelayTime::create(0.8f),
                                       CCFadeTo::create(0.3f, 255), nullptr));

    auto lbl2 = CCLabelBMFont::create(fmt::format("Your coins: {}", oldCoins).c_str(), "bigFont.fnt");

    lbl2->setPosition({centerX, 60});
    lbl2->setOpacity(0);
    lbl2->setScale(0.65f);

    bg->addChild(lbl2, 210);

    lbl2->runAction(CCSequence::create(CCDelayTime::create(0.8f),
                                       CCFadeTo::create(0.3f, 255), nullptr));

    int show = newCoins;

    if (show > 10) {
      show = 10;
    }

    int total = oldCoins;

    for (int i = 0; i < show; i++) {

      int coinAdd = newCoins / show;

      if (i < newCoins % show) {
        coinAdd++;
      }

      total += coinAdd;

      auto coin = CCSprite::createWithSpriteFrameName("secretCoin_01_001.png");
      coin->setScale(0);
      coin->setPosition({centerX, centerY});

      bg->addChild(coin, 209);

      coin->runAction(CCSequence::create(CCDelayTime::create(2.0f + i * 0.3f + 0.15f),
          CCMoveTo::create(0.3f, lbl2->getPosition()), nullptr));


        secretCoin->runAction(CCSequence::create(
            CCDelayTime::create(2.0f + i * 0.3f),
            CallFuncExt::create([=] {
                secretCoin->stopActionByTag(9002);
                secretCoin->setScale(1.2f);
                secretCoin->runAction(
                    CCEaseElasticOut::create(CCScaleTo::create(0.6f, 1.5f), 0.4f)
                )->setTag(9002);
            }),
            nullptr
        ));
       
      coin->runAction(CCSequence::create(

          CCDelayTime::create(2.0f + i * 0.3f),
          CCEaseBackOut::create(CCScaleTo::create(0.15f, 0.8f)),
          CCScaleTo::create(0.3f, 0),
          CallFuncExt::create([=] {

            FMODAudioEngine::sharedEngine()->playEffect("highscoreGet02.ogg");

            lbl2->setString(fmt::format("Your coins: {}", total).c_str());
            lbl2->stopActionByTag(9001);
            lbl2->setScale(1.2f);

            auto pop = CCEaseBackOut::create(CCScaleTo::create(0.15f, 0.65f));
            pop->setTag(9001);

            lbl2->runAction(pop);

            coin->removeFromParentAndCleanup(true);

            if (i == show - 1) {

              this->setKeypadEnabled(true); 
              CCDirector::sharedDirector()->getTouchDispatcher()->setDispatchEvents(true);

              bg->setCascadeOpacityEnabled(true);

              bg->runAction(CCSequence::create(
      CCFadeTo::create(0.5f, 0),
               CallFuncExt::create([=] {
               bg->removeFromParentAndCleanup(true); 
              }),nullptr));

            }
          }),
          nullptr));

    }
  }

  void onCreator(CCObject* sender) {

    geode::createQuickPopup(
         Mod::get()->getName().c_str(),
        "You <cr>can't access</c> the full version options.\n\n"
        "To prevent bans, your <cy>original data</c> and <cy>login access</c> have been <cy>temporarily removed</c> while the mod is active.\n\n"
        "<cg>Don't worry!</c> Your data is <cg>safe!</c> Just <cl>disable the mod</c> to restore everything to normal.",
        "OK",nullptr,nullptr
    );
   
  }
};
