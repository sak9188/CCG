#include "CGGGame.h"
#include <stdio.h>

#include <SDL.h>

#include "media.h"
#include "WINEventActor.h"

CGGGame::~CGGGame()
{
}

CGGGame::CGGGame()
{	
	eventActor = std::make_unique<WINEventActor>();

	gameround = std::make_shared<Gameround>();

	initScene = std::make_unique<Scene>();
	currentScene = initScene.get();
	currentScene->gameRound = std::shared_ptr<Gameround>(this->gameround);
}

bool CGGGame::gameInit()
{
	//Create window
	if (!initMainWindow())
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{		
		//Load media
		std::unique_ptr<Media> media = std::make_unique<Media>();

		if (!media->loadMedia(*currentScene))
		{
			printf("Failed to load media!\n");
			return false;
		}

		//把战士加入场景中
		currentScene->addItem(ctest);
				
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));
		gameround->arena->addCardInAHandCards(std::make_shared<Creature>("战士", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "这是一个战士 ", 2, 3, 1, 0, 0));



		return true;

	}
}

void CGGGame::gameStart()
{

	ctest->paintTexture();	
	gameLoop();

}
void CGGGame::gameClose()
{
	//close MainWindow
	closeMainWindow();
}

void CGGGame::gameLoop()
{
	//整个游戏循环
	while (!CCG_QUIT)
	{
		//事件处理
		while (SDL_PollEvent(&e) != 0)
		{
			eventActor->eventDisposer(e, *currentScene);
		}

		//渲染处理
		renderAcotor->renderScene(currentScene);

		//游戏数据处理
	

		//Wait for 60 fps
		SDL_Delay(16.7);
		//SDL_Delay(500);
	}
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
		CCG_MAIN_WINDOW = SDL_CreateWindow("FUCK SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, NORMAL_SCREEN_WIDTH, NORMAL_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		CCG_MAIN_RENDERER = SDL_CreateRenderer(CCG_MAIN_WINDOW, -1, SDL_RENDERER_ACCELERATED);
		renderAcotor = std::make_unique<RenderAcotor>(CCG_MAIN_WINDOW, CCG_MAIN_RENDERER);

		if (CCG_MAIN_WINDOW == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			CCG_MAIN_SURFACE = SDL_GetWindowSurface(CCG_MAIN_WINDOW);
		}
	}

	return success;
}

void CGGGame::closeMainWindow()
{
	//delete renderer
	SDL_DestroyRenderer(CCG_MAIN_RENDERER);
	CCG_MAIN_RENDERER = NULL;

	//Deallocate surface
	SDL_FreeSurface(CCG_MAIN_SURFACE);
	CCG_MAIN_SURFACE = NULL;

	//Destroy window
	SDL_DestroyWindow(CCG_MAIN_WINDOW);
	CCG_MAIN_WINDOW = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}