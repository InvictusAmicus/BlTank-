#ifndef _GAME_H_
#define _GAME_H_

#include "cocos2d.h"
#include "GameManager.h"

class Game :public cocos2d::Layer
{
private:
	int time;
	bool buttonPushed = false, moveButton = false;
	int buttonLayer = 0, buttonClicked = 0;
	cocos2d::Label* timerLabel;
	cocos2d::Director* director = cocos2d::Director::getInstance();
	cocos2d::Size visibleSize = director->getVisibleSize();
	cocos2d::Vec2 origin = director->getVisibleOrigin();

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Game);

	void update(float delta) override;

};

#endif