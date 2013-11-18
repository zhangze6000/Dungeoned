#include "SceneMenu.h"


CSceneGame::CSceneGame(void)
{

}


CSceneGame::~CSceneGame(void)
{
}


// 创建菜单场景
CSceneGame* CSceneGame::create(void)
{
	CSceneGame * pScene = new CSceneGame();
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
