#ifndef RENDER_ACTOR_H
#define RENDER_ACTOR_H

#include <SDL.h>
#include "CCG_constant.h"

//TODO:单例设计模式

class RenderAcotor
{
private:
	
	//自己不new，拿别人的。所以不用智能指针释放内存
	SDL_Window* window ;
	SDL_Renderer* renderer ;



public:
	
	RenderAcotor(SDL_Window* window, SDL_Renderer* renderer) :window(window), renderer(renderer) {};

	void renderScene(Scene scene)
	{


	}

};

#endif // !RENDER_ACTOR_H

