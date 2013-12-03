#pragma once
#include "cocos2d.h"
class CLayerMenu :
	public cocos2d::CCLayer
{
public:
	CLayerMenu(void);
	~CLayerMenu(void);
	bool init(void);
	void menuStartCallback(CCObject* pSender);
	void menuAboutCallback(CCObject* pSender);
	void menuEndCallback(CCObject* pSender);
	CREATE_FUNC(CLayerMenu);
};

