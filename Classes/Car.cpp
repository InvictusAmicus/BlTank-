#include "Car.h"

Car::Car(std::string n)
{
	filename = n;
	if (filename == "P1Idle.png")
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

		idleAnim.reserve(1);
		idleAnim.pushBack(cocos2d::SpriteFrame::create("P1Idle.png", cocos2d::Rect(0, 0, 120, 80)));

		magicAnim.reserve(10);
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag01.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag02.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag03.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag04.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag03.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag02.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Mag01.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P1Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

		physicalAnim.reserve(8);
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys01.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys03.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys04.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys03.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Phys01.png", cocos2d::Rect(-30, -20, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P1Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

	}
	else if (filename == "P2Idle.png")
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

		physicalAnim.reserve(6);
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys01.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys03.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys01.png", cocos2d::Rect(-30, -20, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

	}
	else if (filename == "P3Idle.png")
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

		physicalAnim.reserve(6);
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys01.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys03.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys01.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

	}

}

Car::~Car()
{
	delete this;
}