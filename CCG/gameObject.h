#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <memory>
#include <string>

class GameObject
{
protected:

	std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>    surface = { nullptr, SDL_FreeSurface };
	std::unique_ptr<SDL_Texture, decltype(SDL_DestroyTexture)*> texture = { nullptr, SDL_DestroyTexture };



	//std::unique_ptr<SDL_Surface, void(__cdecl *)(SDL_Surface *)>
	//	::unique_ptr
	//	(const std::unique_ptr<SDL_Surface, void(__cdecl *)(SDL_Surface *)>

	//		&)

	std::string description = "";

	//仅代表游戏中的可显示的实体
	std::unique_ptr<SDL_Rect> rect;

	//是否可见
	bool isVisble = true;

	//层
	int layer = 0;
	
	//是否可以触碰
	//bool isToucheble = true;

public:
	GameObject(SDL_Surface* msurface, SDL_Texture* mtexture, SDL_Rect* mrect,std::string des, bool isVisble = true, int layer = 0):
	isVisble(isVisble),layer(layer),description(des)
	{

		surface.reset(msurface);
		texture.reset(mtexture);
		rect.reset(mrect);

	}

	explicit GameObject(std::string str):description(str) {};


	//===========================
	GameObject();

	~GameObject();
	//===========================

	SDL_Rect* getRect()
	{
		return rect.get();
	}

	SDL_Texture* getTexture()
	{
		return texture.get();
	}

	std::string getDes()
	{
		return description;
	}

	void setSurface(SDL_Surface* sur)
	{
		surface.reset(sur);
	}

	void setTexture(SDL_Texture* tex)
	{
		texture.reset(tex);
	}

	void setDes(std::string str)
	{
		description = str;
	}

	virtual void paintTexture() {};


};


#endif // !GAME_OBJECT_H
