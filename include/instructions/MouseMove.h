#pragma once

#include "SendInputInstruction.h"

#include <Windows.h>
#include <math.h>

class MouseMove : public SendInputInstruction
{
public:
    MouseMove(char mode, long x, long y, unsigned int waitTime);
};