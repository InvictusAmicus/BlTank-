#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "cocos2d.h"

class GameManager
{
private:
	GameManager();
	~GameManager();

	
public:

	float scaler;
	static GameManager* getInstance();
	static void deleteInstance();
};

#endif // !_GAME_MANAGER_H_
