#include "scene.h"

#include <SDL_image.h>

scene::~scene()
{
}

void scene::putCardsInScene()
{
    arena* a = gameRound->arena_inst.get();

    ////ƶ
    //card_stack* ACards;
    //card_stack* BCards;

    ////Ĺ
    //std::vector<std::shared_ptr<card>> ADeadCards;
    if(a->ADeadCards.empty()) ;
    //std::vector<std::shared_ptr<card>> BDeadCards;

    ////
    //std::vector<std::shared_ptr<card>> AOutCards;
    //std::vector<std::shared_ptr<card>> BOutCards;

    ////
    //std::vector<std::shared_ptr<card>> AFightCards;
    //std::vector<std::shared_ptr<card>> BFightCards;

    ////
    //std::vector<std::shared_ptr<card>> AHandCards;
    //std::vector<std::shared_ptr<card>> BHandCards;
}

void scene::addItems(game_object* obj, ...)
{
}

void scene::addItem(game_object* obj)
{
    items.push_back(std::shared_ptr<game_object>(obj));
}

void scene::paintTexture()
{
}

