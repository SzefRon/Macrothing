#include "instructions/MousePress.h"

MousePress::MousePress(char key, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    unsigned long flag = 0ul;
    if (key == 'L' || key == 'l') flag = MOUSEEVENTF_LEFTDOWN;
    else if (key == 'M' || key == 'm') flag = MOUSEEVENTF_MIDDLEDOWN;
    else if (key == 'R' || key == 'r') flag = MOUSEEVENTF_RIGHTDOWN;

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = flag;
}