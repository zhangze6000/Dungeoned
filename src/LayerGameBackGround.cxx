#include "Dungeoned.h"
#include "LayerGameBackGround.h"



CLayerGameBackGround::CLayerGameBackGround(void)
{

}



CLayerGameBackGround::~CLayerGameBackGround(void)
{
}


bool CLayerGameBackGround::init(void)
{
	if ( !CCLayer::init() )
	{
		return false;
	}


	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	
	CCLabelTTF* pLabel = CCLabelTTF::create(_CG2U("游戏世界"), "黑体", TITLE_FONT_SIZE);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(pLabel, 1);


	
	return true;
}
