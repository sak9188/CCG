#ifndef RENDER_ACTOR_H
#define RENDER_ACTOR_H

#include <SDL.h>
#include "CCG_constant.h"

//TODO:�������ģʽ

class RenderAcotor
{
private:
	
	//�Լ���new���ñ��˵ġ����Բ�������ָ���ͷ��ڴ�
	SDL_Window* window ;
	SDL_Renderer* renderer ;



public:
	
	RenderAcotor(SDL_Window* window, SDL_Renderer* renderer) :window(window), renderer(renderer) {};

	void renderScene(Scene scene)
	{


	}

};

#endif // !RENDER_ACTOR_H

