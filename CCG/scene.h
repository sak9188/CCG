#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <memory>
#include <vector>

#include "gameObject.h"

class Scene : public GameObject
{
private:
	std::vector<GameObject*> items;

	//Ê÷ÐÎ½á¹¹
	std::vector<Scene> scenes;

public:
	Scene() {};
	~Scene();

	SDL_Surface* getSurface()
	{
		return surface.get();
	}

	SDL_Texture* getTexture()
	{
		return texture.get();
	}

	std::vector<GameObject*> getItems()
	{
		return items;
	}

	void addItems(GameObject* obj, ...);

	void addItem(GameObject* obj);

	virtual void paintTexture();

};

#endif // !SCENE_H



