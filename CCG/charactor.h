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

	CardStack* cards;
	Profession* profession;


public:
	Charactor();
	~Charactor();
};

#endif

