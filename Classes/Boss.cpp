#include "Boss.h"

Boss::Boss(std::string n)
{
	filename = n;
			totalHealth = 100;
			health = 100;
	if (filename == "GOD1Aura.png")
	{
//		totalHealth = 1000;
//		health = 1000;
		speed = 20;
		attack = 30;
		defence = 25;
	}
	else if(filename == "GOD2Aura.png")
	{
//		totalHealth = 2500;
//		health = 2500;
		speed = 30;
		attack = 50;
		defence = 35;
	}
	else
	{
//		totalHealth = 3000;
//		health = 3000;
		speed = 50;
		attack = 50;
		defence = 25;
	}
}