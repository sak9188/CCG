#ifndef CGGGAME_H
#define CGGGAME_H

#include "CCG_constant.h"
#include "scene.h"
#include "eventActor.h"

//todo:: µ¥ÀýÄ£Ê½

class CGGGame
{
private:
	EventActor* eventActor;
	Scene* initScene;

	bool initMainWindow();
	void closeMainWindow();





public:
	CGGGame();

	void gameInit();
	void gameStart();
	void gameClose();

	~CGGGame();
};

#endif // !CGGGAME_H



