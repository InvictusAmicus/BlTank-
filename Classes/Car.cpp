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
		gameHealth = health * 100;
		gameSpeed = speed * 10;
		gameAttack = attack * 10;
		gameDefence = defence * 10;
		currentHealth = gameHealth;
		currentSpeed = gameSpeed;
		currentAttack = gameAttack;
		currentDefence = gameDefence;

	}
	else if (filename == "WhiteCar.png")
	{
		health = 4;
		speed = 3;
		attack = 3;
		defence = 2;
		gameHealth = health * 100;
		gameSpeed = speed * 10;
		gameAttack = attack * 10;
		gameDefence = defence * 10;
		currentHealth = gameHealth;
		currentSpeed = gameSpeed;
		currentAttack = gameAttack;
		currentDefence = gameDefence;
	}
	else if (filename == "YellowCar.png")
	{
		health = 3;
		speed = 2;
		attack = 5;
		defence = 2;
		gameHealth = health * 100;
		gameSpeed = speed * 10;
		gameAttack = attack * 10;
		gameDefence = defence * 10;
		currentHealth = gameHealth;
		currentSpeed = gameSpeed;
		currentAttack = gameAttack;
		currentDefence = gameDefence;

	}

}

Car::~Car()
{
	delete this;
}