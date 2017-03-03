#ifndef _HOW_TO_PLAY_
#define _HOW_TO_PLAY_

#include "cocos2d.h"
#include "MainMenuScene.h"

class HowToPlay : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goToCustomize(cocos2d::Ref* pSender);

	CREATE_FUNC(HowToPlay);
};

#endif // !_HOW_TO_PLAY_
