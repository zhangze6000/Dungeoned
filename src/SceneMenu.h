#pragma once
#include "cocos2d.h"
#include "LayerMenu.h"
class CSceneMenu :public cocos2d::CCScene
{
public:
	CSceneMenu(void);
	~CSceneMenu(void);

	// �����˵�����
	static CSceneMenu* create(void);
};

