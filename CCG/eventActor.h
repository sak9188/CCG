#ifndef EVENT_ACTOR_H
#define EVENT_ACTOR_H

//TODO：这个东西做成接口，为了跨平台协作
class EventActor
{
public:
	virtual void eventDisposer();
	virtual ~EventActor() {};


};

#endif // !EVENT_ACTOR_H

