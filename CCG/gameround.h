#ifndef GAMEROUND_H
#define GAMEROUND_H

#include "arena.h"
#include "recorder.h"

class Gameround
{
private:
	Arena* arena;
	Recorder* recoder;

public:
	Gameround(Arena* arena, Recorder* recorder);
	~Gameround();
};

#endif // !GAMEROUND_H

