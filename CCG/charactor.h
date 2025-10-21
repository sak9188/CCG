#ifndef CHARACTOR_H
#define CHARACTOR_H

#include <string>
#include "card_stack.h"
#include "profession.h"

class charactor
{
private:
	std::string name;
	int life;
	int mage;
	int mageAccelerate;
	int attack;
	int defense;

	profession* prof;


public:
	charactor(std::string name, int life, int mage, int mageAccelerate, int attack, int defense,
		profession* prof) :life(life), name(name), mage(mage), mageAccelerate(mageAccelerate), attack(attack), defense(defense)
	{};

	~charactor();
};

#endif

