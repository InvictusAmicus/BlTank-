#include "Boss.h"

/*
*	This class stores the information on the bosses to make it easier to access it
*/
Boss::Boss(std::string n)
{
	filename = n;
	/*
	*	Info on Boss 1
	*/
	if (filename == "Level1.png")
	{
		health = 1000;
		speed = 20;
		attack = 30;
		defence = 25;
	}
	/*
	*	Info on Boss 2
	*/
	else
	{
		health = 2500;
		speed = 30;
		attack = 60;
		defence = 35;
	}
}
