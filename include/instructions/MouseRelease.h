#pragma once

#include "SendInputInstruction.h"

#include <Windows.h>

class MouseRelease : public SendInputInstruction
{
public:
    MouseRelease(char key, unsigned int waitTime);
};