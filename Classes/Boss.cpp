#include "Boss.h"

Boss::Boss(std::string n)
{
	filename = n;
	if (filename == "GOD1Aura.png")
	{
		totalHealth = 1000;
		health = 1000;
		speed = 20;
		attack = 30;
		defence = 25;
	}
	else
	{
		totalHealth = 2500;
		health = 2500;
		speed = 30;
		attack = 50;
		defence = 35;
	}
}