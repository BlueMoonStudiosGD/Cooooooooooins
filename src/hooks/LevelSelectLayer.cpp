// colorForPage is taken from GD Lunar by capeling, MIT License:
/*
 * MIT License
 *
 * Copyright (c) 2025 capeling
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

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

    ccColor3B colorForPage(int pageID) {

    int count = m_scrollLayer->m_dynamicObjects->count();
    int page = (count + (pageID % count)) % count;

    auto GM = GameManager::sharedState();
    //5, 7, 8, 9, 10, 11, 1, 3, 4, 5, 94, 8
	int colIDs[11] = { 5, 7, 8, 9, 10, 11, 1, 3, 4, 5, 94 };
    

    return GM->colorForIdx(colIDs[page]);
    }
};