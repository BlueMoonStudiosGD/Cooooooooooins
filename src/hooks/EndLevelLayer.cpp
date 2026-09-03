#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/EndLevelLayer.hpp>


class $modify(EndLevelLayer) {
    void onMenu(CCObject* sender) {
        int const levelID = PlayLayer::get()->m_level->m_levelID;

        int mainLevelIDs[10] = { 1, 2, 3, 8, 13, 14, 17, 19, 20, 21 };

        for (int page = 0; page < 10; page++) {
            if (mainLevelIDs[page] == levelID) {
                CCDirector::sharedDirector()->replaceScene(
                    CCTransitionFade::create(0.5f, LevelSelectLayer::scene(page))
                );
                break;
            }
        }

        EndLevelLayer::onMenu(sender);
    }
};