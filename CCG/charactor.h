#ifndef CHARACTOR_H
#define CHARACTOR_H

#include <string>
#include "cardStack.h"
#include "profession.h"

class Charactor
{
private:
	std::string name;
	int life;
	int mage;
	int mageAccelerate;
	int attack;
	int defense;

	Profession* profession;


public:
	Charactor(std::string name, int life, int mage, int mageAccelerate, int attack, int defense,
		Profession* profession) :life(life), name(name), mage(mage), mageAccelerate(mageAccelerate), attack(attack), defense(defense)
	{};

	~Charactor();
};

#endif

