#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "cocos2d.h"
#include "Car.h"
#include "Boss.h"

class GameManager
{
private:
	GameManager();
	~GameManager();

	
public:

	void addBosses();
	float scaler;
	static GameManager* getInstance();
	static void deleteInstance();
	Car* car;
	std::vector<Boss*> levels;
};

#endif // !_GAME_MANAGER_H_
