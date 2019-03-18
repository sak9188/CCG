//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <string>

#include "CGGGame.h"

#include "creature.h"
#include "enum/CCG_enum.h"

//Screen dimension constants
extern const int SCREEN_WIDTH = 1280;
extern const int SCREEN_HEIGHT = 960;

extern SDL_Window* MAIN_WINDOW = NULL;
extern SDL_Renderer* MAIN_RENDERER = NULL;

double gSpeed = 10;

//Starts up SDL and creates window
bool init(SDL_Window *&gWindow, SDL_Surface *&gScreenSurface);

//Loads media
bool loadMedia(SDL_Texture *&texture);

//Frees media and shuts down SDL
void close(SDL_Window *&gWindow, SDL_Surface *&gHelloWorld);

void moveCharacter(SDL_Rect* pos, const SDL_Scancode code);

void keydownDispose(SDL_Event* e, SDL_Rect* pos);

double getSpeedValue(int base = 1);

void eventDispose(SDL_Rect* rect);

SDL_Texture* loadTexture(std::string path);

bool contactedCard(int x, int y);

bool follow = false;

SDL_Rect lastPos = { 0 };

//===============================================================================

bool quit = false;

SDL_Event* e = new SDL_Event();

Creature* c = new Creature("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, 2, 3, 1, 0);

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

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	SDL_Surface* gHello = NULL;

	SDL_Texture* texture = NULL;

	//Initialize SDL
	if (!init(MAIN_WINDOW, screenSurface))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		//Load media
		if (!loadMedia(texture))
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

	close(WINDOW, screenSurface);

	return 0;
}

bool init(SDL_Window *&gWindow, SDL_Surface *&gScreenSurface)
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
		gWindow = SDL_CreateWindow("FUCK SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia(SDL_Texture *&texture)
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	texture = loadTexture("img/sword.png");
	if (texture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
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

void moveCharacter(SDL_Rect* pos, const SDL_Scancode code)
{
	switch (code)
	{
	case (SDL_SCANCODE_UP):
		pos->y -= getSpeedValue();
		break;
	case (SDL_SCANCODE_DOWN):
		pos->y += getSpeedValue();
		break;
	case (SDL_SCANCODE_LEFT):
		pos->x -= getSpeedValue();
		break;
	case (SDL_SCANCODE_RIGHT):
		pos->x += getSpeedValue();
	}

	printf("x:%d y:%d \n", pos->x, pos->y);
}

double getSpeedValue(int base)
{
	return base * gSpeed;
}

void keydownDispose(SDL_Event* e, SDL_Rect* pos)
{
	moveCharacter(pos, e->key.keysym.scancode);
}

void eventDispose(SDL_Rect* moveble_rect)
{


	while (SDL_PollEvent(e) != 0)
	{
		switch (e->type)
		{
		case (SDL_KEYDOWN):
			keydownDispose(e, moveble_rect);
			break;
		case (SDL_QUIT):
			quit = true;
			break;
		case (SDL_MOUSEMOTION):
			//printf("MX:%d MY:%d\n", e->motion.x, e->motion.y);
			//SDL_Rect nowPos = c->getRec()
			if (follow)
			{
				
				c->getRect()->x += e->motion.x - lastPos.x;
				c->getRect()->y += e->motion.y - lastPos.y;

				lastPos.x = e->motion.x;
				lastPos.y = e->motion.y;
			}
			break;
		case (SDL_MOUSEBUTTONDOWN):

			//printf("SDL_MOUSEBUTTONDOWN\n");
			//printf("x:%d y:%d\n", c->getRect()->x, c->getRect()->y);
			//printf("lx:%d, rx:%d, ty:%d, by:%d\n", c->getBoundaryLx(), c->getBoundaryRx(), c->getBoundaryTy(), c->getBoundaryBy());
			if (contactedCard(e->motion.x, e->motion.y))
			{
				printf("contactedCard\n");
				lastPos.x = e->motion.x;
				lastPos.y = e->motion.y;
				follow = true;
			}
			break;
		case (SDL_MOUSEBUTTONUP):
			if(follow)
				follow = false;
			break;
		}

	}

}

bool contactedCard(int x, int y)
{
	if (x < c->getBoundaryRx() && x > c->getBoundaryLx() && y > c->getBoundaryTy() && y < c->getBoundaryBy())
		return true;
	else
		return false;
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(RENDERER, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
