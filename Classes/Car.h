#ifndef _CAR_H_
#define _CAR_H_

#include "cocos2d.h"

class Car
{
public:
	std::string filename;
	int health;
	int speed;
	int attack;
	int defence;
	int gameHealth;
	int gameSpeed;
	int gameAttack;
	int gameDefence;
	int currentHealth;
	int currentSpeed;
	int currentAttack;
	int currentDefence;

	std::string magic;
	std::string special1;
	std::string special2;

	std::string midStoryScene;
	std::string endStoryScene;

	
	cocos2d::Vector<cocos2d::SpriteFrame*> idleAnim;
	cocos2d::Vector<cocos2d::SpriteFrame*> magicAnim;
	cocos2d::Vector<cocos2d::SpriteFrame*> physicalAnim;
	cocos2d::Vector<cocos2d::SpriteFrame*> special1Anim;
	cocos2d::Vector<cocos2d::SpriteFrame*> special2Anim;
	cocos2d::Vector<cocos2d::SpriteFrame*> healingAnim;
	
	Car(std::string n);
	~Car();

};

#endif // !_CAR_H_
