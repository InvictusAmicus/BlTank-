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

	Car(std::string n);
	~Car();

};

#endif // !_CAR_H_
