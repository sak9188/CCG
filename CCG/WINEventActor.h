#ifndef WIN_EVENT_ACTOR_H
#define WIN_EVENT_ACTOR_H

#include <SDL.h>

#include "eventActor.h"

class WINEventActor : public EventActor
{
public:
	WINEventActor();

	virtual void eventDisposer(const SDL_Event& e, GameObject& ob);

	virtual ~WINEventActor() {};
};

#endif // !WIN_EVENT_ACTOR_H


