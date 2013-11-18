#pragma once
#include "cocos2d.h"
class CLayerGameBackGround :
	public cocos2d::CCLayer
{
public:
	CLayerGameBackGround(void);
	~CLayerGameBackGround(void);
	bool init(void);
	void menuStartCallbackCallback(CCObject* pSender);
	CREATE_FUNC(CLayerGameBackGround);
};

