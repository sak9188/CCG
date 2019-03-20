#ifndef GAMEROUND_H
#define GAMEROUND_H

#include "arena.h"
#include "recorder.h"

class Gameround
{
private:
	std::unique_ptr<Arena> arena;
	std::unique_ptr<Recorder> recoder;

public:
	Gameround(Arena* oarena, Recorder* orecorder)
	{
		arena.reset(oarena);
		recoder.reset(orecorder);
	}

	Gameround() {};
	~Gameround() {};


};

#endif // !GAMEROUND_H

