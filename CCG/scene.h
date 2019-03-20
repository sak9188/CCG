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

	//���νṹ
	std::vector<std::shared_ptr<Scene>> scenes;

	//Gameround���ڵ���Ϸ�߼���Scene�е�items��Ҫ����������
	


public:
	Scene() {};
	~Scene();

	//���ó���ʵ��һ��
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



