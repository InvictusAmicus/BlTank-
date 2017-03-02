#include "NewGame.h"
#include "WinGameDialogueScene.h"
#include "LoseGameDialogueScene.h"
#include "SimpleAudioEngine.h"
#include <sstream>
#include <ctime>

#define attackButtonTag 1010
#define magicButtonTag 1011
#define specialButtonTag 1012

#define BOSSHEALTH 11111



cocos2d::Scene* NewGame::createScene()
{
	/*
	*	Create a scene from the cocos2d library that will hold the
	*	Main Menu layer, displaying the buttons for moving across the
	*	game's menu system and getting to the game, as well as displays
	*	the title screen
	*/
	auto scene = cocos2d::Scene::create();
	auto layer = NewGame::create();
	scene->addChild(layer);

	return scene;
}

bool NewGame::init()
{
	if (!Layer::init())
	{
		return false;
	}
	srand(std::time(NULL));

	CocosDenshion::SimpleAudioEngine* audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->stopBackgroundMusic(true);
	audio->playBackgroundMusic("Audio/Mabye-Boss-Battle.mp3", true);

	time = 150;
	level = 0;
	scheduleUpdate();
	gm = GameManager::getInstance();
	gm->addFinalBoss();
	Car* car = gm->car;
	//	Boss* boy = gm->levels.at(0);

	auto background = cocos2d::Sprite::create("Finished_Images/BattleBackground2.png");
	background->setScale(gm->scaler);
	background->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width / 2,// - (background->getContentSize().width / 2),
			origin.y + visibleSize.height / 2// - background->getContentSize().height / 2
		)
	);
	this->addChild(background, 1);

	auto attackButton = cocos2d::Sprite::create("Attack.png");
	attackButton->setScale(gm->scaler);
	attackButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width - (attackButton->getContentSize().width / 2 * gm->scaler),
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
			origin.x + visibleSize.width - (magicButton->getContentSize().width / 2 * gm->scaler),
			origin.y + magicButton->getContentSize().height / 4 + (4 * visibleSize.height / 8)
		)
	);
	this->addChild(magicButton, 1, magicButtonTag);
	CCLOG("%f, %f", visibleSize.width, gm->scaler);

	auto specialButton = cocos2d::Sprite::create("Special.png");
	specialButton->setScale(gm->scaler);
	specialButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width - ((specialButton->getContentSize().width / 2)*gm->scaler),
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
			origin.x + (8 * visibleSize.width / 12),
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
	healthLabel = cocos2d::Label::createWithTTF("Player Health: " + gh, "fonts/arial.ttf", 12);
	healthLabel->setScale(gm->scaler);
	healthLabel->setColor(cocos2d::Color3B::GREEN);
	healthLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (9 * visibleSize.width / 12) - healthLabel->getContentSize().width / 2,
			origin.y + (visibleSize.height / 8) - healthLabel->getContentSize().height / 2
		)
	);
	this->addChild(healthLabel, 1);

	bossSprite = cocos2d::Sprite::create(gm->levels.at(0)->filename);
	bossSprite->setScale(gm->scaler);
	bossSprite->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (3 * visibleSize.width / 12) - bossSprite->getContentSize().width / 2,
			//origin.y + (4.5 * visibleSize.height / 8) - bossSprite->getContentSize().height / 2
			origin.y + (4 * visibleSize.height / 8)
		)
	);
	this->addChild(bossSprite, 1);

	auto bossLabel = cocos2d::Label::createWithTTF("Boss Health: ", "fonts/arial.ttf", 12);
	bossLabel->setScale(gm->scaler);
	bossLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + 0.05*visibleSize.width + bossLabel->getContentSize().width * gm->scaler / 2,
			origin.y + (1.75 * visibleSize.height / 8) - bossLabel->getContentSize().height / 2
		)
	);
	this->addChild(bossLabel, 1);

	auto emptyHealth = cocos2d::Sprite::create("HealthNone.png");
	emptyHealth->setScale(gm->scaler);
	emptyHealth->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + emptyHealth->getContentSize().width * gm->scaler / 2,
			origin.y + (visibleSize.height / 8) - emptyHealth->getContentSize().height / 2
		)
	);
	this->addChild(emptyHealth, 1);

	auto bossHealth = cocos2d::Sprite::create("Health2.png");
	bossHealth->setScale(gm->scaler);
	bossHealth->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + bossHealth->getContentSize().width * gm->scaler / 2,
			origin.y + (visibleSize.height / 8) - bossHealth->getContentSize().height / 2
		)
	);
	this->addChild(bossHealth, 1, BOSSHEALTH);
	startPosOfBossHealth = bossHealth->getContentSize().width * gm->scaler;

	auto clock = cocos2d::Sprite::create("Clock.png");//, "fonts/Clock.ttf", 16);
	clock->setScale(gm->scaler);
	clock->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (6 * visibleSize.width / 12),
			origin.y + (7.5 * visibleSize.height / 8)
		)
	);
	this->addChild(clock, 1);


	std::string timeLeft;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	timeLeft = std::to_string(time);

