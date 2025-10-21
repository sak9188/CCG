#ifndef LOAD_MEDIA_H
#define LOAD_MEDIA_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "ccg_constant.h"
#include "game_object.h"

class media
{
public:
	media();
	~media();

	bool loadMedia(game_object & obj);
	SDL_Texture* loadTexture(std::string path);
};

#endif // !LOAD_MEDIA_H
