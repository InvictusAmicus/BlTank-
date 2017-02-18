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

	/*	
	*	Create an instance of the Game Manager
	*	If this is the first call to getInstance(),
	*	create the Game Manager
	*/
	GameManager* gm = GameManager::getInstance();

	/*
	*	This block of code creates the sprite for the story
	*	sets its position and puts it in the game scene.
	*/
	auto sprite = cocos2d::Sprite::create("Story.png");
	sprite -> setScale(gm->scaler);
	sprite->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height / 2
		)
	);
	this->addChild(sprite, 1);

	/*
	*	Creates the event listener that listens for user
	*	input. In this case, it is a touch listener, as it
	*	works with PC (mouse clicks) and android phones
	*	(screen touches)
	*/
	auto listener1 = cocos2d::EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);
	/*
	*	Says what to do when a touch is detected
	*/
	listener1->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		static int x = 0;

		auto target = static_cast<cocos2d::Sprite*>(event->getCurrentTarget());

		cocos2d::Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		cocos2d::Size s = target->getContentSize();
		cocos2d::Rect rect = cocos2d::Rect(0, 0, s.width, s.height);
		float originalXPos = target->getPosition().x;
		float originalYPos = target->getPosition().y;

		/*
		*	If the touch was on the story image,
		*	advance the game
		*/
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
	// add the eventlistener into the scene
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, sprite);

	return true;
}

/*
*	This method calls the director to take the
*	game to the next stage of the game, the
*	scene where the player chooses the character
*	 they want to play as.
*/
void BeginningDialogueScene::goToCustomize(cocos2d::Ref* pSender)
{
	auto CustomizeScene = CustomizeCarScene::createScene();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(2,CustomizeScene));
}
