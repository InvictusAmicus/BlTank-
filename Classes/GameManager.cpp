#include "GameManager.h"

static GameManager* gm;
/*
*	A singleton class used to transport game
*	objects needed in multiple classes
*/
GameManager::GameManager()
{
	scaler = cocos2d::Director::getInstance()->getVisibleSize().width / 480;

}

GameManager::~GameManager()
{

}

void GameManager::deleteInstance()
{
	if (gm)
	{
		delete gm;
	}
}

GameManager* GameManager::getInstance()
{
	if (!gm)
	{
		gm = new GameManager();
	}

	return gm;
}

void GameManager::addBosses()
{
	levels.clear();

	levels.push_back(new Boss("Level1.png"));
	levels.push_back(new Boss("Level2.png"));


}
