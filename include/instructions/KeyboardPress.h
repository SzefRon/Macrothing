#pragma once

#include "SendInputInstruction.h"
#include "helper/KeyCodes.h"

#include <Windows.h>
#include <string>
#include <algorithm>

class KeyboardPress : public SendInputInstruction
{
private:
    void configureInput(SHORT keyCode);
public:
    KeyboardPress(char ch, unsigned int waitTime);
    KeyboardPress(std::string key, unsigned int waitTime);
};