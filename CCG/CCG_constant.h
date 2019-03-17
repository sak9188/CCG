#ifndef CGG_CONSTANT_H
#define CGG_CONSTANT_H

#include <SDL.h>
#include "enum/CCG_enum.h"

extern const int NORMAL_SCREEN_WIDTH = 1280;
extern const int NORMAL_SCREEN_HEIGHT = 960;

extern const int LARGE_SCREEN_WIDTH = 1920;
extern const int LARGE_SCREEN_HEIGHT = 1080;

extern SDL_Window* MAIN_WINDOW = NULL;
extern SDL_Surface* MAIN_SURFACE = NULL;
extern SDL_Renderer* MAIN_RENDERER = NULL;

#endif // !CGG_CONSTANT_H

