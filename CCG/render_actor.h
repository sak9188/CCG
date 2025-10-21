#ifndef RENDER_ACTOR_H
#define RENDER_ACTOR_H

#include <SDL.h>
#include <iostream>

#include "ccg_constant.h"

//TODO:ģʽ

class render_acotor
{
private:
    
    //Լnewñ˵ġԲָͷڴ
    SDL_Window* window ;
    SDL_Renderer* renderer ;

public:
    
    render_acotor(SDL_Window* window, SDL_Renderer* renderer) :window(window), renderer(renderer) 
    {
        //renderer = CCG_MAIN_RENDERER;
    };

    void renderScene(scene* scene)
    {
        renderClearInBlack();

        if (scene->gameRound != NULL)
        {
            renderGameround(scene->gameRound.get());
        }
        //һ
        //for (auto val : scene->getItems())
        //{
        //    val->paintTexture();
        //    //std::cout << "name:" << val->getDes() << "\n";
        //    renderGameObject(val.get());
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

    void renderGameObject(game_object* obj)
    {
        //SDL_RenderFillRect(renderer, obj->getRect());
        SDL_RenderCopy(renderer, obj->getTexture(), NULL, obj->getRect());
    }

    void update()
    {
        SDL_RenderPresent(renderer);
    }

    void renderGameround(gameround* game)
    {
        //̨ó
        arena* a = game->arena_inst.get();
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
        ////
        //std::vector<std::shared_ptr<card>> AFightCards;
        //std::vector<std::shared_ptr<card>> BFightCards;

        ////
        //std::vector<std::shared_ptr<card>> AHandCards;
        //std::vector<std::shared_ptr<card>> BHandCards;
    }

};

#endif // !RENDER_ACTOR_H

