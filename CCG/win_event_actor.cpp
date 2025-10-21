#include "win_event_actor.h"

#include <iostream>

#include "scene.h"


win_event_actor::win_event_actor()
{
}

void win_event_actor::eventDisposer(const SDL_Event& e, scene& ob)
{		
	switch ( e.type )
	{
	case (SDL_QUIT):
		CCG_QUIT = true;
		break;

	//¼
	case (SDL_MOUSEBUTTONDOWN):
	case (SDL_MOUSEBUTTONUP):
	case (SDL_MOUSEMOTION):
		mouseEventDisposer(e, ob);
		break;

	//¼
	case (SDL_KEYDOWN):
		break;
	}
	//std::cout << typeid(e).name() << std::endl;
}

void win_event_actor::mouseEventDisposer(const SDL_Event& e, scene& ob)
{
	switch (e.type)
	{
	case (SDL_MOUSEBUTTONDOWN):

		//жǷڿڣ򷵻ؿû򷵻null
		for (auto val : ob.getItems())
		{
			std::cout << typeid(*val).name() << std::endl;
			//жǲCard
			if (isCard(val.get()))
			{
				//std::cout << "mother fucker i goted you31" << std::endl;
				::card* card_local = dynamic_cast<::card*>(val.get());
				if (card_local->isContacted(e.button.x, e.button.y))
				{
					followCard = card_local;
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
			//	creature& c = dynamic_cast<creature&>(ob);
			//	std::cout << "mother fucker i goted you2\n" << std::endl;
			//	if (c.isContacted(e.motion.x, e.motion.y))
			//	{

			//		std::cout << "mother fucker i goted you3\n" << std::endl;
			//	}


			//}
			//
			////ж
			//if(isEqualType(&ob, &sceneType))
			//{
			//
			//}
		}
		break;
	}
}

void win_event_actor::keyEventDisposer()
{
}

bool win_event_actor::LMouseButtonMotion(Uint32 states)
{
	return states & SDL_BUTTON_LMASK;
}

bool win_event_actor::isCard(game_object * ob)
{
	if (isEqualType(*ob, creatureType))
	{
		return true;
	}
	return false;
}

