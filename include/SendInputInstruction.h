#pragma once

#include "WaitableInstruction.h"

#include <windows.h>

class SendInputInstruction : public WaitableInstruction
{
protected:
    INPUT input;
public:
    SendInputInstruction(unsigned int waitTime);
    bool run() override;
};