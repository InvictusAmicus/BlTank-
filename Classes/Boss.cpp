#include "Boss.h"

Boss::Boss(std::string n)
{
	filename = n;
	if (filename == "GOD1Aura.png")
	{
		hurtFilename = "God1Hurt.png";
		totalHealth = 1000;
		health = 1000;
		speed = 20;
		attack = 30;
		defence = 25;
	}
	else if(filename == "GOD2Aura.png")
	{
		hurtFilename = "God2Hurt.png";
		totalHealth = 2500;
		health = 2500;
		speed = 30;
		attack = 50;
		defence = 35;
	}
	else
	{
		hurtFilename = "God2Hurt.png";
		totalHealth = 3000;
		health = 3000;
		speed = 50;
		attack = 50;
		defence = 25;
	}
}