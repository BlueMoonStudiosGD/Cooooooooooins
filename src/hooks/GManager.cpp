#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/GManager.hpp>


class $modify(GManager)
{
     void setup() {
        auto compare = std::string(m_fileName);

        compare.insert(std::string_view(compare).find(".dat"), "coinslevels");

        m_fileName = compare;
        GManager::setup();
	}
};