#ifndef CGGGAME_H
#define CGGGAME_H

#include <memory>

#include "scene.h"
#include "event_actor.h"
#include "render_actor.h"
#include "creature.h"
#include "gameround.h"

//todo:: ģʽ

class cgg_game
{
private:
	std::unique_ptr<event_actor> eventActor;
	std::unique_ptr<render_acotor> renderAcotor;
	std::unique_ptr<scene> initScene;

	bool initMainWindow();
	void closeMainWindow();
		
	SDL_Event e;
	gameround* pGameRound;
	scene* currentScene;
	creature* ctest = new creature("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ",2, 3, 1, 0, 0);



public:
	//ó
	std::shared_ptr<gameround> game_round;

	cgg_game();

	bool gameInit();
	void gameStart();
	void gameClose();

	void gameLoop();

	~cgg_game();
};

#endif // !CGGGAME_H



