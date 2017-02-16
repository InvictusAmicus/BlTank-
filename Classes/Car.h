#ifndef _CAR_H_
#define _CAR_H_

#include "cocos2d.h"

class Car
{
public:
	std::string filename;
	int health;
	int speed;
	int attack;
	int defence;
	int gameHealth;
	int gameSpeed;
	int gameAttack;
	int gameDefence;
	int currentHealth;
	int currentSpeed;
	int currentAttack;
	int currentDefence;

	Car(std::string n);
	~Car();

};

#endif // !_CAR_H_