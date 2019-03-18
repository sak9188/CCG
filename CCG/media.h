#ifndef LOAD_MEDIA_H
#define LOAD_MEDIA_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "CCG_constant.h"
#include "gameObject.h"

class Media
{
public:
	Media();
	~Media();

	bool loadMedia(GameObject & obj);
	SDL_Texture* loadTexture(std::string path);
};

#endif // !LOAD_MEDIA_H
