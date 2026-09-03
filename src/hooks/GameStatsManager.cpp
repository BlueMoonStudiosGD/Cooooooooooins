#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GameStatsManager.hpp>


class $modify(GameStatsManager) {
    
    bool isItemUnlocked(UnlockType type, int id) {
        
        if(Mod::get()->getSettingValue<bool>("all-icons") && type == UnlockType::GJItem && id == 17) {
            return true;
        }
        
        return GameStatsManager::isItemUnlocked(type,id);
    }
};