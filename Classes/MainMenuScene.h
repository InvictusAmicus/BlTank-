#ifndef _MAINMENU_H_
#define _MAINMENU_H_

/*
*	includes the cocos2dx library for usage
*/
#include "cocos2d.h"
/*
*	The Main Menu class will handle the implementation of the main menu
*	screen. This refers to the title display and the following buttons to
*	navigate through:
*	"Play Game"
*	"Exit Game"
*/
class MainMenuScene : public cocos2d::Layer
{

public:
	static cocos2d::Scene* createScene();
	
	virtual bool init();

	void goToStory(cocos2d::Ref* pSender);
	void goToOptions(cocos2d::Ref* pSender);
	void goToExit(cocos2d::Ref* pSender);

	CREATE_FUNC(MainMenuScene);

	cocos2d::Label* label;
	float timer;
};

#endif