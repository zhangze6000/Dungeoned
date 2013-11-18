#include "SceneMenu.h"


CSceneMenu::CSceneMenu(void)
{

}


CSceneMenu::~CSceneMenu(void)
{
}


// 创建菜单场景
CSceneMenu* CSceneMenu::create(void)
{
	CSceneMenu * pScene = new CSceneMenu();
	if(pScene && pScene->init())
	{
		pScene->autorelease();
		CLayerMenu *layer = CLayerMenu::create();

		// add layer as a child to scene
		pScene->addChild(layer);
		return pScene;
	}
	CC_SAFE_DELETE(pScene);
	return NULL;
}
