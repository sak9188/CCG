#ifndef EVENT_ACTOR_H
#define EVENT_ACTOR_H

#include "gameObject.h"
#include "scene.h"

//TODO：这个东西做成接口，为了跨平台协作
class EventActor
{
public:
	virtual void eventDisposer(const SDL_Event& e, Scene& ob) = 0;
	virtual ~EventActor() {};


};

#endif // !EVENT_ACTOR_H

