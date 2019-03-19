#include "WINEventActor.h"

#include <iostream>

WINEventActor::WINEventActor()
{
}

void WINEventActor::eventDisposer(const SDL_Event& e, GameObject& ob)
{
	std::cout << typeid(ob).name() << std::endl;
}
