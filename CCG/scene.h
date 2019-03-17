#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>

class Scene
{
private:
	SDL_Surface* surface;
	SDL_Texture* texture;

public:
	Scene();
	~Scene();

	SDL_Surface* getSurface()
	{
		return surface;
	}

	SDL_Texture* getTexture()
	{
		return texture;
	}
};

#endif // !SCENE_H



