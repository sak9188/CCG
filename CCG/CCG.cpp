//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <string>

#include "CGGGame.h"

#include "creature.h"
#include "enum/CCG_enum.h"

extern SDL_Window* CCG_MAIN_WINDOW = NULL;
extern SDL_Surface* CCG_MAIN_SURFACE = NULL;
extern SDL_Renderer* CCG_MAIN_RENDERER = NULL;

extern const int NORMAL_SCREEN_WIDTH = 1280;
extern const int NORMAL_SCREEN_HEIGHT = 960;

extern const int LARGE_SCREEN_WIDTH = 1920;
extern const int LARGE_SCREEN_HEIGHT = 1080;

extern bool CCG_QUIT = false;


int main(int argc, char* args[])
{
	//Create game object
	CGGGame* mainGame = new CGGGame();

	//game.init
	if (!mainGame->gameInit())
	{
		printf("Failed to initial game!\n");
	}

	//game.start
	mainGame->gameStart();

	//game.close
	mainGame->gameClose();

	return 0;
}