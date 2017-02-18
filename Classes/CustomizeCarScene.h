#ifndef _CUSTOMIZE_CAR_SCENE_H_
#define _CUSTOMIZE_CAR_SCENE_H_

#include "cocos2d.h"
#include "Car.h"


/*
*	The customize car scene lets the player
*	pick the vehicle they wish to do battle
*	with
*/
class CustomizeCarScene : public cocos2d::Layer
{
public:
	
	std::vector<Car*> cars;
	int statline[4];
	int current;

	static cocos2d::Scene* createScene();
	virtual bool init();
	void goToGame(cocos2d::Ref* pSender);
	void goBackMenu(cocos2d::Ref* pSender);
	void goForwardMenu(cocos2d::Ref* pSender);


	void changeCar();
	void addStats();



	CREATE_FUNC(CustomizeCarScene);
};

#endif
