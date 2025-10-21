#ifndef CARDSTACK_H
#define CARDSTACK_H

#include <vector>
#include "card/card.h"

class card_stack
{
private:
	static const int MAX_MAINCARDS = 60;
	static const int MAX_VICECARDS = 15;

	std::vector<std::shared_ptr<card>> mainCards;
	std::vector<std::shared_ptr<card>> viceCards;

	

public:
	card_stack();
	~card_stack();
};

#endif // !CARDSTACK_H


