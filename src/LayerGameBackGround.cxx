#include "LayerGameBackGround.h"
#include <cocos-ext.h>
#include "AppMacros.h"
#include <string>
#include <wchar.h>
USING_NS_CC;
USING_NS_CC_EXT;

CLayerGameBackGround::CLayerGameBackGround(void)
{

}



CLayerGameBackGround::~CLayerGameBackGround(void)
{
}

static char* G2U( const char* gb2312 )
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);    
	wchar_t* wstr = new wchar_t[len+1];    
	memset(wstr, 0, len+1);    
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);    
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);    
	char* str = new char[len+1];    
	memset(str, 0, len+1);    
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);    
	if(wstr) delete[] wstr;    
	return str;
}
bool CLayerGameBackGround::init(void)
{
	if ( !CCLayer::init() )
	{
		return false;
	}


	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	
	CCLabelTTF* pLabel = CCLabelTTF::create(G2U("游戏世界"), "黑体", TITLE_FONT_SIZE);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(pLabel, 1);


	
	return true;
}
