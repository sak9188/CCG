#ifndef ARENA_H
#define ARENA_H

#include <SDL.h>
#include <vector>
#include "charactor.h"

class Arena
{
private:
	SDL_Surface* surface;
	SDL_Texture* texture;



	SDL_Rect* rect;

public:

	//拿出来好测试

	//角色
	Charactor* charactorA;
	Charactor* charactorB;

	//牌堆
	CardStack* ACards;
	CardStack* BCards;

	//墓区
	std::vector<std::shared_ptr<Card>> ADeadCards;
	std::vector<std::shared_ptr<Card>> BDeadCards;

	//除外区
	std::vector<std::shared_ptr<Card>> AOutCards;
	std::vector<std::shared_ptr<Card>> BOutCards;

	//出牌区
	std::vector<std::shared_ptr<Card>> AFightCards;
	std::vector<std::shared_ptr<Card>> BFightCards;

	//手牌区
	std::vector<std::shared_ptr<Card>> AHandCards;
	std::vector<std::shared_ptr<Card>> BHandCards;

	bool addCardInAHandCards(std::shared_ptr<Card> card)
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

	Arena();
	~Arena();
};
#endif
