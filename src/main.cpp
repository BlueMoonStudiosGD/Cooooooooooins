#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
			return false;
		}

        if (auto menu = this->getChildByID("main-menu")) {
            menu->removeChildByID("editor-button");
            menu->updateLayout();
        }

        return true;
    }
};
