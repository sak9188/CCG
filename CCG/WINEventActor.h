#ifndef WIN_EVENT_ACTOR_H
#define WIN_EVENT_ACTOR_H

#include <SDL.h>

#include "CCG_constant.h"
#include "eventActor.h"
#include "scene.h"
#include "creature.h"

class WINEventActor : public EventActor
{
private:
	Scene sceneType;
	Card cardType;
	Creature creatureType;
	
	//���̴����¼�
	void keyEventDisposer();

	//��괦���¼�
	Card* followCard;
	void mouseEventDisposer(const SDL_Event& e, Scene& ob);
	bool LMouseButtonMotion(Uint32 states);

	//�����ж�
	bool isCard(GameObject* ob);

	//ģ�庯��
	template <class T, class D>
	bool isEqualType(T &t, D &d);
	


public:
	WINEventActor();

	virtual void eventDisposer(const SDL_Event& e, Scene& ob);

	virtual ~WINEventActor() {};

};

template<class T, class D>
inline bool WINEventActor::isEqualType(T &Object, D &Class)
{
	return (typeid(Object) == typeid(D));
}

#endif // !WIN_EVENT_ACTOR_H

