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

		magicSound = "Audio/Finished_Sounds/Magic/Ice_Attack.mp3";
		specialSound1 = "Audio/Finished_Sounds/Specials/Maelstrom.mp3";
		specialSound2 = "Audio/Finished_Sounds/Specials/Avalanche.mp3";

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

		healingAnim.reserve(8);
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Heal1.png", cocos2d::Rect(-30, -20, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P1Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

		special1Anim.reserve(3);
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P1Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P1Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P1Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));

		special2Anim.reserve(3);
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P1Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P1Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P1Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));

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

		magicSound = "Audio/Finished_Sounds/Magic/Fire_Attack.mp3";
		specialSound1 = "Audio/Finished_Sounds/Specials/Incinerate.mp3";
		specialSound2 = "Audio/Finished_Sounds/Specials/Blaze.mp3";

		idleAnim.reserve(1);
		idleAnim.pushBack(cocos2d::SpriteFrame::create("P2Idle.png", cocos2d::Rect(0, 0, 120, 80)));

		magicAnim.reserve(6);
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P2Mag01.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P2Mag02.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P2Mag03.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P2Mag02.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P2Mag01.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P2Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

		physicalAnim.reserve(6);
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys01.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys03.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Phys01.png", cocos2d::Rect(-30, -20, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P2Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

		healingAnim.reserve(8);
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Heal1.png", cocos2d::Rect(-30, -20, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P2Idle.png", cocos2d::Rect(-30, -20, 120, 80)));
		
		special1Anim.reserve(3);
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P2Spec1.png", cocos2d::Rect(0, 0, 120, 80)));
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P2Spec2.png", cocos2d::Rect(0, 0, 120, 80)));
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P2Spec3.png", cocos2d::Rect(0, 0, 120, 80)));

		special2Anim.reserve(3);
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P2Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P2Spec2_2.png", cocos2d::Rect(0, 0, 120, 80)));
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P2Spec2_3.png", cocos2d::Rect(0, 0, 120, 80)));

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

		magicSound = "Audio/Finished_Sounds/Magic/Thunder.mp3";
		specialSound1 = "Audio/Finished_Sounds/Specials/Obliterate.mp3";
		specialSound1 = "Audio/Finished_Sounds/Specials/Raikou.mp3";

		idleAnim.reserve(1);
		idleAnim.pushBack(cocos2d::SpriteFrame::create("P3Idle.png", cocos2d::Rect(0, 0, 120, 80)));

		magicAnim.reserve(6);
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P3Mag01.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P3Mag02.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P3Mag03.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P3Mag02.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P3Mag01.png", cocos2d::Rect(0, 0, 120, 80)));
		magicAnim.pushBack(cocos2d::SpriteFrame::create("P3Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

		physicalAnim.reserve(6);
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys01.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys01.png", cocos2d::Rect(-30, -20, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys02.png", cocos2d::Rect(0, 0, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Phys01.png", cocos2d::Rect(-30, -20, 120, 80)));
		physicalAnim.pushBack(cocos2d::SpriteFrame::create("P3Idle.png", cocos2d::Rect(-30, -20, 120, 80)));

		healingAnim.reserve(8);
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal1.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal2.png", cocos2d::Rect(0, 0, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Heal1.png", cocos2d::Rect(-30, -20, 120, 80)));
		healingAnim.pushBack(cocos2d::SpriteFrame::create("P3Idle.png", cocos2d::Rect(-30, -20, 120, 80)));
		
		special1Anim.reserve(3);
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P3Spec1.png", cocos2d::Rect(0, 0, 120, 80)));
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P3Spec2.png", cocos2d::Rect(0, 0, 120, 80)));
		special1Anim.pushBack(cocos2d::SpriteFrame::create("P3Spec3.png", cocos2d::Rect(0, 0, 120, 80)));
		
		special2Anim.reserve(3);
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P3Spec2_1.png", cocos2d::Rect(0, 0, 120, 80)));
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P3Spec2_2.png", cocos2d::Rect(0, 0, 120, 80)));
		special2Anim.pushBack(cocos2d::SpriteFrame::create("P3Spec2_3.png", cocos2d::Rect(0, 0, 120, 80)));
		
		
	}

}

Car::~Car()
{
	delete this;
}