#else CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	std::ostringstream timeLeft1;
	timeLeft1 << time;
	timeLeft = timeLeft1.str();
#endif
	timerLabel = cocos2d::Label::createWithTTF(timeLeft, "fonts/Clock.ttf", 16);
	timerLabel->setColor(cocos2d::Color3B::BLACK);
	timerLabel->setScale(gm->scaler);
	timerLabel->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (6 * visibleSize.width / 12),
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
			}
			else if (target->getTag() == 1011)
			{
				buttonPushed = true;
				buttonClicked = 1;
				moveButton = true;
			}
			else if (target->getTag() == 1012)
			{
				buttonPushed = true;
				buttonClicked = 2;
				moveButton = true;
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

void NewGame::changeHealth(int d)
{
	if (d <= 0)
	{
		changeTimer(200 / gm->car->currentSpeed);
	}
	gm->car->currentHealth -= d;

	if (gm->car->currentHealth >= gm->car->gameHealth)
	{
		gm->car->currentHealth = gm->car->gameHealth;
	}
	std::string healthLeft;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	healthLeft = std::to_string(gm->car->currentHealth);

#else CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	std::ostringstream healthLeft1;
	healthLeft1 << gm->car->currentHealth;
	healthLeft = healthLeft1.str();
#endif

	healthLabel->setString("Health: " + healthLeft);
	if (gm->car->currentHealth <= 0)
	{
		//fade out to bad end // lost all health
		auto StoryScene = LoseGameDialogueScene::createScene();
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionRotoZoom::create(2, StoryScene));
	}
}

void NewGame::changeTimer(int d)
{

	time -= d;
	std::string timeLeft;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	timeLeft = std::to_string(time);

#else CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	std::ostringstream timeLeft1;
	timeLeft1 << time;
	timeLeft = timeLeft1.str();
#endif

	timerLabel->setString(timeLeft);

	if (time <= 0)
	{
		auto StoryScene = LoseGameDialogueScene::createScene();
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionRotoZoom::create(2, StoryScene));
	}
}

