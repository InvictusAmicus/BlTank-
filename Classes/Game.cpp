#include "Game.h"
#include <sstream>

#define attackButtonTag 1010
#define magicButtonTag 1011
#define specialButtonTag 1012



cocos2d::Scene* Game::createScene()
{
	/*
	*	Create a scene from the cocos2d library that will hold the
	*	Main Menu layer, displaying the buttons for moving across the
	*	game's menu system and getting to the game, as well as displays
	*	the title screen
	*/
	auto scene = cocos2d::Scene::create();
	auto layer = Game::create();
	scene->addChild(layer);

	return scene;
}

bool Game::init()
{
	if (!Layer::init())
	{
		return false;
	}

	time = 100;
	scheduleUpdate();
	GameManager* gm = GameManager::getInstance();
	Car* car = gm->car;

	auto attackButton = cocos2d::Sprite::create("Attack.png");
	attackButton->setScale(gm->scaler);
	attackButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + attackButton->getContentSize().width + (11 * visibleSize.width / 12) - attackButton->getContentSize().width,
			origin.y + attackButton->getContentSize().height / 4 + (6 * visibleSize.height / 8)
		)
	);
	this->addChild(attackButton, 1, attackButtonTag);

	auto magicButton = cocos2d::Sprite::create("Magic.png");
	magicButton->setScale(gm->scaler);
	magicButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + magicButton->getContentSize().width + (11 * visibleSize.width / 12) - magicButton->getContentSize().width,
			origin.y + magicButton->getContentSize().height / 4 + (4 * visibleSize.height / 8)
		)
	);
	this->addChild(magicButton, 1, magicButtonTag);

	auto specialButton = cocos2d::Sprite::create("Special.png");
	specialButton->setScale(gm->scaler);
	specialButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + specialButton->getContentSize().width + (11 * visibleSize.width / 12) - specialButton->getContentSize().width,
			origin.y + specialButton->getContentSize().height / 4 + (2 * visibleSize.height / 8)
		)
	);
	this->addChild(specialButton, 1, specialButtonTag);

	auto player = cocos2d::Sprite::create(gm->car->filename);
	player->setScale(gm->scaler);
	player->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (7 * visibleSize.width / 12),
			origin.y + (4 * visibleSize.height / 8)
		)
	);
	this->addChild(player, 1);

	std::string gh;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	gh = std::to_string(gm->car->gameHealth);

#else CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	std::ostringstream gh1;
	gh1 << gm->car->gameHealth;
	gh = gh1.str();
#endif
	auto playerHealth = cocos2d::Label::createWithTTF("Health: " + gh, "fonts/arial.ttf", 16);
	playerHealth->setScale(gm->scaler);
	playerHealth->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (8 * visibleSize.width / 12) - playerHealth->getContentSize().width / 2,
			origin.y + ( visibleSize.height / 8) - playerHealth->getContentSize().height / 2
		)
	);
	this->addChild(playerHealth, 1);

	auto enemy = cocos2d::Sprite::create("Level1.png");
	enemy->setScale(gm->scaler*2);
	enemy->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (3 * visibleSize.width / 12) - enemy->getContentSize().width / 2,
			origin.y + (4.5 * visibleSize.height / 8) - enemy->getContentSize().height / 2
		)
	);
	this->addChild(enemy, 1);
/*
	auto enemy = cocos2d::Sprite::create("Level2.png");
	enemy->setScale(gm->scaler * 2.75);
	enemy->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (2.5 * visibleSize.width / 12) - enemy->getContentSize().width / 2,
			origin.y + (4.5 * visibleSize.height / 8) - enemy->getContentSize().height / 2
		)
	);
	this->addChild(enemy, 1);
	player->setScale(1 / gm->scaler*2);
	*/
	std::string timeLeft;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	timeLeft = std::to_string(time);

#else CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	std::ostringstream timeLeft1;
	timeLeft1 << time;
	timeLeft = timeLeft1.str();
