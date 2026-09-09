#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LocalLevelManager.hpp>

class $modify(LocalLevelManager) {

  gd::string getMainLevelString(int id) {
    
    auto path = Mod::get()->getResourcesDir() / fmt::format("tencoins-{}.txt", id);

    auto levelString = file::readString(path);

    if (levelString.isOk()) {
      return gd::string(levelString.unwrap());
    }

    return LocalLevelManager::getMainLevelString(id);
  }
};