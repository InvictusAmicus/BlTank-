#ifndef _GAME_H_
#define _GAME_H_

#include "cocos2d.h"
#include "GameManager.h"

class Game :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Game);
};

#endif