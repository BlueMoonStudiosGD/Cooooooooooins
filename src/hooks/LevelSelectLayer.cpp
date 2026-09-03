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

	
	int mainLevelIDs[10] = { 1, 2, 3, 8, 13, 14, 17, 19, 20, 21 };

	auto GLM = GameLevelManager::sharedState();
	for (int i = 0; i < 10; i++) {
		auto level = GLM->getMainLevel(mainLevelIDs[i], true);
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
	updatePageWithObject(m_scrollLayer->m_pages->objectAtIndex(pageID % m_scrollLayer->m_pages->count()),
		m_scrollLayer->m_dynamicObjects->objectAtIndex(pageID));
	m_scrollLayer->repositionPagesLooped();

    return true;
	}

    ccColor3B colorForPage(int pageID) { //taked from gd lunar, thanks cap!

    int count = m_scrollLayer->m_dynamicObjects->count();
    int page = (count + (pageID % count)) % count;

    auto GM = GameManager::sharedState();
    //5, 7, 8, 9, 10, 11, 1, 3, 4, 5, 94, 8
	int colIDs[11] = { 5, 7, 8, 9, 10, 11, 1, 3, 4, 5, 94 };
    

    return GM->colorForIdx(colIDs[page]);
    }
};