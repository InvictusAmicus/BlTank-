#include "Boss.h"

Boss::Boss(std::string n)
{
	filename = n;
	if (filename == "Level1.png")
	{
		health = 1000;
		speed = 20;
		attack = 30;
		defence = 25;
	}
	else
	{
		health = 2500;
		speed = 30;
		attack = 60;
		defence = 35;
	}
}