#ifndef CGGGAME_H
#define CGGGAME_H

#include <memory>

#include "scene.h"
#include "eventActor.h"
#include "renderActor.h"
#include "creature.h"
#include "gameround.h"

//todo:: 单例模式

class CGGGame
{
private:
	std::unique_ptr<EventActor> eventActor;
	std::unique_ptr<RenderAcotor> renderAcotor;
	std::unique_ptr<Scene> initScene;

	bool initMainWindow();
	void closeMainWindow();
		
	SDL_Event e;
	Gameround* pGameRound;
	Scene* currentScene;
	Creature* ctest = new Creature("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ",2, 3, 1, 0, 0);



public:
	CGGGame();

	bool gameInit();
	void gameStart();
	void gameClose();

	void gameLoop();

	~CGGGame();
};

#endif // !CGGGAME_H



