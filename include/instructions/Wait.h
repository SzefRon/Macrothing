#pragma once

#include "Instruction.h"
#include "Abort.h"

namespace Wait
{

class Wait : public Instruction
{
private:
    unsigned int waitTime;
public:
    Wait(int waitTime);
    bool run() override;
};

};