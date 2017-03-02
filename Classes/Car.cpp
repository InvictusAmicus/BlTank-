#include "Car.h"

Car::Car(std::string n)
{
	filename = n;
	if (filename == "Finished_Images/Player_1_120x80.png")
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

		magic = "Ice.png";
		special1 = "P1Special1.png";
		special2 = "P1Special2.png";
		midStoryScene = "MidGameImage2.png";
		endStoryScene = "BlizzEnding.png";


	}
	else if (filename == "Finished_Images/Player_2_120x80.png")
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

		magic = "Fire.png";
		special1 = "P2Special1.png";
		special2 = "P2Special2.png";
		midStoryScene = "MidGameImage2.png";
		endStoryScene = "FireEnding.png";
	}
	else if (filename == "Finished_Images/Player_3_120x80.png")
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

		magic = "Thunder.png";
		special1 = "P3Special1.png";
		special2 = "P3Special2.png";
		midStoryScene = "MidGameImage3.png";
		endStoryScene = "ThEnding.png";
	}

}

Car::~Car()
{
	delete this;
}