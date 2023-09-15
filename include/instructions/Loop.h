#pragma once

#include <deque>

#include "WaitableInstruction.h"

class Loop : public Instruction
{
private:
    std::deque<Instruction *> instructions;
    unsigned int loops;
public:
    Loop(unsigned int loops);

    bool run() override;

    void add(Instruction *instruction);
};