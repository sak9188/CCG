#ifndef WIN_EVENT_ACTOR_H
#define WIN_EVENT_ACTOR_H

#include <SDL.h>

#include "ccg_constant.h"
#include "event_actor.h"
#include "scene.h"
#include "card/card.h"
#include "creature.h"

class win_event_actor : public event_actor
{
private:
    scene sceneType;
    card cardType;
    creature creatureType;
    
    //̴¼
    void keyEventDisposer();

    //괦¼
    ::card* followCard;
    void mouseEventDisposer(const SDL_Event& e, scene& ob);
    bool LMouseButtonMotion(Uint32 states);

    //ж
    bool isCard(game_object* ob);

    //ģ庯
    template <class T, class D>
    bool isEqualType(T &t, D &d);
    


public:
    win_event_actor();

    virtual void eventDisposer(const SDL_Event& e, scene& ob);

    virtual ~win_event_actor() {};

};

template<class T, class D>
inline bool win_event_actor::isEqualType(T &Object, D &Class)
{
    return (typeid(Object) == typeid(D));
}

#endif // !WIN_EVENT_ACTOR_H

