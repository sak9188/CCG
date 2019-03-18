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
	
	RenderAcotor(SDL_Window* window, SDL_Renderer* renderer) :window(window), renderer(renderer) 
	{
	};

	void renderScene(Scene* scene)
	{
		renderClearInBlack();

		//遍历一个容器
		for (auto val : scene->getItems())
		{
			printf("name:%s\n", val->getDes());
			renderGameObject(val);
		}

		update();

	}

	void renderClearWithColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderClear(renderer);
	}

	void renderClearInBlack()
	{
		renderClearWithColor(0, 0, 0, 0);
	}

	void renderGameObject(GameObject* obj)
	{
		SDL_RenderFillRect(renderer, obj->getRect());
		SDL_RenderCopy(renderer, obj->getTexture(), NULL, obj->getRect());
	}

	void update()
	{
		SDL_RenderPresent(renderer);
	}

};

#endif // !RENDER_ACTOR_H

