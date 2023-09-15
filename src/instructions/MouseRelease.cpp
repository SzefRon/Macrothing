#include "instructions/MouseRelease.h"

MouseRelease::MouseRelease(char key, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    unsigned long flag = 0ul;
    if (key == 'L' || key == 'l') flag = MOUSEEVENTF_LEFTUP;
    else if (key == 'M' || key == 'm') flag = MOUSEEVENTF_MIDDLEUP;
    else if (key == 'R' || key == 'r') flag = MOUSEEVENTF_RIGHTUP;

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = flag;
}