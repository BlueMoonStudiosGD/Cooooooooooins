#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GameManager.hpp>

class $modify(GameManager) {

  bool isIconUnlocked(int id, IconType type) {

    if (Mod::get()->getSettingValue<bool>("all-icons")) {
      return true;
    }

    return GameManager::isIconUnlocked(id, type);
  }

  bool isColorUnlocked(int id, UnlockType type) {

    if (Mod::get()->getSettingValue<bool>("all-icons")) {
      return true;
    }

    return GameManager::isColorUnlocked(id, type);
  }

  void returnToLastScene(GJGameLevel *level) {

    int levelID = PlayLayer::get()->m_level->m_levelID;

    auto director = CCDirector::sharedDirector();

    int mainLevelIDs[10] = {1, 2, 3, 8, 13, 14, 17, 19, 20, 21};

    for (int i = 0; i < 10; i++) {
      if (mainLevelIDs[i] == levelID) {
        director->replaceScene(
            CCTransitionFade::create(0.5f, LevelSelectLayer::scene(i)));
        break;
      }
    }

    GameManager::returnToLastScene(level);
  }
};