#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <memory>

class GameObject
{
protected:

	//仅代表游戏中的可显示的实体
	std::unique_ptr<SDL_Rect> rect;

	//是否可见
	bool isVisble = true;

	//层
	int layer = 0;
	
	//是否可以触碰
	//bool isToucheble = true;

public:
	GameObject();
	~GameObject();
};


#endif // !GAME_OBJECT_H
