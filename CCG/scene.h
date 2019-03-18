#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <memory>

#include "gameObject.h"

class Scene : public GameObject
{
private:
	std::unique_ptr<SDL_Surface> surface;
	std::unique_ptr<SDL_Texture> texture;

public:
	Scene();
	~Scene();

	SDL_Surface* getSurface()
	{
		return surface.get();
	}

	SDL_Texture* getTexture()
	{
		return texture.get();
	}
};

#endif // !SCENE_H



