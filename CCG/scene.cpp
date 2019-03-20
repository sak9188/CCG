#include "scene.h"

#include <SDL_image.h>

Scene::~Scene()
{
}

void Scene::putCardsInScene()
{
	Arena* a = gameRound->arena.get();

	////牌堆
	//CardStack* ACards;
	//CardStack* BCards;

	////墓区
	//std::vector<std::shared_ptr<Card>> ADeadCards;
	if(a->ADeadCards.empty())
	//std::vector<std::shared_ptr<Card>> BDeadCards;

	////除外区
	//std::vector<std::shared_ptr<Card>> AOutCards;
	//std::vector<std::shared_ptr<Card>> BOutCards;

	////出牌区
	//std::vector<std::shared_ptr<Card>> AFightCards;
	//std::vector<std::shared_ptr<Card>> BFightCards;

	////手牌区
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

