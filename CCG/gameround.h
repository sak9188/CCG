#ifndef GAMEROUND_H
#define GAMEROUND_H

#include "arena.h"
#include "recorder.h"

class gameround
{
private:


public:

    //óò
    std::unique_ptr<arena> arena_inst;
    std::unique_ptr<recorder> recoder;

    gameround(arena* oarena, recorder* orecorder)
    {
        arena_inst.reset(oarena);
        recoder.reset(orecorder);
    }

    gameround()
    {
        arena_inst = std::make_unique<::arena>();
        recoder = std::make_unique<recorder>();
    };
    ~gameround() {};


};

#endif // !GAMEROUND_H

