#ifndef SCENE_ITEM_H
#define SCENE_ITEM_H

#include "game_object.h"
class scene_item : public game_object
{
public:
	scene_item();
	~scene_item();

	virtual void paintTexture();
};

#endif
