#pragma once

#include "Instruction.h"
#include "Instructions/Wait.h"

class WaitableInstruction : public Instruction
{
private:
    Wait::Wait *waiter;
public:
    WaitableInstruction(unsigned int waitTime);

    bool wait();
    virtual bool run() override = 0;
};