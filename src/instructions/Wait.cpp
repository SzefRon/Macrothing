#include "instructions/Wait.h"

#include <chrono>

Wait::Wait::Wait(int waitTime) : waitTime(waitTime)
{
}

bool Wait::Wait::run()
{
    if (waitTime) {
        auto t0 = std::chrono::high_resolution_clock::now();
        while (true) {
            if (Abort::i().abort) return true;
            auto t1 = std::chrono::high_resolution_clock::now();
            auto dur = std::chrono::duration_cast
                <std::chrono::milliseconds>(t1-t0);
            if (dur.count() >= waitTime) break;
        }
    } else {
        if (Abort::i().abort) return true;
    }
    return false;
}