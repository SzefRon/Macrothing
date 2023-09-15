#pragma once

#include "SendInputInstruction.h"
#include "helper/KeyCodes.h"

#include <Windows.h>
#include <string>
#include <algorithm>

class KeyboardRelease : public SendInputInstruction
{
private:
    void configureInput(SHORT keyCode);
public:
    KeyboardRelease(char ch, unsigned int waitTime);
    KeyboardRelease(std::string key, unsigned int waitTime);
};