
#include "Dungeoned.h"

#include "LayerMenu.h"
#include "SceneGame.h"


CLayerMenu::CLayerMenu(void)
{

}



CLayerMenu::~CLayerMenu(void)
{
}



void CLayerMenu::menuStartCallback(CCObject* pSender)
{
	CSceneGame* s = CSceneGame::create();
	CCDirector::sharedDirector()->replaceScene(s);
}

void CLayerMenu::menuAboutCallback(CCObject* pSender)
{
	TRACE("%s\n",__FUNCTION__);
}

void CLayerMenu::menuEndCallback(CCObject* pSender)
{
	TRACE("%s\n",__FUNCTION__);
	if(IDOK == _CALEART(_T("你确定要退出？"),_T("魔塔对话框"),MB_OKCANCEL))
	{
		exit(0);
	}

}


bool CLayerMenu::init(void)
{
	if ( !CCLayer::init() )
	{
		return false;
	}


	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	
	CCLabelTTF* pLabel = CCLabelTTF::create(_Language.GetString("Title").data(), "黑体", TITLE_FONT_SIZE);

	// position the label on the center of the screen
	pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height - pLabel->getContentSize().height));

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	CCMenuItemFont::setFontName("宋体");
	CCMenuItemFont::setFontSize(25);

	CCMenuItemFont* start = CCMenuItemFont::create(_Language.GetString("MenuStart").data(),this,menu_selector(CLayerMenu::menuStartCallback));
	CCMenuItemFont* about =  CCMenuItemFont::create(_Language.GetString("MenuAbout").data(),this,menu_selector(CLayerMenu::menuAboutCallback));
	CCMenuItemFont* end =  CCMenuItemFont::create(_Language.GetString("MenuEnd").data(),this,menu_selector(CLayerMenu::menuEndCallback));

	CCMenu* menu= CCMenu::create(start,about,end,NULL);
	menu->alignItemsVerticallyWithPadding(20);


	this->addChild(menu);

	
	return true;
}
