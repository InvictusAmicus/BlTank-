#include "CustomizeCarScene.h"
#include "GameManager.h"
#include "Game.h"

#define health1 1000
#define health2 1001
#define health3 1002
#define health4 1003
#define health5 1004
#define health6 1005

#define speed1 2000
#define speed2 2001
#define speed3 2002
#define speed4 2003
#define speed5 2004
#define speed6 2005

#define attack1 3000
#define attack2 3001
#define attack3 3002
#define attack4 3003
#define attack5 3004
#define attack6 3005

#define defence1 4000
#define defence2 4001
#define defence3 4002
#define defence4 4003
#define defence5 4004
#define defence6 4005

#define goBack 10000
#define goForward 20000

#define CARSPRITE 100000

cocos2d::Scene* CustomizeCarScene::createScene()
{
	/*
	*	Create a scene from the cocos2d library that will hold the
	*	Main Menu layer, displaying the buttons for moving across the
	*	game's menu system and getting to the game, as well as displays
	*	the title screen
	*/
	auto scene = cocos2d::Scene::create();
	auto layer = CustomizeCarScene::create();
	scene->addChild(layer);

	return scene;
}

bool CustomizeCarScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	current = 0;

	
	cars.push_back(new Car("Blocky.png"));
	cars.push_back(new Car("WhiteCar.png"));

	statline[0] = cars.at(current)->health;
	statline[1] = cars.at(current)->speed;
	statline[2] = cars.at(current)->attack;
	statline[3] = cars.at(current)->defence;

	GameManager* gm = GameManager::getInstance();
	cocos2d::Director* director = cocos2d::Director::getInstance();
	auto visibleSize = director->getVisibleSize();
	cocos2d::Vec2 origin = director->getVisibleOrigin();

	auto backArrow1 = cocos2d::Sprite::create("backArrow.png");
	backArrow1->setScale(gm->scaler);
	backArrow1->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + backArrow1->getContentSize().width / 4 + (3*visibleSize.width / 12),
			origin.y + backArrow1->getContentSize().height / 4 + (7*visibleSize.height / 8)
		)
	);
	this->addChild(backArrow1, 1);

	auto backArrow2 = cocos2d::Sprite::create("backArrow.png");
	backArrow2->setScale(gm->scaler);
	backArrow2->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + backArrow2->getContentSize().width / 2 + (3*visibleSize.width / 12),
			origin.y + backArrow2->getContentSize().height / 2 + (6*visibleSize.height / 8)
		)
	);
	this->addChild(backArrow2, 1, goBack);

	auto backArrow3 = cocos2d::Sprite::create("backArrow.png");
	backArrow3->setScale(gm->scaler);
	backArrow3->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + backArrow3->getContentSize().width / 2 + (3*visibleSize.width / 12),
			origin.y + backArrow3->getContentSize().height / 2 + (5*visibleSize.height / 8)
		)
	);
	this->addChild(backArrow3, 1);

	auto forwardArrow1 = cocos2d::Sprite::create("forwardArrow.png");
	forwardArrow1->setScale(gm->scaler);
	forwardArrow1->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + forwardArrow1->getContentSize().width / 2 + (9*visibleSize.width / 12),
			origin.y + forwardArrow1->getContentSize().height / 2 + (7*visibleSize.height / 8)// - 20
		)
	);
	this->addChild(forwardArrow1, 1);

	auto forwardArrow2 = cocos2d::Sprite::create("forwardArrow.png");
	forwardArrow2->setScale(gm->scaler);
	forwardArrow2->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + forwardArrow2->getContentSize().width / 2 + (9*visibleSize.width / 12),
			origin.y + forwardArrow2->getContentSize().height / 2 + (6*visibleSize.height / 8)
		)
	);
	this->addChild(forwardArrow2, 1, goForward);

	auto forwardArrow3 = cocos2d::Sprite::create("forwardArrow.png");
	forwardArrow3->setScale(gm->scaler);

	forwardArrow3->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + forwardArrow3->getContentSize().width / 2 + (9 * visibleSize.width / 12),
			origin.y + forwardArrow3->getContentSize().height / 2 + (5 * visibleSize.height / 8)
		)
	);
	this->addChild(forwardArrow3, 1);
	
	auto carSprite = cocos2d::Sprite::create("Blocky.png");
	carSprite->setScale(gm->scaler);
	
	carSprite->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (6 * visibleSize.width / 12) - carSprite->getContentSize().width / 2,
			origin.y + carSprite->getContentSize().height / 2 + (6 * visibleSize.height / 8)
		)
	);
	this->addChild(carSprite, 1, CARSPRITE);

	auto healthLabel = cocos2d::Label::createWithTTF("Health:", "fonts/arial.ttf", 16);
	healthLabel->setScale(gm->scaler);
	healthLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (3 * visibleSize.width / 12) - healthLabel->getContentSize().width / 2,
			origin.y + healthLabel->getContentSize().height / 2 + (4 * visibleSize.height / 8)
		)
	);
	this->addChild(healthLabel, 1);

	auto speedLabel = cocos2d::Label::createWithTTF("Speed:", "fonts/arial.ttf", 16);
	speedLabel->setScale(gm->scaler);
	speedLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (3 * visibleSize.width / 12) - speedLabel->getContentSize().width / 2,
			origin.y + speedLabel->getContentSize().height / 2 + (3 * visibleSize.height / 8)
		)
	);
	this->addChild(speedLabel, 1);

	auto attackLabel = cocos2d::Label::createWithTTF("Attack:", "fonts/arial.ttf", 16);
	attackLabel->setScale(gm->scaler);
	attackLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (3 * visibleSize.width / 12) - attackLabel->getContentSize().width / 2,
			origin.y + attackLabel->getContentSize().height / 2 + (2 * visibleSize.height / 8)
		)
	);
	this->addChild(attackLabel, 1);

	auto defenceLabel = cocos2d::Label::createWithTTF("Defence:", "fonts/arial.ttf", 16);
	defenceLabel->setScale(gm->scaler);
	CCLOG("hahaha");
	defenceLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (3 * visibleSize.width / 12) - defenceLabel->getContentSize().width / 2,
			origin.y + defenceLabel->getContentSize().height / 2 + (visibleSize.height / 8)
		)
	);
	this->addChild(defenceLabel, 1);

	addStats();

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

		if (target->getTag() == 10000)
		{
			if (current == 0)
			{
				current = cars.size() - 1;
			}
			else
			{
				current--;
			}

			changeCar();
		}
		else if (target->getTag() == 20000)
		{
			if (current == cars.size() - 1)
			{
				current = 0;
			}
			else
			{
				current++;
			}
				changeCar();
		}

		if (rect.containsPoint(locationInNode))
		{
			return true;
		}
		return false;

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, backArrow2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), forwardArrow2);

	auto playGameButton = cocos2d::MenuItemImage::create
	(
		"PlayGameButton.png", 
		"PlayGameButton.png",
		CC_CALLBACK_1(CustomizeCarScene::goToGame, this)
	);
	playGameButton->setScale(gm->scaler);
	playGameButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (11 * visibleSize.width / 12) - playGameButton->getContentSize().width / 2,
			origin.y + playGameButton->getContentSize().height / 2 + (visibleSize.height / 8)
		)
	);
	auto menu = cocos2d::Menu::create(playGameButton, NULL);
	menu->setPosition(cocos2d::Vec2::ZERO);
	this->addChild(menu, 1);


	return true;
}

