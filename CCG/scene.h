#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
#include <memory>
#include <vector>

#include "game_object.h"
#include "gameround.h"

class scene : public game_object
{
private:
	std::vector<std::shared_ptr<game_object>> items;

	//νṹ
	std::vector<std::shared_ptr<scene>> scenes;

	//GameroundڵϷ߼SceneеitemsҪ
	


public:
	scene() {};
	~scene();

	//óʵһ
	std::shared_ptr<gameround> gameRound;

	SDL_Surface* getSurface()
	{
		return surface.get();
	}

	SDL_Texture* getTexture()
	{
		return texture.get();
	}

	void putCardsInScene();

	std::vector<std::shared_ptr<game_object>> getItems()
	{
		return items;
	}

	void addItems(game_object* obj, ...);

	void addItem(game_object* obj);

	virtual void paintTexture();



};

#endif // !SCENE_H