void NewGame::update(float delta)
{
	cocos2d::Sprite* attack = (cocos2d::Sprite*)getChildByTag(attackButtonTag);
	cocos2d::Sprite* magic = (cocos2d::Sprite*)getChildByTag(magicButtonTag);
	cocos2d::Sprite* special = (cocos2d::Sprite*)getChildByTag(specialButtonTag);

	if (moveButton)
	{
		if (buttonPushed)
		{
			attack->setPositionX(attack->getPositionX() + 100 * delta);
			magic->setPositionX(magic->getPositionX() + 100 * delta);
			special->setPositionX(special->getPositionX() + 100 * delta);
			if (attack->getPositionX() > director->getVisibleSize().width + (gm->scaler * attack->getContentSize().width) / 2)
			{
				buttonPushed = false;
				if (buttonLayer == 0)
				{
					if (buttonClicked == 0)
					{
						attack->setTexture("Slash.png");
						magic->setTexture("Strike.png");
						special->setTexture("Back.png");
						attMagSpe = 0;
						buttonLayer++;
					}
					else if (buttonClicked == 1)
					{
						attack->setTexture(gm->car->magic);
						magic->setTexture("Cure.png");
						special->setTexture("Back.png");
						attMagSpe = 1;
						buttonLayer++;
					}
					else if (buttonClicked == 2)
					{
						attack->setTexture(gm->car->special1);
						magic->setTexture(gm->car->special2);
						special->setTexture("Back.png");
						attMagSpe = 2;
						buttonLayer++;
					}
				}
				else
				{
					if (buttonClicked == 0)
					{
						attack->setTexture("Attack.png");
						magic->setTexture("Magic.png");
						special->setTexture("Special.png");
						if (attMagSpe == 0) // first attack
						{

							damageBoss(calculateDamage(1));
						}
						else if (attMagSpe == 1)//elemental attack
						{
							damageBoss(calculateDamage(2));
						}
						else // special 1
						{
							damageBoss(calculateDamage(3));
						}
						buttonLayer--;
					}
					else if (buttonClicked == 1)
					{
						attack->setTexture("Attack.png");
						magic->setTexture("Magic.png");
						special->setTexture("Special.png");
						if (attMagSpe == 0) // second attack
						{
							damageBoss(calculateDamage(4));
						}
						else if (attMagSpe == 1)//heal
						{
							changeHealth(-gm->car->gameHealth);
						}
						else // special 2
						{
							damageBoss(calculateDamage(6));
						}
						buttonLayer--;
					}
					else if (buttonClicked == 2)
					{
						attack->setTexture("Attack.png");
						magic->setTexture("Magic.png");
						special->setTexture("Special.png");
						buttonLayer--;

					}
				}
			}
		}
		if (!buttonPushed && moveButton)
		{
			attack->setPositionX(attack->getPositionX() - 100 * delta);
			magic->setPositionX(magic->getPositionX() - 100 * delta);
			special->setPositionX(special->getPositionX() - 100 * delta);
			if (attack->getPositionX() < origin.x + visibleSize.width - (attack->getContentSize().width / 2 * gm->scaler))
			{
				moveButton = false;
			}
		}
	}

	float percentageMoved = 100 - (100 * ((getChildByTag(BOSSHEALTH)->getPositionX() + startPosOfBossHealth / 2) / startPosOfBossHealth));

	CCLOG("percent damage:\t%f\npercent moved:\t%f", percentDamageToBoss, percentageMoved);

	if (percentDamageToBoss > percentageMoved)
	{
		getChildByTag(BOSSHEALTH)->setPositionX
		(
			getChildByTag(BOSSHEALTH)->getPositionX() - 100 * delta
		);
	}

	if (transform)
	{
		getChildByTag(BOSSHEALTH)->setOpacity(bossSprite->getOpacity() - 128 * delta);
		bossSprite->setOpacity(bossSprite->getOpacity() - 128 * delta);

		if (bossSprite->getOpacity() < 2)
		{
			transform = false;
		}
		if (!transform)
		{
			bossSprite->setTexture(gm->levels.at(level)->filename);
			percentDamageToBoss = 0;
			getChildByTag(BOSSHEALTH)->setPosition
			(
				cocos2d::Vec2
				(
					origin.x + getChildByTag(BOSSHEALTH)->getContentSize().width * gm->scaler / 2,
					origin.y + (visibleSize.height / 8) - getChildByTag(BOSSHEALTH)->getContentSize().height / 2
				)
			);
			transformBack = true;
		}
	}
	if (transformBack)
	{
		getChildByTag(BOSSHEALTH)->setOpacity(bossSprite->getOpacity() + 128 * delta);
		bossSprite->setOpacity(bossSprite->getOpacity() + 128 * delta);
		if (bossSprite->getOpacity() > 253)
		{
			transformBack = false;
			bossSprite->setOpacity(255);
		}
	}
}

