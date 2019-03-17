#ifndef CGGGAME_H
#define CGGGAME_H

class CGGGame
{


public:
	CGGGame() = delete;

	static void gameInit();
	static void gameStart();
	static void gameClose();

	~CGGGame();
};

#endif // !CGGGAME_H



