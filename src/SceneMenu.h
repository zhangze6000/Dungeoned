#pragma once
#include "cocos2d.h"
#include "LayerMenu.h"
class CSceneMenu :public cocos2d::CCScene
{
public:
	CSceneMenu(void);
	~CSceneMenu(void);

	// 创建菜单场景
	static CSceneMenu* create(void);
};

