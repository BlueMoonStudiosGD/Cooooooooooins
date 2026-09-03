#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/PauseLayer.hpp>


class $modify(PauseLayer)
{
     void onQuit(CCObject* sender) {

    int levelID = PlayLayer::get()->m_level->m_levelID;

    auto director = CCDirector::sharedDirector();

    int mainLevelIDs[10] = { 1, 2, 3, 8, 13, 14, 17, 19, 20, 21 };

    for (int i = 0; i < 10; i++) {
        if (mainLevelIDs[i] == levelID) {
            director->replaceScene(CCTransitionFade::create(0.5f, LevelSelectLayer::scene(i)));
            break;
        }
    }

        PauseLayer::onQuit(sender);

	}
};