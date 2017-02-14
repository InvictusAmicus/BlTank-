#ifndef _WINGAMEDIALOGUE_SCENE_
#define _WINGAMEDIALOGUE_SCENE_

#include "cocos2d.h"
#include "GameManager.h"

class WinGameDialogueScene : public cocos2d::Layer
{
	public:
		static cocos2d::Scene* createScene();

		virtual bool init();

		void goToCustomize(cocos2d::Ref* pSender);

		CREATE_FUNC(WinGameDialogueScene);
};

#endif // !_WINGAMEDIALOGUE_SCENE_
