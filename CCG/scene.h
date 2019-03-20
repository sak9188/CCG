#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <memory>
#include <vector>

#include "gameObject.h"
#include "gameround.h"

class Scene : public GameObject
{
private:
	std::vector<std::shared_ptr<GameObject>> items;

	//树形结构
	std::vector<std::shared_ptr<Scene>> scenes;

	//Gameround内在的游戏逻辑，Scene中的items都要从这里面拿
	


public:
	Scene() {};
	~Scene();

	//先拿出来实验一下
	std::unique_ptr<Gameround> gameRound;

	SDL_Surface* getSurface()
	{
		return surface.get();
	}

	SDL_Texture* getTexture()
	{
		return texture.get();
	}

	std::vector<std::shared_ptr<GameObject>> getItems()
	{
		return items;
	}

	void addItems(GameObject* obj, ...);

	void addItem(GameObject* obj);

	virtual void paintTexture();

};

#endif // !SCENE_H



