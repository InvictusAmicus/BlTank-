#ifndef _SCORE_H_
#define _SCORE_H_

#include "cocos2d.h"
#include "GameManager.h"

class ScoreScene : public cocos2d::Layer
{
public:
	cocos2d::UserDefault* def = cocos2d::UserDefault::getInstance();
	static cocos2d::Scene* createScene();

	virtual bool init();

	void goToCustomize(cocos2d::Ref* pSender);

	CREATE_FUNC(ScoreScene);
};

#endif

