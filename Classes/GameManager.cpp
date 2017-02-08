#include "GameManager.h"

static GameManager* gm;

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