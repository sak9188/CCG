#include "cgg_game.h"
#include <stdio.h>

#include <SDL.h>

#include "media.h"
#include "win_event_actor.h"

cgg_game::~cgg_game()
{
}

cgg_game::cgg_game()
{    
    eventActor = std::make_unique<win_event_actor>();

    game_round = std::make_shared<gameround>();

    initScene = std::make_unique<scene>();
    currentScene = initScene.get();
    currentScene->gameRound = std::shared_ptr<gameround>(this->game_round);
}

bool cgg_game::gameInit()
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
        std::unique_ptr<media> media_obj = std::make_unique<media>();

        if (!media_obj->loadMedia(*currentScene))
        {
            printf("Failed to load media!\n");
            return false;
        }

        //սʿ볡
        currentScene->addItem(ctest);
                
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));
        game_round->arena_inst->addCardInAHandCards(std::make_shared<creature>("սʿ", RaceKind::MACHINE, RaceType::GROUND, PropertyType::EARTH, "һսʿ ", 2, 3, 1, 0, 0));



        return true;

    }
}

void cgg_game::gameStart()
{

    ctest->paintTexture();    
    gameLoop();

}
void cgg_game::gameClose()
{
    //close MainWindow
    closeMainWindow();
}

void cgg_game::gameLoop()
{
    //Ϸѭ
    while (!CCG_QUIT)
    {
        //¼
        while (SDL_PollEvent(&e) != 0)
        {
            eventActor->eventDisposer(e, *currentScene);
        }

        //Ⱦ
        renderAcotor->renderScene(currentScene);

        //Ϸݴ
    

        //Wait for 60 fps
        SDL_Delay(16.7);
        //SDL_Delay(500);
    }
}

bool cgg_game::initMainWindow()
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
        renderAcotor = std::make_unique<render_acotor>(CCG_MAIN_WINDOW, CCG_MAIN_RENDERER);

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

void cgg_game::closeMainWindow()
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