#ifndef RENDER_ACTOR_H
#define RENDER_ACTOR_H

#include <SDL.h>
#include <iostream>

#include "CCG_constant.h"

//TODO:�������ģʽ

class RenderAcotor
{
private:
	
	//�Լ���new���ñ��˵ġ����Բ�������ָ���ͷ��ڴ�
	SDL_Window* window ;
	SDL_Renderer* renderer ;

public:
	
	RenderAcotor(SDL_Window* window, SDL_Renderer* renderer) :window(window), renderer(renderer) 
	{
		//renderer = CCG_MAIN_RENDERER;
	};

	void renderScene(Scene* scene)
	{
		renderClearInBlack();

		if (scene->gameRound != NULL)
		{
			renderGameround(scene->gameRound.get());
		}
		//����һ������
		//for (auto val : scene->getItems())
		//{
		//	val->paintTexture();
		//	//std::cout << "name:" << val->getDes() << "\n";
		//	renderGameObject(val.get());
		//}

		update();

	}

	void renderClearWithColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		if (renderer == NULL)
		{
			printf("somthing is wrong\n");
		}
		SDL_SetRenderDrawColor(renderer, r, g, b, a);
		SDL_RenderClear(renderer);
	}

	void renderClearInBlack()
	{
		renderClearWithColor(0, 0, 0, 0);
	}

	void renderGameObject(GameObject* obj)
	{
		//SDL_RenderFillRect(renderer, obj->getRect());
		SDL_RenderCopy(renderer, obj->getTexture(), NULL, obj->getRect());
	}

	void update()
	{
		SDL_RenderPresent(renderer);
	}

	void renderGameround(Gameround* game)
	{
		//����̨�ó���
		Arena* a = game->arena.get();
		if (!a->AHandCards.empty())
		{
			int count = 0;
			for (auto val : a->AHandCards)
			{
				//std::cout << "name:" << val->getDes() << "\n";
				val->paintTexture();		
				val->getRect()->x = (val->getWidth() * count) ;
				renderGameObject(val.get());
			}
		}
		////������
		//std::vector<std::shared_ptr<Card>> AFightCards;
		//std::vector<std::shared_ptr<Card>> BFightCards;

		////������
		//std::vector<std::shared_ptr<Card>> AHandCards;
		//std::vector<std::shared_ptr<Card>> BHandCards;
	}

};

#endif // !RENDER_ACTOR_H