#endif
	timerLabel = cocos2d::Label::createWithTTF(timeLeft, "fonts/arial.ttf", 16);
	timerLabel->setScale(gm->scaler);
	timerLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (6 * visibleSize.width / 12) - enemy->getContentSize().width / 2,
			origin.y + (7.5 * visibleSize.height / 8)
		)
	);
	this->addChild(timerLabel, 1);

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
			if (target->getTag() == 1010)
			{
				buttonPushed = true;
				buttonClicked = 0;
				moveButton = true;
				CCLOG("ATTACK");
			}
			else if (target->getTag() == 1011)
			{
				buttonPushed = true;
				buttonClicked = 1;
				moveButton = true;
				CCLOG("Magic");
			}
			else if (target->getTag() == 1012)
			{
				buttonPushed = true;
				buttonClicked = 2;
				moveButton = true;
				CCLOG("Special");
			}
			return true;
		}
		return false;

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, attackButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), magicButton);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1->clone(), specialButton);


	return true;


}

void Game::update(float delta)
{
	cocos2d::Sprite* attack = (cocos2d::Sprite*)getChildByTag(attackButtonTag);
	cocos2d::Sprite* magic = (cocos2d::Sprite*)getChildByTag(magicButtonTag);
	cocos2d::Sprite* special = (cocos2d::Sprite*)getChildByTag(specialButtonTag);

	if (moveButton)
	{
		if (buttonPushed)
		{
			attack->setPositionX(attack->getPositionX() + 40 * delta);
			magic->setPositionX(magic->getPositionX() + 40 * delta);
			special->setPositionX(special->getPositionX() + 40 * delta);
			if (attack->getPositionX() > director->getVisibleSize().width + attack->getContentSize().width)
			{
				buttonPushed = false;
				if (buttonLayer == 0)
				{
					if (buttonClicked == 0)
					{
						attack->setTexture("Attack.png");
						magic->setTexture("Attack.png");
						special->setTexture("Back.png");
					}
					else if (buttonClicked == 1)
					{
						attack->setTexture("Magic.png");
						magic->setTexture("Magic.png");
						special->setTexture("Back.png");
					}
					else if (buttonClicked == 2)
					{
						attack->setTexture("Special.png");
						magic->setTexture("Special.png");
						special->setTexture("Back.png");
					}
				}
				else
				{
					if (buttonClicked == 0)
					{
						attack->setTexture("Attack.png");
						magic->setTexture("Attack.png");
						special->setTexture("Back.png");
					}
					else if (buttonClicked == 1)
					{
						attack->setTexture("Magic.png");
						magic->setTexture("Magic.png");
						special->setTexture("Back.png");
					}
					else if (buttonClicked == 2)
					{
						attack->setTexture("Attack.png");
						magic->setTexture("Magic.png");
						special->setTexture("Special.png");
					}
				}
			}
		}
		if (!buttonPushed && moveButton)
		{

			
			attack->setPositionX(attack->getPositionX() - 40 * delta);
			magic->setPositionX(magic->getPositionX() - 40 * delta);
			special->setPositionX(special->getPositionX() - 40 * delta);
			if (attack->getPositionX() < origin.x + attack->getContentSize().width + (11 * visibleSize.width / 12) - attack->getContentSize().width)
			{
				moveButton = false;
			}
		}
	}
/*
		if (attack->getPositionX() == director->getVisibleSize().width)
		{
			moveButton = false;
		}
		if (buttonLayer == 0)
		{
			if (buttonClicked == 0)
			{
				attack->setTexture("Attack.png");
				magic->setTexture("Magic.png");
				special->setTexture("Back.png");
			}
			else if (buttonClicked == 1)
			{
				attack->setTexture("Attack.png");
				magic->setTexture("Magic.png");
				special->setTexture("Back.png");
			}
			else if (buttonClicked == 2)
			{
				attack->setTexture("Attack.png");
				magic->setTexture("Magic.png");
				special->setTexture("Back.png");
			}
		}
		else
		{

		}
		if (!moveButton && attack->getPositionX() >= origin.x + attack->getContentSize().width + (11 * visibleSize.width / 12) - attack->getContentSize().width)
		{
			attack->setPositionX(attack->getPositionX() - 4 * delta);
			magic->setPositionX(magic->getPositionX() - 4 * delta);
			special->setPositionX(special->getPositionX() - 4 * delta);
		}
		*/
//	}
}