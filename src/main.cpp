#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/OptionsLayer.hpp>

class $modify(OptionsLayer) {
  void customSetup() {
    OptionsLayer::customSetup();
    auto menu = m_optionsMenu;
    if (menu) {
      menu->removeChildByID("account-button");
      menu->updateLayout();
    }
  }
};