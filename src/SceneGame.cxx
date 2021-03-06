#include "SceneGame.h"


CSceneGame::CSceneGame(void)
{

}


CSceneGame::~CSceneGame(void)
{
}


// �����˵�����
CSceneGame* CSceneGame::create(void)
{
	CSceneGame * pScene = new CSceneGame();
	if(pScene && pScene->init())
	{
		pScene->autorelease();
		CLayerGameBackGround *layer = CLayerGameBackGround::create();

		// add layer as a child to scene
		pScene->addChild(layer);
		return pScene;
	}
	CC_SAFE_DELETE(pScene);
	return NULL;
}
