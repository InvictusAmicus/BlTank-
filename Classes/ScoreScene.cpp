#include "ScoreScene.h"
#include "MainMenuScene.h"


const char* HIGHSCORE1 = "highscore1";
const char* HIGHSCORE2 = "highscore2";


cocos2d::Scene* ScoreScene::createScene()
{
	/*
	*	Create a scene from the cocos2d library that will hold the
	*	Main Menu layer, displaying the buttons for moving across the
	*	game's menu system and getting to the game, as well as displays
	*	the title screen
	*/
	auto scene = cocos2d::Scene::create();
	auto layer = ScoreScene::create();
	scene->addChild(layer);

	return scene;
}

bool ScoreScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	/*
	*	The cocos2d::Director functions as a scene manager, navigating
	*	the code through the scenes that make up the game. It also holds
	*	the renderer and other information on the various components that
	*	keep the game running.
	*/
	cocos2d::Director* director = cocos2d::Director::getInstance();

	auto visibleSize = director->getVisibleSize();
	cocos2d::Vec2 origin = director->getVisibleOrigin();

	GameManager* gm = GameManager::getInstance();

	int high_score1;
	int high_score2;


	if (def->getIntegerForKey(HIGHSCORE2) != NULL)
	{
		high_score1 = def->getIntegerForKey(HIGHSCORE1);
		high_score2 = def->getIntegerForKey(HIGHSCORE2);
	}
	else if (def->getIntegerForKey(HIGHSCORE1) != NULL)
	{
		high_score1 = def->getIntegerForKey(HIGHSCORE1);
		high_score2 = 0;
	}
	else
	{
		high_score1 = 0;
		high_score2 = 0;
	}

	if (gm->score > high_score1)
	{
		def->setIntegerForKey(HIGHSCORE2, high_score1);
		def->setIntegerForKey(HIGHSCORE1, gm->score);

	}
	else if (gm->score > high_score2)
	{
		def->setIntegerForKey(HIGHSCORE2, gm->score);
	}

	high_score1 = def->getIntegerForKey(HIGHSCORE1);
	high_score2 = def->getIntegerForKey(HIGHSCORE2);

	auto sprite = cocos2d::Sprite::create("Scoreboard.png");
	sprite->setScale(gm->scaler);
	sprite->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height / 2// - 20
		)
	);

	this->addChild(sprite, 1);

	char s[20];

	sprintf(s, "Your score:\t%d", gm->score);

	auto yourScore = cocos2d::Label::createWithTTF(s, "fonts/arial.ttf", 20);
	yourScore->setScale(gm->scaler);
	yourScore->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width/8 + yourScore->getContentSize().width * gm->scaler / 2,
			origin.y + (4.5 * visibleSize.height / 8)

		)
	);
	this->addChild(yourScore, 1);

	sprintf(s, "1st:\t%d", high_score1);
	auto label1 = cocos2d::Label::createWithTTF(s, "fonts/arial.ttf", 20);
	label1->setScale(gm->scaler);
	label1->setPosition
	(
		cocos2d::Vec2
		(
//			origin.x + visibleSize.width/8 + label1->getContentSize().width * gm->scaler / 2,
//			origin.y + (5 * visibleSize.height / 8)
			origin.x + visibleSize.width / 8 + label1->getContentSize().width * gm->scaler / 2,
			origin.y + (3 * visibleSize.height / 8)
		)
	);
	this->addChild(label1, 1);

	sprintf(s, "2nd:\t%d", high_score2);
	auto label2 = cocos2d::Label::createWithTTF(s, "fonts/arial.ttf", 20);
	label2->setScale(gm->scaler);
	label2->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + visibleSize.width / 8 + label2->getContentSize().width * gm->scaler /2,
			origin.y + (1.7 * visibleSize.height / 8)

		)
	);
	this->addChild(label2, 1);

	auto mainMenuButton = cocos2d::MenuItemImage::create
	(
		"MainMenuButton.png",
		"MainMenuButton.png",
		CC_CALLBACK_1(ScoreScene::goToCustomize, this)
	);

	/*
	Set the position of the button using a 2d Vector variable
	*/
	mainMenuButton->setScale(gm->scaler);
	mainMenuButton->setPosition
	(
		cocos2d::Vec2
		(
			origin.x + (10.25 * visibleSize.width / 12),
			origin.y + (1.75f * visibleSize.height / 8)
		)
	);

	auto menu = cocos2d::Menu::create(mainMenuButton, NULL);
	menu->setPosition(cocos2d::Vec2::ZERO);
	this->addChild(menu, 1);

	def->flush();

	return true;
	
}


void ScoreScene::goToCustomize(cocos2d::Ref* pSender)
{
	auto scene = MainMenuScene::createScene();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(2, scene));
}