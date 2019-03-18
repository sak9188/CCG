#ifndef CGGGAME_H
#define CGGGAME_H

#include <memory>

#include "CCG_constant.h"
#include "scene.h"
#include "eventActor.h"
#include "creature.h"

//todo:: 单例模式

class CGGGame
{
private:
	std::unique_ptr<EventActor> eventActor;
	std::unique_ptr<Scene> initScene;

	bool initMainWindow();
	void closeMainWindow();

	Creature* c = new Creature("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, 2, 3, 1, 0);



public:
	CGGGame();

	bool gameInit();
	void gameStart();
	void gameClose();

	~CGGGame();
};

#endif // !CGGGAME_H



