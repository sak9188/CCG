#ifndef CREATURE_H
#define CREATURE_H

#include "card/card.h"
#include <SDL_image.h>

extern SDL_Window* CCG_MAIN_RWINDOW;
extern SDL_Renderer* CCG_MAIN_RENDERER;

class creature final : public card
{
private:
	RaceType raceType;
	RaceKind raceKind;
	PropertyType propertyType;
	int attack;
	int life;
	int defense;
	bool sacrifice;

	//ս lua
	//
	//Ч

	std::string pathToImg;

public:

	creature(std::string name , RaceKind raceKind, RaceType raceType, PropertyType proType,std::string des,
		int attack, int life, int defense, bool sacrifice, int x = 0, int y = 0) :card(name, CardType::CREATURE, ConsumeType::MAGE, x, y, des),
		raceType(raceType), raceKind(raceKind), propertyType(proType), attack(attack), life(life), defense(defense), sacrifice(sacrifice)
	{
	}

	creature() {};

	virtual void setName(std::string name)
	{
		this->name = name;
	}

	virtual void setConsumeType(ConsumeType type)
	{
		this->consumeType = type;
	}

	virtual void paintTexture()
	{
		//ʾ
		SDL_Rect* toprect = new SDL_Rect();
		toprect->h = getHeight();
		toprect->w = getWidth();

		surface.reset(IMG_Load("img/fighter.jpg"));//ԹҲҪĵ
		SDL_Surface* s = SDL_CreateRGBSurfaceWithFormat(0, getWidth(), getHeight(), 32, SDL_PIXELFORMAT_RGBA32);

		SDL_Surface* optimizedSurface = SDL_ConvertSurface(surface.get(), s->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image! SDL Error: %s\n", SDL_GetError());
		}

		surface.reset(optimizedSurface);
		
		SDL_FillRect(s, toprect, SDL_MapRGB(s->format, 130, 92, 66));
		toprect->y = getTopHeight();
		toprect->h = getMidHeight();
		SDL_BlitScaled(surface.get(), NULL, s, toprect);
		
		texture.reset(SDL_CreateTextureFromSurface(CCG_MAIN_RENDERER, s));

		//Free memory
		SDL_FreeSurface(s);
	}

	void setRaceType(RaceType type)
	{
		this->raceType = type;
	}

	void setRaceKind(RaceKind kind)
	{
		this->raceKind = kind;
	}

	void setPropertyType(PropertyType propertyType)
	{
		this->propertyType = propertyType;
	}

	void setAttack(int attack)
	{
		this->attack = attack;
	}

	int setLife(int life)
	{
		this->life = life;
	}

	int setDefense(int defense)
	{
		this->defense = defense;
	}

	bool setSacrifice(bool sacrifice)
	{
		this->sacrifice = sacrifice;
	}

	virtual std::string getName()
	{
		return name;
	}

	virtual CardType getCardType()
	{
		return cardType;
	}

	virtual ConsumeType getConsumeType()
	{
		return getConsumeType();
	}

	RaceType getRaceType()
	{
		return raceType;
	}

	RaceKind getRaceKind()
	{
		return raceKind;
	}

	PropertyType getPropertyType()
	{
		return propertyType;
	}

	int getAttack()
	{
		return attack;
	}

	int getLife()
	{
		return life;
	}

	int getDefense()
	{
		return defense;
	}

	bool getSacrifice()
	{
		return sacrifice;
	}

	SDL_Texture* getTexture()
	{
		return texture.get();
	}

};

#endif // !CREATURE_H