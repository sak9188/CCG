#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <memory>

class GameObject
{
protected:

	//��������Ϸ�еĿ���ʾ��ʵ��
	std::unique_ptr<SDL_Rect> rect;

	//�Ƿ�ɼ�
	bool isVisble = true;

	//��
	int layer = 0;
	
	//�Ƿ���Դ���
	//bool isToucheble = true;

public:
	GameObject();
	~GameObject();
};


#endif // !GAME_OBJECT_H
