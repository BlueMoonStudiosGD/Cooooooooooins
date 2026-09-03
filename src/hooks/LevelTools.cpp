#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelTools.hpp>

class $modify(LevelTools) {

     static bool verifyLevelIntegrity(gd::string verifyString, int levelID) {
         
        return true;
    }

    static GJGameLevel* getLevel(int levelID, bool loaded) {

        auto level = LevelTools::getLevel(levelID, loaded);

        switch (levelID) {
        case 1:
            level->m_levelName = "Stereo Madness";
            level->m_audioTrack = 0;
            level->m_stars = 1;
            level->m_difficulty = GJDifficulty::Easy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 2:
            level->m_levelName = "Back on Track";
            level->m_audioTrack = 1;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Easy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 3:
            level->m_levelName = "Polargeist";
            level->m_audioTrack = 2;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 8:
            level->m_levelName = "Time Machine";
            level->m_audioTrack = 7;
            level->m_stars = 8;
            level->m_difficulty = GJDifficulty::Harder;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 13:
            level->m_levelName = "Electroman Adventures";
            level->m_audioTrack = 12;
            level->m_stars = 10;
            level->m_difficulty = GJDifficulty::Insane;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 14:
            level->m_levelName = "Clubstep";
            level->m_audioTrack = 13;
            level->m_stars = 14;
            level->m_demon = 1;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 17:
            level->m_levelName = "Blast Processing";
            level->m_audioTrack = 16;
            level->m_stars = 10;
            level->m_difficulty = GJDifficulty::Harder;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 19:
            level->m_levelName = "Geometrical Dominator";
            level->m_audioTrack = 18;
            level->m_stars = 10;
            level->m_difficulty = GJDifficulty::Harder;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 20:
            level->m_levelName = "Deadlocked";
            level->m_audioTrack = 19;
            level->m_stars = 15;
            level->m_demon = 1;
            level->m_difficulty = GJDifficulty::DemonEasy;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;
        case 21:
            level->m_levelName = "Fingerdash";
            level->m_audioTrack = 20;
            level->m_stars = 12;
            level->m_difficulty = GJDifficulty::Insane;
            level->m_requiredCoins = 0;
            level->m_timestamp = 0;
            level->m_coins = 10;
            break;

        default:
            return level;
        }



        if (!loaded) {
            level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
        }
        level->m_levelID = levelID;
        level->m_levelType = GJLevelType::Main;

        return level;


    }
};