#ifndef CGGGAME_H
#define CGGGAME_H

#include "CCG_constant.h"

class CGGGame
{
private:
	
	static bool initMainWindow();


public:
	CGGGame() = delete;

	static void gameInit();
	static void gameStart();
	static void gameClose();

	~CGGGame();
};

#endif // !CGGGAME_H



