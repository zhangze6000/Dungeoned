#include "LayerMenu.h"
#include <cocos-ext.h>
#include "AppMacros.h"
#include <string>
#include <wchar.h>
#include "SceneGame.h"
USING_NS_CC;
USING_NS_CC_EXT;

CLayerMenu::CLayerMenu(void)
{

}



CLayerMenu::~CLayerMenu(void)
{
}

char* G2U( const char* gb2312 )
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

void CLayerMenu::menuStartCallback(CCObject* pSender)
{
	CSceneGame* s = CSceneGame::create();
	CCDirector::sharedDirector()->replaceScene(s);
}

bool CLayerMenu::init(void)
{
	if ( !CCLayer::init() )
	{
		return false;
	}


	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	
	CCLabelTTF* pLabel = CCLabelTTF::create(G2U("魔塔世界"), "黑体", TITLE_FONT_SIZE);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	CCMenuItemFont::setFontName("宋体");
	CCMenuItemFont::setFontSize(25);

	CCMenuItemFont* start = CCMenuItemFont::create(G2U("开始游戏"),this,menu_selector(CLayerMenu::menuStartCallback));
	CCMenuItemFont* about =  CCMenuItemFont::create(G2U("关于游戏"),this,NULL);
	CCMenuItemFont* end =  CCMenuItemFont::create(G2U("结束游戏"),this,NULL);

	CCMenu* menu= CCMenu::create(start,about,end,NULL);
	menu->alignItemsVerticallyWithPadding(20);


	this->addChild(menu);

	
	return true;
}
