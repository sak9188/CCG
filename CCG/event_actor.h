#ifndef EVENT_ACTOR_H
#define EVENT_ACTOR_H

#include "game_object.h"
#include "scene.h"

//TODOɽӿڣΪ˿ƽ̨Э
class event_actor
{
public:
	virtual void eventDisposer(const SDL_Event& e, scene& ob) = 0;
	virtual ~event_actor() {};


};

#endif // !EVENT_ACTOR_H

