#include "BeginningDialogueScene.h"
#include "CustomizeCarScene.h"

cocos2d::Scene* BeginningDialogueScene::createScene()
{
	/*
	*	Create a scene from the cocos2d library that will hold the
	*	Main Menu layer, displaying the buttons for moving across the
	*	game's menu system and getting to the game, as well as displays
	*	the title screen
	*/
	auto scene = cocos2d::Scene::create();
	auto layer = BeginningDialogueScene::create();
	scene->addChild(layer);

	return scene;
}

bool BeginningDialogueScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	/*
	*	The cocos2d::Director functions as a scene manager, navigating
	*	the code through the scenes that make up the game. It also holds
	*	the renderer and other information on the various components that
	*	keep the game running.
	*/
	cocos2d::Director* director = cocos2d::Director::getInstance();

	auto visibleSize = director->getVisibleSize();
	cocos2d::Vec2 origin = director->getVisibleOrigin();

	GameManager* gm = GameManager::getInstance();


	auto sprite = cocos2d::Sprite::create("Story.png");
	sprite -> setScale(gm->scaler);
	sprite->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height / 2// - 20
		)
	);

	this->addChild(sprite, 1);

	auto listener1 = cocos2d::EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		static int x = 0;

		auto target = static_cast<cocos2d::Sprite*>(event->getCurrentTarget());

		cocos2d::Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		cocos2d::Size s = target->getContentSize();
		cocos2d::Rect rect = cocos2d::Rect(0, 0, s.width, s.height);
		float originalXPos = target->getPosition().x;
		float originalYPos = target->getPosition().y;

		if (rect.containsPoint(locationInNode))
		{
			x++;
			if (x == 1)
			{
				target->setTexture("Story2.png");
			}
			else
			{
				goToCustomize(NULL);
			}
			return true;
		}
		return false;
		
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite);

	return true;
}


void BeginningDialogueScene::goToCustomize(cocos2d::Ref* pSender)
{
	auto CustomizeScene = CustomizeCarScene::createScene();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(2,CustomizeScene));
}