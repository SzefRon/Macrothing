#include "instructions/KeyboardPress.h"

void KeyboardPress::configureInput(SHORT keyCode)
{
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = MapVirtualKey(LOBYTE(keyCode), 0);
}

KeyboardPress::KeyboardPress(char ch, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    SHORT keyCode = VkKeyScan(ch);
    configureInput(keyCode);
}

KeyboardPress::KeyboardPress(std::string key, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    SHORT keyCode = KeyCodes::keyboardKeyScans(key);
    configureInput(keyCode);
}