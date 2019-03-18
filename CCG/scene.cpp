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
	items.push_back(obj);
}

void Scene::paintTexture()
{
}
