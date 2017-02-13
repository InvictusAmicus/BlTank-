#ifndef _BOSS_H_
#define _BOSS_H_

#include "cocos2d.h"

class Boss
{

public:

	std::string filename;
	int health;
	int speed;
	int attack;
	int defence;

	Boss(std::string n);

};

#endif