#ifndef ARENA_H
#define ARENA_H

#include "charactor.h"
#include <SDL.h>

class Arena
{
private:
	Charactor* charactorA;
	Charactor* charactorB;

	SDL_Surface* surface;
	SDL_Texture* texture;

	CardStack* ACards;
	CardStack* BCards;

	SDL_Rect* rect;

public:
	Arena();
	~Arena();
};
#endif
