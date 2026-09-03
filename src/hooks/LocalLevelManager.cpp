#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LocalLevelManager.hpp>

class $modify(LocalLevelManager) {

    gd::string getMainLevelString(int id) {
        auto const path = fmt::format("tencoins-{}.txt"_spr, id);

        if (auto content = CCString::createWithContentsOfFile(path.c_str())) {
            return gd::string(content->getCString());
        }

        return LocalLevelManager::getMainLevelString(id);
    }
};