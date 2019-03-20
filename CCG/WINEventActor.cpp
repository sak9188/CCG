#include "WINEventActor.h"

#include <iostream>

#include "scene.h"


WINEventActor::WINEventActor()
{
}

void WINEventActor::eventDisposer(const SDL_Event& e, Scene& ob)
{		
	switch ( e.type )
	{
	case (SDL_QUIT):
		CCG_QUIT = true;
		break;

	//鼠标事件
	case (SDL_MOUSEBUTTONDOWN):
	case (SDL_MOUSEBUTTONUP):
	case (SDL_MOUSEMOTION):
		mouseEventDisposer(e, ob);
		break;

	//键盘事件
	case (SDL_KEYDOWN):
		break;
	}
	//std::cout << typeid(e).name() << std::endl;
}

void WINEventActor::mouseEventDisposer(const SDL_Event& e, Scene& ob)
{
	switch (e.type)
	{
	case (SDL_MOUSEBUTTONDOWN):

		//return card card in 

		//先判断是否有在卡内，有则返回卡，没有则返回null
		for (auto val : ob.getItems())
		{
			std::cout << typeid(*val).name() << std::endl;
			//再判断是不是Card
			if (isCard(val))
			{
				//std::cout << "mother fucker i goted you31" << std::endl;
				Card* card = dynamic_cast<Card*>(val);
				if (card->isContacted(e.button.x, e.button.y))
				{
					followCard = card;
					//std::cout << "123" << std::endl;
				}
				
			}
			
		}
		//



		break;
	case (SDL_MOUSEBUTTONUP):
		if (followCard != NULL)
		{
			followCard = 0;
		}
		break;
	case (SDL_MOUSEMOTION):
		if (LMouseButtonMotion(e.motion.state))
		{
			if (followCard != NULL)
			{
				followCard->getRect()->x += e.motion.xrel;
				followCard->getRect()->y += e.motion.yrel;
			}

			//std::cout << "mother fucker i goted you1\n" << std::endl;
			//std::cout << typeid(ob).name() << std::endl;
			//
			//if (isEqualType(&ob, &creatureType))
			//{
			//	Creature& c = dynamic_cast<Creature&>(ob);
			//	std::cout << "mother fucker i goted you2\n" << std::endl;
			//	if (c.isContacted(e.motion.x, e.motion.y))
			//	{

			//		std::cout << "mother fucker i goted you3\n" << std::endl;
			//	}


			//}
			//
			////先判断
			//if(isEqualType(&ob, &sceneType))
			//{
			//
			//}
		}
		break;
	}
}

void WINEventActor::keyEventDisposer()
{
}

bool WINEventActor::LMouseButtonMotion(Uint32 states)
{
	return states & SDL_BUTTON_LMASK;
}

bool WINEventActor::isCard(GameObject * ob)
{
	if (isEqualType(*ob, creatureType))
	{
		return true;
	}
	return false;
}

