#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/LevelSelectLayer.hpp>


class $modify(LevelSelectLayer)
{
     bool init(int pageID) {

         if (!LevelSelectLayer::init(pageID)) {
			return false;
		}

     m_scrollLayer->m_dynamicObjects->removeAllObjects();

	auto dotsArray = CCArrayExt<CCSprite*>(m_scrollLayer->m_dots);

	for (CCSprite* dot : dotsArray) {
		dot->removeFromParent();
	}
	m_scrollLayer->m_dots->removeAllObjects();

	
	std::vector<std::tuple<int, const char*>> levels = {
		{1, "Stereo Madness"},
		{2, "Back on Track"},
		{3, "Polargeist"},
        {8, "Time Machine"},
        {13, "Electroman Adventures"},
        {14, "Clubstep"},
        {17, "Blast Processing"},
        {19, "Geometrical Dominator"},
        {20, "Deadlocked"},
        {21, "Fingerdash"}
	};



	auto GLM = GameLevelManager::sharedState();
	for (auto [id, name] : levels) {
		auto level = GLM->getMainLevel(id, true);

		m_scrollLayer->m_dynamicObjects->addObject(level);
	}

	auto comingSoon = GJGameLevel::create();
	comingSoon->m_levelID = -1;
	m_scrollLayer->m_dynamicObjects->addObject(comingSoon);

	auto batchNode = CCSpriteBatchNode::create("smallDot.png", 29);
	m_scrollLayer->addChild(batchNode, 5);

	for (int i = 0; i < m_scrollLayer->m_dynamicObjects->count(); i++) {
		auto sprite = CCSprite::create("smallDot.png");
		batchNode->addChild(sprite);
		m_scrollLayer->m_dots->addObject(sprite);
	}

	m_scrollLayer->updateDots(0.f);
	m_scrollLayer->updatePages();
	updatePageWithObject(m_scrollLayer->m_pages->objectAtIndex(pageID),
		m_scrollLayer->m_dynamicObjects->objectAtIndex(pageID));
	m_scrollLayer->repositionPagesLooped();

    return true;
	}
};