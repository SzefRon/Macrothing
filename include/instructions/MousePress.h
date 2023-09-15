#pragma once

#include "SendInputInstruction.h"

#include <Windows.h>

class MousePress : public SendInputInstruction
{
public:
    MousePress(char key, unsigned int waitTime);
};