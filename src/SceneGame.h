#pragma once
#include "cocos2d.h"
#include "LayerGameBackGround.h"
class CSceneGame :public cocos2d::CCScene
{
public:
	CSceneGame(void);
	~CSceneGame(void);

	// �����˵�����
	static CSceneGame* create(void);
};

