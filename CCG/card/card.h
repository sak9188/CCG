#ifndef CARD_H
#define CARD_H


#include <SDL.h>
#include <string>
#include <memory>

#include "../enum/CCG_enum.h"
#include "../gameObject.h"

class Card : public GameObject
{
public:
    virtual void setName(std::string name) = 0;

    virtual std::string getName() = 0;
    virtual CardType getCardType() = 0;
    virtual ConsumeType getConsumeType() = 0;

	Card(std::string name, CardType type, ConsumeType consumeType, int x, int y, std::string str) :GameObject(str),name(name),
		cardType(cardType), consumeType(consumeType) 
	{
		rect.reset(new SDL_Rect());
		rect->x = x;
		rect->y = y;
		rect->w = getWidth();
		rect->h = getHeight(); 
	}

	~Card()
	{
	}

	//virtual void paintTexture() = 0;

	bool isContacted(int x, int y)
	{
		if (x < getBoundaryRx() && x > getBoundaryLx() && y > getBoundaryTy() && y < getBoundaryBy())
			return true;
		else
			return false;
	}

	bool isContacted(const SDL_Rect& rect)
	{
		return isContacted(rect.x, rect.y);
	}

	double getWidth()
	{
		return width * scal;
	}

	double getHeight()
	{
		return height * scal;
	}

	double getTopHeight()
	{
		return topHeight * scal;
	}

	double getBotHeight()
	{
		return botHeight * scal;
	}

	double getMidHeight()
	{
		return midHeight * scal;
	}

	int getBoundaryLx()
	{
		return rect->x;
	}

	int getBoundaryTy()
	{
		return rect->y;
	}

	int getBoundaryRx()
	{
		return rect->x + getWidth();
	}

	int getBoundaryBy()
	{
		return rect->y + getHeight();
	}

protected:
    std::string name;
    CardType cardType;
    ConsumeType consumeType;

	unsigned int cardSeries;

	const int width = 64;
	const int height = 96;

	const int topHeight = 10;
	const int midHeight = 54;
	const int botHeight = 32;

	int scal = 2.5;

};

#endif
