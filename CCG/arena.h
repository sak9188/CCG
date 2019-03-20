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

	//�ó����ò���

	//��ɫ
	Charactor* charactorA;
	Charactor* charactorB;

	//�ƶ�
	CardStack* ACards;
	CardStack* BCards;

	//Ĺ��
	std::vector<std::shared_ptr<Card>> ADeadCards;
	std::vector<std::shared_ptr<Card>> BDeadCards;

	//������
	std::vector<std::shared_ptr<Card>> AOutCards;
	std::vector<std::shared_ptr<Card>> BOutCards;

	//������
	std::vector<std::shared_ptr<Card>> AFightCards;
	std::vector<std::shared_ptr<Card>> BFightCards;

	//������
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
