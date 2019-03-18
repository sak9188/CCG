#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <memory>

class GameObject
{
protected:
	std::unique_ptr<SDL_Rect> rect;

public:
	GameObject();
	~GameObject();
};


#endif // !GAME_OBJECT_H
