#include "scene.h"

#include <SDL_image.h>

Scene::~Scene()
{
}

void Scene::putCardsInScene()
{
	Arena* a = gameRound->arena.get();

	////�ƶ�
	//CardStack* ACards;
	//CardStack* BCards;

	////Ĺ��
	//std::vector<std::shared_ptr<Card>> ADeadCards;
	if(a->ADeadCards.empty())
	//std::vector<std::shared_ptr<Card>> BDeadCards;

	////������
	//std::vector<std::shared_ptr<Card>> AOutCards;
	//std::vector<std::shared_ptr<Card>> BOutCards;

	////������
	//std::vector<std::shared_ptr<Card>> AFightCards;
	//std::vector<std::shared_ptr<Card>> BFightCards;

	////������
	//std::vector<std::shared_ptr<Card>> AHandCards;
	//std::vector<std::shared_ptr<Card>> BHandCards;
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

