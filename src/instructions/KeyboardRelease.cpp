#include "instructions/KeyboardRelease.h"

void KeyboardRelease::configureInput(SHORT keyCode)
{
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    input.ki.wScan = MapVirtualKey(LOBYTE(keyCode), 0);
}

KeyboardRelease::KeyboardRelease(char ch, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    SHORT keyCode = VkKeyScan(ch);
    configureInput(keyCode);
}

KeyboardRelease::KeyboardRelease(std::string key, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);
    SHORT keyCode = KeyCodes::keyboardKeyScans(key);
    configureInput(keyCode);
}