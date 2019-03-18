#ifndef CARD_H
#define CARD_H

#include "../enum/CCG_enum.h"
#include <SDL.h>
#include <string>

class Card
{
public:
    virtual void setName(std::string name) = 0;

    virtual std::string getName() = 0;
    virtual CardType getCardType() = 0;
    virtual ConsumeType getConsumeType() = 0;

	Card(std::string name, CardType type, ConsumeType consumeType, int x, int y) :name(name),
		cardType(cardType), consumeType(consumeType) 
	{
		rect = new SDL_Rect();
		rect->x = x;
		rect->y = y;
		rect->w = getWidth();
		rect->h = getHeight(); 
	}

	~Card()
	{
		delete surface;
		delete texture;

		delete rect;
	}

	virtual void paintTexture() = 0;

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

	SDL_Rect* getRect()
	{
		return rect;
	}

protected:
    std::string name;
    CardType cardType;
    ConsumeType consumeType;

	SDL_Surface* surface;
	SDL_Texture* texture;

	SDL_Rect* rect;

	unsigned int cardSeries;

	const int width = 64;
	const int height = 96;

	const int topHeight = 10;
	const int midHeight = 54;
	const int botHeight = 32;

	int scal = 2.5;

};

#endif
