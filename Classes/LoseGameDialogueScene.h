#ifndef _ENDING_DIALOGUE_H_
#define _ENDING_DIALOGUE_H_

#include "cocos2d.h"
#include "GameManager.h"

class LoseGameDialogueScene : public cocos2d::Layer
{
	public:
		static cocos2d::Scene* createScene();

		virtual bool init();

		void goToCustomize(cocos2d::Ref* pSender);

		CREATE_FUNC(LoseGameDialogueScene);
	};

#endif // !_ENDINGDIALOGUE_SCENE_
