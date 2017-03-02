#include "GameManager.h"

static GameManager* gm;

GameManager::GameManager()
{
	scaler =  2* (cocos2d::Director::getInstance()->getVisibleSize().width / 480);
	score = 0;
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

	levels.push_back(new Boss("GOD1Aura.png"));
	levels.push_back(new Boss("GOD2Aura.png"));
}

void GameManager::addFinalBoss()
{
	levels.clear();
	levels.push_back(new Boss("FinalBoss.png"));
}