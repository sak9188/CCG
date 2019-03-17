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
};

#endif // !SCENE_H



