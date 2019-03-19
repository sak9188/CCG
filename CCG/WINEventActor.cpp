#include "WINEventActor.h"

#include <iostream>

void WINEventActor::mouseEventDisposer()
{
}

WINEventActor::WINEventActor()
{
}

void WINEventActor::eventDisposer(const SDL_Event& e, GameObject& ob)
{		
	switch ( e.type )
	{
	case (SDL_QUIT):
		CCG_QUIT = true;
		break;

	//鼠标事件
	case (SDL_MOUSEBUTTONDOWN):
		break;
	case (SDL_MOUSEBUTTONUP):
		break;
	case (SDL_MOUSEMOTION):
		break;

	//键盘事件
	case (SDL_KEYDOWN):
		break;
	}
	std::cout << typeid(e).name() << std::endl;
}
