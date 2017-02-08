#include "Game.h"

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

	GameManager* gm = GameManager::getInstance();
	cocos2d::Director* director = cocos2d::Director::getInstance();
	auto visibleSize = director->getVisibleSize();
	cocos2d::Vec2 origin = director->getVisibleOrigin();

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
	this->addChild(attackButton, 1);

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
	this->addChild(magicButton, 1);

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
	this->addChild(specialButton, 1);

	return true;

}