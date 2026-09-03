#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EndLevelLayer.hpp>


class $modify(EndLevelLayer)
{
     void onMenu(CCObject* sender) {

    int levelID = PlayLayer::get()->m_level->m_levelID;
    
    auto director = CCDirector::sharedDirector();

    switch(levelID)
    {
        case 1:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(0)));
        break;
        case 2:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(1)));
        break;
        case 3:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(2)));
        break;
        case 8:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(3)));
        break;
        case 13:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(4)));
        break;
        case 14:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(5)));
        break;
        case 17:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(6)));
        break;
        case 19:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(7)));
        break;
        case 20:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(8)));
        break;
        case 21:
        director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(9)));
        break;
    }

        EndLevelLayer::onMenu(sender);

	}
};