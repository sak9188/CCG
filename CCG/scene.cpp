#include "scene.h"

#include <SDL_image.h>

Scene::~Scene()
{
}

void Scene::addItems(GameObject* obj, ...)
{
}

void Scene::addItem(GameObject* obj)
{
	items.push_back(std::shared_ptr<GameObject>(obj));
}

void Scene::paintTexture()
{
}

