#ifndef CGGGAME_H
#define CGGGAME_H

#include <memory>

#include "CCG_constant.h"
#include "scene.h"
#include "eventActor.h"
#include "creature.h"

//todo:: ����ģʽ

class CGGGame
{
private:
	std::unique_ptr<EventActor> eventActor;
	std::unique_ptr<Scene> initScene;

	bool initMainWindow();
	void closeMainWindow();

	SDL_Event e;
	Creature* ctest = new Creature("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, 2, 3, 1, 0);



public:
	CGGGame();

	bool quit = false;

	bool gameInit();
	void gameStart();
	void gameClose();

	void gameLoop();

	~CGGGame();
};

#endif // !CGGGAME_H



