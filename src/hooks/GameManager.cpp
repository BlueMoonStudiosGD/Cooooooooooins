#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GameManager.hpp>


class $modify(GameManager) {
    
    bool isIconUnlocked(int id, IconType type) {
        
        if(Mod::get()->getSettingValue<bool>("all-icons")) {
            return true;
        }
        
        return GameManager::isIconUnlocked(id,type);
    }

    bool isColorUnlocked(int id, UnlockType type) {

        if(Mod::get()->getSettingValue<bool>("all-icons")) {
            return true;
        }
        
        return GameManager::isColorUnlocked(id,type);
    }
};