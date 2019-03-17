#include "scene.h"

#include <SDL_image.h>


Scene::Scene()
{
}


Scene::~Scene()
{
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