void NewGame::damageBoss(int damage)
{
	gm->levels.at(level)->health -= damage;
	percentDamageToBoss += 100 * damage / gm->levels.at(level)->totalHealth;
	if (gm->levels.at(level)->health <= 0)
	{
		calculateScore();
		bool ready = false;
		if (level == 0)
		{
			transform = true;

			auto StoryScene = WinGameDialogueScene::createScene();
			cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionRotoZoom::create(2, StoryScene));
		}
		else if (level == 1)
		{
		}
	}
	else
	{
		int returnDamage = bossAI();
		changeHealth(returnDamage);
	}
}

int NewGame::calculateDamage(int attack)
{
	Boss* b = gm->levels.at(level);
	Car* c = gm->car;
	int damage = 0;
	if (attack == 1)
	{
		damage = 300 - (5 * b->defence) + c->currentAttack;
		changeTimer(10 - c->currentSpeed / 10);
	}
	else if (attack == 2)
	{
		damage = (500 + c->currentAttack) - (3 * b->defence);
		changeTimer(20 - 2 * (c->currentSpeed / 10));
	}
	else if (attack == 3)
	{
		damage = (1000 + c->currentAttack * 3) - (b->defence * 10);
		changeTimer(250 / c->currentSpeed);
	}
	else if (attack == 4)
	{
		damage = 300 - (5 * b->defence) + c->currentAttack;
		changeTimer(10 - (7 - c->currentSpeed / 10));
	}
	else if (attack == 6)
	{
		damage = (300 + c->currentAttack) - (3 * b->defence);

		c->currentAttack += 10;
		if (c->currentSpeed < 100)
		{
			c->currentSpeed += 10;
		}
		changeTimer(35 - 3 * (c->currentSpeed / 10));
	}
	if (damage < 0)
	{
		damage *= -1;
	}
	return damage;
}

int NewGame::bossAI()
{
	Boss* b = gm->levels.at(level);
	Car* c = gm->car;

	int returnDamage;
	int randomNoise;
	int random = rand() % 100;
	if (1 - (b->health / b->totalHealth) > .3)
	{
		randomNoise = 10 - rand() % 70;

		if (random > 95)
		{
			//special attack
			returnDamage = (b->attack * 4) - c->currentDefence / 2;
		}
		else if (random > 70)
		{
			//headbutt
			returnDamage = (b->attack * 3) - c->currentDefence;
		}
		else
		{
			//claw
			returnDamage = (b->attack * 2) - c->currentDefence;
		}
	}
	else if (1 - (b->health / b->totalHealth) > .6)
	{
		randomNoise = 10 - rand() % 60;

		if (random > 85)
		{
			//special attack
			returnDamage = (b->attack * 4) - c->currentDefence / 2;
		}
		else if (random > 55)
		{
			//headbutt
			returnDamage = (b->attack * 3) - c->currentDefence;
		}
		else
		{
			//claw
			returnDamage = (b->attack * 2) - c->currentDefence;
		}
	}
	else if (1 - (b->health / b->totalHealth) > .8)
	{
		randomNoise = 10 - rand() % 50;

		if (random > 60)
		{
			//special attack
			returnDamage = (b->attack * 4) - c->currentDefence / 2;

		}
		else if (random > 30)
		{
			//headbutt
			returnDamage = (b->attack * 3) - c->currentDefence;
		}
		else
		{
			//claw
			returnDamage = (b->attack * 2) - c->currentDefence;
		}
	}
	else
	{
		randomNoise = 10 - rand() % 30;

		if (random > 40)
		{
			//special attack
			returnDamage = (b->attack * 4) - c->currentDefence / 2;
		}
		else if (random > 15)
		{
			//headbutt
			returnDamage = (b->attack * 3) - c->currentDefence;
		}
		else
		{
			//claw
			returnDamage = (b->attack * 2) - c->currentDefence;
		}
	}
	returnDamage += randomNoise;
	if (returnDamage < 0)
	{
		returnDamage *= -1;
	}

	return returnDamage;
}

void NewGame::calculateScore()
{
	if (time <= 0)
	{
		time = 1;
	}
	gm->score += gm->car->currentHealth * time;
}
