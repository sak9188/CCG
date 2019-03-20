#ifndef CARDSTACK_H
#define CARDSTACK_H

#include <vector>
#include "card/card.h"

class CardStack
{
private:
	static const int MAX_MAINCARDS = 60;
	static const int MAX_VICECARDS = 15;

	std::vector<std::shared_ptr<Card>> mainCards;
	std::vector<std::shared_ptr<Card>> viceCards;

	

public:
	CardStack();
	~CardStack();
};

#endif // !CARDSTACK_H


