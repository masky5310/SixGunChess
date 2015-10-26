

#include "SplashScreen.h"
#include "WelcomeScene.h"


using namespace cocos2d;

CCScene* SplashScreen::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        SplashScreen *layer = SplashScreen::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScreen::init()
{
    bool bRet = false;
    do 
    {
        //////////////////////////////////////////////////////////////////////////
        // super init first
        //////////////////////////////////////////////////////////////////////////

        CC_BREAK_IF(! CCLayer::init());

        //////////////////////////////////////////////////////////////////////////
        // add your codes below...
        //////////////////////////////////////////////////////////////////////////

        // 1. Add a menu item with "X" image, which is clicked to quit the program.

        // Create a "close" menu item with close icon, it's an auto release object.
        //CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
        //    "CloseNormal.png",
        //    "CloseSelected.png",
        //    this,
        //    menu_selector(SplashScreen::menuCloseCallback));
       // CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        //pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
       // CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
       // pMenu->setPosition(CCPointZero);
       // CC_BREAK_IF(! pMenu);

        // Add the menu to HelloWorld layer as a child layer.
       // this->addChild(pMenu, 1);

        // 2. Add a label shows "Hello World".

		initData();

        bRet = true;
    } while (0);

    return bRet;
}

void SplashScreen::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}

void SplashScreen::initData()
{
	do 
	{
		// Create a label and initialize with string "Hello World".
		CCLabelTTF* pLabel = CCLabelTTF::create("Six stick chess", "Marker Felt", 24);
		CC_BREAK_IF(! pLabel);

		// Get window size and place the label upper. 
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		pLabel->setPosition(ccp(size.width / 2, size.height - 100));
		pLabel->setVisible(false);
		// Add the label to HelloWorld layer as a child layer.
		this->addChild(pLabel, 1,kTagLable);

		// 3. Add add a splash screen, show the cocos2d splash image.
		CCSprite* pSprite = CCSprite::create("logo.png");
		CC_BREAK_IF(! pSprite);

		// Place the sprite on the center of the screen
		pSprite->setPosition(ccp(size.width/2, size.height/2));

		// Add the sprite to HelloWorld layer as a child layer.
		this->addChild(pSprite, 0);

	} while (false);

}


void SplashScreen::onEnter()
{
	CCLayer::onEnter();

	CCSprite* pSprite = (CCSprite*)getChildByTag(kTagLable);
	pSprite->runAction(CCSequence::create(CCDelayTime::create(2),CCCallFunc::create(this,callfunc_selector(SplashScreen::startGame)),NULL));
}

void SplashScreen::startGame()
{
	//CCScene *pScene= WelcomeScene::create();
	WelcomeScene *pScene= WelcomeScene::create();
	//ÌøÔ¾Ê½¶¯»­
	//CCDirector::sharedDirector()->replaceScene(CCTransitionJumpZoom::create(1.2f,pScene));
	CCDirector::sharedDirector()->replaceScene(pScene);
}

