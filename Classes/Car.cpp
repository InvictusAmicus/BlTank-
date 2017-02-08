#include "Car.h"

Car::Car(std::string n)
{
	filename = n;
	if (filename == "Blocky.png")
	{
		health = 5;
		speed = 1;
		attack = 2;
		defence = 4;
	}
	else if (filename == "WhiteCar.png")
	{
		health = 4;
		speed = 3;
		attack = 3;
		defence = 2;
	}
}

Car::~Car()
{
	delete this;
}