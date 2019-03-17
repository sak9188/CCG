#include "CGGGame.h"
#include <stdio.h>

#include <SDL.h>

#include "CCG_constant.h"
#include "media.h"

CGGGame::~CGGGame()
{
}

void CGGGame::gameInit()
{
	
	if (!initMainWindow())
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		//Load media
		Media* media = new Media();

		if (!media->loadMedia(texture))
		{
			printf("Failed to load media!\n");
		}
		else
		{
			c->paintTexture();
			while (!quit)
			{
				eventDispose(c->getRect());

				//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x1F, 0xFF, 0xFF));
				SDL_SetRenderDrawColor(MAIN_RENDERER, 0x00, 0x00, 0x00, 0x00);
				SDL_RenderClear(MAIN_RENDERER);

				//SDL_SetRenderDrawColor(RENDERER, 0x82, 0x5c, 0x42, 0xff);
				SDL_RenderFillRect(MAIN_RENDERER, c->getRect());

				SDL_RenderCopy(MAIN_RENDERER, c->getTexture(), NULL, c->getRect());

				//Apply the image
				//SDL_BlitSurface(gHello, NULL, screenSurface, moveble_rect);

				//Update the surface
				//SDL_UpdateWindowSurface(WINDOW);

				SDL_RenderPresent(MAIN_RENDERER);

				//Wait two seconds
				SDL_Delay(16.7);
			}

		}

	}
}

void CGGGame::gameStart()
{

}
void CGGGame::gameClose()
{

}

bool CGGGame::initMainWindow()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		MAIN_WINDOW = SDL_CreateWindow("FUCK SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, NORMAL_SCREEN_WIDTH, NORMAL_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		MAIN_RENDERER = SDL_CreateRenderer(MAIN_WINDOW, -1, SDL_RENDERER_ACCELERATED);
		if (MAIN_WINDOW == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			MAIN_SURFACE = SDL_GetWindowSurface(MAIN_WINDOW);
		}
	}

	return success;
}

void close(SDL_Window *&gWindow, SDL_Surface *&gHelloWorld)
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}