#ifndef ARENA_H
#define ARENA_H

#include <SDL.h>
#include <vector>
#include "charactor.h"

class arena
{
private:
	SDL_Surface* surface;
	SDL_Texture* texture;



	SDL_Rect* rect;

public:

	//óò

	//ɫ
	charactor* charactorA;
	charactor* charactorB;

	//ƶ
	card_stack* ACards;
	card_stack* BCards;

	//Ĺ
	std::vector<std::shared_ptr<card>> ADeadCards;
	std::vector<std::shared_ptr<card>> BDeadCards;

	//
	std::vector<std::shared_ptr<card>> AOutCards;
	std::vector<std::shared_ptr<card>> BOutCards;

	//
	std::vector<std::shared_ptr<card>> AFightCards;
	std::vector<std::shared_ptr<card>> BFightCards;

	//
	std::vector<std::shared_ptr<card>> AHandCards;
	std::vector<std::shared_ptr<card>> BHandCards;

	bool addCardInAHandCards(std::shared_ptr<card> card)
	{
		if (AHandCards.size() == MAX_HAND_CARDS)
		{
			return false;
		}
		else
		{
			AHandCards.push_back(card);
			return true;
		}
	}

	const int MAX_FIGHT_CARDS = 8;
	const int MAX_HAND_CARDS = 7;

	arena();
	~arena();
};
#endif
