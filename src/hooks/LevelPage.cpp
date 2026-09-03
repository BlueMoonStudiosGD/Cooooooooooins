#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelPage.hpp>

class $modify(LevelPage) {

     bool init(GJGameLevel* level) {
        if (!LevelPage::init(level)) {
			return false;
		}

          for (int i = 1; i <= 3; ++i) {
            auto id = fmt::format("secret-coin-icon-{}", i);
            if (auto coin = this->getChildByID(id)) {
                coin->removeFromParent();
            }
        }

        m_coins = CCArray::create();
        m_coins->retain();

        CCPoint base = { m_levelDisplaySize.width - 16.f, 16.f };

        for (int i = 0; i < 10; ++i) {
            auto coin = CCSprite::createWithSpriteFrameName(
                "GJ_coinsIcon_001.png"
            );
            m_levelDisplay->addChild(coin);
            coin->setScale(1.0f);
            coin->setPosition({ base.x + (i * -26.0f), base.y });
            m_coins->addObject(coin);
        }

        return true;
    }

    void updateDynamicPage(GJGameLevel* level)
    {
        LevelPage::updateDynamicPage(level);

        auto gsm = GameStatsManager::sharedState();
         for (int i = 1; i <= m_coins->count(); ++i) {
            
            bool const unlocked = gsm->hasSecretCoin(level->getCoinKey(i));

            char const* frameName = unlocked
                ? "GJ_coinsIcon_001.png"
                : "GJ_coinsIcon_gray_001.png";

            auto sprite = typeinfo_cast<CCSprite*>(m_coins->objectAtIndex(m_coins->count() - i));

            auto frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);

            if (sprite && frame) {

                sprite->setDisplayFrame(frame);
            } 
        }

        if (level->m_levelID == -1) {

            if (!this->getChildByID("coming-soon-sprite")) {
                auto sprite = CCSprite::create("coming_soon_2.png"_spr);
                sprite->setID("coming-soon-sprite");
                sprite->setScale(1.175f);
                sprite->setPosition(CCDirector::sharedDirector()->getWinSize()/2);
                this->addChild(sprite);
            }

            if (auto label = this->getChildByID("coming-soon-label")) {
                label->setVisible(false);
            }

            if (auto doorMenu = this->getChildByID("button-menu")) {
                doorMenu->setVisible(false);
            }
        }
        else if (auto commingSoonSpr = this->getChildByID("coming-soon-sprite")) {
            commingSoonSpr->removeFromParent();
        }

    }
};