void CustomizeCarScene::changeCar()
{
	cocos2d::Sprite* sprite = (cocos2d::Sprite*)getChildByTag(CARSPRITE);
	sprite->setTexture(cars.at(current)->filename);

	addStats();
}

void CustomizeCarScene::addStats()
{
	GameManager* gm = GameManager::getInstance();
	cocos2d::Director* director = cocos2d::Director::getInstance();
	auto visibleSize = director->getVisibleSize();
	cocos2d::Vec2 origin = director->getVisibleOrigin();

	for (int i = 0; i < statline[0]; i++)
	{
		if (getChildByTag(health1 + i) != NULL)
		{
			getChildByTag(health1 + i)->removeFromParentAndCleanup(true);
		}
	}
	for (int i = 0; i < statline[1]; i++)
	{
		if (getChildByTag(speed1 + i) != NULL)
		{
			getChildByTag(speed1 + i)->removeFromParentAndCleanup(true);
		}
	}
	for (int i = 0; i < statline[2]; i++)
	{
		if (getChildByTag(attack1 + i) != NULL)
		{
			getChildByTag(attack1 + i)->removeFromParentAndCleanup(true);
		}
	}
	for (int i = 0; i < statline[3]; i++)
	{
		if (getChildByTag(defence1 + i) != NULL)
		{
			getChildByTag(defence1 + i)->removeFromParentAndCleanup(true);
		}
	}

	statline[0] = cars.at(current)->health;
	statline[1] = cars.at(current)->speed;
	statline[2] = cars.at(current)->attack;
	statline[3] = cars.at(current)->defence;

	for (int i = 0; i < statline[0]; i++)
	{
		auto statSprite = cocos2d::Sprite::create("StatPoint.png");
		statSprite->setScale(gm->scaler);
		statSprite->setPosition
		(
			cocos2d::Vec2
			(
				origin.x + ((i + 5) * visibleSize.width / 12) - statSprite->getContentSize().width / 2,
				origin.y + statSprite->getContentSize().height / 2 + (4 * visibleSize.height / 8)
			)
		);
		this->addChild(statSprite, 1, health1 + i);
	}
	for (int i = 0; i < statline[1]; i++)
	{
		auto statSprite = cocos2d::Sprite::create("StatPoint.png");
		statSprite->setScale(gm->scaler);
		statSprite->setPosition
		(
			cocos2d::Vec2
			(
				origin.x + ((i + 5) * visibleSize.width / 12) - statSprite->getContentSize().width / 2,
				origin.y + statSprite->getContentSize().height / 2 + (3 * visibleSize.height / 8)
			)
		);
		this->addChild(statSprite, 1, speed1 + i);
	}
	for (int i = 0; i < statline[2]; i++)
	{
		auto statSprite = cocos2d::Sprite::create("StatPoint.png");
		statSprite->setScale(gm->scaler);
		statSprite->setPosition
		(
			cocos2d::Vec2
			(
				origin.x + ((i + 5) * visibleSize.width / 12) - statSprite->getContentSize().width / 2,
				origin.y + statSprite->getContentSize().height / 2 + (2 * visibleSize.height / 8)
			)
		);
		this->addChild(statSprite, 1, attack1 + i);
	}
	for (int i = 0; i < statline[3]; i++)
	{
		auto statSprite = cocos2d::Sprite::create("StatPoint.png");
		statSprite->setScale(gm->scaler);
		statSprite->setPosition
		(
			cocos2d::Vec2
			(
				origin.x + ((i + 5) * visibleSize.width / 12) - statSprite->getContentSize().width / 2,
				origin.y + statSprite->getContentSize().height / 2 + (visibleSize.height / 8)
			)
		);
		this->addChild(statSprite, 1, defence1 + i);
	}
	
}

void CustomizeCarScene::goToGame(cocos2d::Ref* pSender)
{
	auto StoryScene = Game::createScene();
	cocos2d::Director::getInstance()->pushScene(StoryScene);
}