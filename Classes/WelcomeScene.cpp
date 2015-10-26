#include "WelcomeScene.h"


WelcomeScene::WelcomeScene(void)
{
	_welcomeLayer=NULL;
}

WelcomeScene::~WelcomeScene(void)
{
}

bool WelcomeScene::init()
{
	bool bRet=false;
	do 
	{
		CC_BREAK_IF(!CCScene::init());
		_welcomeLayer=WelcomeLayer::create();
		CC_BREAK_IF(!_welcomeLayer);
		this->addChild(_welcomeLayer);
		PreloadMusic();
		bRet=true;
	} while (0);

	return bRet;
}

void WelcomeScene::PreloadMusic()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sound/Sound_Background.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/win.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/lose.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/bdraw.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/addPieces.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/delPieces.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/makeitem.mp3");
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sound/addPieces.mp3");

	//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/Sound_Background.mp3",true);
}