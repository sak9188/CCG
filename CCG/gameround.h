#ifndef GAMEROUND_H
#define GAMEROUND_H

#include "arena.h"
#include "recorder.h"

class Gameround
{
private:


public:

	//ÄÃ³öÀ´£¬ºÃ²âÊÔ
	std::unique_ptr<Arena> arena;
	std::unique_ptr<Recorder> recoder;

	Gameround(Arena* oarena, Recorder* orecorder)
	{
		arena.reset(oarena);
		recoder.reset(orecorder);
	}

	Gameround() 
	{
		arena = std::make_unique<Arena>();
		recoder = std::make_unique<Recorder>();
	};
	~Gameround() {};


};

#endif // !GAMEROUND_H

