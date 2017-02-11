#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "cocos2d.h"
#include "Car.h"

class GameManager
{
private:
	GameManager();
	~GameManager();

	
public:


	float scaler;
	static GameManager* getInstance();
	static void deleteInstance();
	Car* car;
};

#endif // !_GAME_MANAGER_H_
