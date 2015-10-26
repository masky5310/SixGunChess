


#include "WelcomeLayer.h"
#include "GameScene.h"
//#include "GameOverLayer.h"

WelcomeLayer::WelcomeLayer(void)
{
	pOnlineItem = NULL;
	pSingleItem = NULL;

	pHelpItem = NULL;
	pShareItem = NULL;
	pAboutItem = NULL;
}

WelcomeLayer::~WelcomeLayer(void)
{
}

bool WelcomeLayer::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		//png加入全局cache中
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui/GameUi0.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui/GameUi1.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui/GameUi2.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui/GameUi3.plist");
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui/GameUi4.plist");

		CCSize winSize=CCDirector::sharedDirector()->getWinSize();

		//加入background
		CCSprite* background=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("Background_Grass.png"));
		background->setPosition(ccp(winSize.width/2,winSize.height/2));
		this->addChild(background);

		//加入six chess logo
		CCSprite* chessLogo=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("wugunqi.png"));
		//chessLogo->setAnchorPoint(ccp(0.5,0));
		chessLogo->setPosition(ccp(winSize.width/2,winSize.height-150));
		this->addChild(chessLogo);

		//加入联网对战菜单
		CCSprite* BtnOnlineGame=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnOnlineGame.png"));
		CCSprite* BtnOnlineGamePress=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnOnlineGamePress.png"));
		pOnlineItem=CCMenuItemImage::create();
		pOnlineItem->initWithNormalSprite(BtnOnlineGame,BtnOnlineGamePress,NULL,this,menu_selector(WelcomeLayer::menuOnlineCallback));
		//pOnlineItem->setPosition(ccp(BtnOnlineGame->getContentSize().width/2+10,winSize.height-BtnOnlineGame->getContentSize().height/2-10));
		pOnlineItem->setPosition(ccp(winSize.width/2,winSize.height/2));
		CCMenu *menuOnline=CCMenu::create(pOnlineItem,NULL);
		menuOnline->setPosition(CCPointZero);
		this->addChild(menuOnline,101);

		//加入单机对战按钮
		CCSprite* BtnSignleGame=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnSignleGame.png"));
		CCSprite* BtnSignleGamePress=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnSignleGamePress.png"));
		pSingleItem=CCMenuItemImage::create();
		pSingleItem->initWithNormalSprite(BtnSignleGame,BtnSignleGamePress,NULL,this,menu_selector(WelcomeLayer::menuSingleCallback));
		pSingleItem->setPosition(ccp(winSize.width/2,winSize.height/2-150));
		CCMenu *menuSingle=CCMenu::create(pSingleItem,NULL);
		menuSingle->setPosition(CCPointZero);
		this->addChild(menuSingle,101);

		//加入玩法介绍
		CCSprite* BtnHelp=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnHelp.png"));
        CCSprite* BtnHelp_1=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnHelp_1.png"));
		pHelpItem=CCMenuItemImage::create();
		pHelpItem->initWithNormalSprite(BtnHelp,BtnHelp_1,NULL,this,menu_selector(WelcomeLayer::menuHelpCallback));
		pHelpItem->setPosition(ccp(BtnHelp->getContentSize().width/2,BtnHelp->getContentSize().height/2));
		CCMenu *menuHelp=CCMenu::create(pHelpItem,NULL);
		menuHelp->setPosition(CCPointZero);
		this->addChild(menuHelp,101);

		//加入分享
		CCSprite* BtnShare=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnShare.png"));
		CCSprite* BtnShare_1=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnShare_1.png"));
		pShareItem=CCMenuItemImage::create();
		pShareItem->initWithNormalSprite(BtnShare,BtnShare_1,NULL,this,menu_selector(WelcomeLayer::menuShareCallback));
		pShareItem->setPosition(ccp(winSize.width/2,BtnShare->getContentSize().height/2));
		CCMenu *menuShare=CCMenu::create(pShareItem,NULL);
		menuShare->setPosition(CCPointZero);
		this->addChild(menuShare,101);

		//加入关于
		CCSprite* BtnAbout=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnAbout.png"));
		CCSprite* BtnAbout_1=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("BtnAbout_1.png"));
		pAboutItem=CCMenuItemImage::create();
		pAboutItem->initWithNormalSprite(BtnAbout,BtnAbout_1,NULL,this,menu_selector(WelcomeLayer::menuAboutCallback));
		pAboutItem->setPosition(ccp(winSize.width-BtnAbout->getContentSize().width/2,BtnAbout->getContentSize().height/2));
		CCMenu *menuAbout=CCMenu::create(pAboutItem,NULL);
		menuAbout->setPosition(CCPointZero);
		this->addChild(menuAbout,101);

		/*
		//加入copyright
		CCSprite* copyright=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("shoot_copyright.png"));
		copyright->setAnchorPoint(ccp(0.5,0));
		copyright->setPosition(ccp(winSize.width/2,winSize.height/2));
		this->addChild(copyright);

		//加入loading
		CCSprite* loading=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_loading1.png"));
		loading->setPosition(ccp(winSize.width/2,winSize.height/2-40));
		this->addChild(loading);

		CCAnimation* animation=CCAnimation::create();
		animation->setDelayPerUnit(0.2f);
		animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_loading1.png"));
		animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_loading2.png"));
		animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_loading3.png"));
		animation->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("game_loading4.png"));

		CCAnimate* animate=CCAnimate::create(animation);
		CCRepeat* repeat=CCRepeat::create(animate,2);
		CCCallFuncN* repeatdone=CCCallFuncN::create(this,callfuncN_selector(WelcomeLayer::loadingDone));
		CCSequence* sequence=CCSequence::create(repeat,repeatdone,NULL);
		loading->runAction(sequence);
		*/
		getHighestHistorySorce();

		this->setKeypadEnabled(true);

		bRet=true;
	} while (0);

	return bRet;
}

void WelcomeLayer::loadingDone(CCNode* pNode)
{
	//CCScene* pScene=GameScene::create();
	//CCTransitionMoveInB *animateScene=CCTransitionMoveInB::create(0.5f,pScene);
	//CCDirector::sharedDirector()->replaceScene(animateScene);
}

void WelcomeLayer::keyBackClicked()
{
	CCDirector::sharedDirector()->end();
}

bool WelcomeLayer::isHaveSaveFile()
{
	if(!CCUserDefault::sharedUserDefault()->getBoolForKey("isHaveSaveFileXml"))
	{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isHaveSaveFileXml", true);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("HighestScore",0);
		CCUserDefault::sharedUserDefault()->flush();
		return false;
	}
	else
	{
		return true;
	}
}

void WelcomeLayer::getHighestHistorySorce()
{
	if (isHaveSaveFile())
	{
		//GameOverLayer::highestHistoryScore=CCUserDefault::sharedUserDefault()->getIntegerForKey("HighestScore",0);
	}
}

void WelcomeLayer::menuOnlineCallback(CCObject* pSender)
{
	//
}

void WelcomeLayer::menuSingleCallback(CCObject* pSender)
{
	//	//CCScene *pScene= WelcomeScene::create();
	GameScene *pScene= GameScene::create();
	//跳跃式动画
	//CCDirector::sharedDirector()->replaceScene(CCTransitionJumpZoom::create(1.2f,pScene));
	CCDirector::sharedDirector()->replaceScene(pScene);
}

void WelcomeLayer::menuHelpCallback(CCObject* pSender)
{
	//
}

void WelcomeLayer::menuShareCallback(CCObject* pSender)
{
	//
}

void WelcomeLayer::menuAboutCallback(CCObject* pSender)
{
	//
}