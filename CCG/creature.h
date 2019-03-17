#ifndef CREATURE_H
#define CREATURE_H

#include "card/card.h"
#include <SDL_image.h>

extern SDL_Window* WINDOW;
extern SDL_Renderer* RENDERER;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Creature final : public Card
{
private:
	RaceType raceType;
	RaceKind raceKind;
	PropertyType propertyType;
	int attack;
	int life;
	int defense;
	bool sacrifice;

	//战吼 调用lua函数
	//亡语
	//效果

	std::string pathToImg;

public:

	Creature(std::string name , RaceKind raceKind, RaceType raceType, PropertyType proType,
		int attack, int life, int defense, bool sacrifice, int x = 0, int y = 0) :Card(name, CardType::CREATURE, ConsumeType::MAGE, x, y),
		raceType(raceType), raceKind(raceKind), propertyType(proType), attack(attack), life(life), defense(defense), sacrifice(sacrifice)
	{
	}

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
		SDL_Rect* toprect = new SDL_Rect();
		toprect->h = getHeight();
		toprect->w = getWidth();

		surface = IMG_Load("img/fighter.jpg");
		SDL_Surface* s = SDL_CreateRGBSurfaceWithFormat(0, getWidth(), getHeight(), 32, SDL_PIXELFORMAT_RGBA32);

		SDL_Surface* optimizedSurface = SDL_ConvertSurface(surface, s->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image! SDL Error: %s\n", SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(surface);
		surface = optimizedSurface;
		
		SDL_FillRect(s, toprect, SDL_MapRGB(s->format, 130, 92, 66));
		toprect->y = getTopHeight();
		toprect->h = getMidHeight();
		SDL_BlitScaled(surface, NULL, s, toprect);
		
		texture = SDL_CreateTextureFromSurface(RENDERER, s);

		SDL_FreeSurface(s);
		SDL_FreeSurface(optimizedSurface);
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
		return texture;
	}

};

#endif // !CREATURE_H