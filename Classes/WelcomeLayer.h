
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class WelcomeLayer :
	public CCLayer
{
public:

	WelcomeLayer(void);

	~WelcomeLayer(void);

	virtual bool init();

	CREATE_FUNC(WelcomeLayer);

	void loadingDone(CCNode* pNode);
	virtual void keyBackClicked();//Android���ؼ�
	bool isHaveSaveFile();
	void getHighestHistorySorce();

	void menuOnlineCallback(CCObject* pSender);
	void menuSingleCallback(CCObject* pSender);
	void menuHelpCallback(CCObject* pSender);
	void menuShareCallback(CCObject* pSender);
	void menuAboutCallback(CCObject* pSender);

public:

	CCMenuItemImage* pOnlineItem;
	CCMenuItemImage* pSingleItem;

	CCMenuItemImage* pHelpItem;
	CCMenuItemImage* pAboutItem;
	CCMenuItemImage* pShareItem;

};
