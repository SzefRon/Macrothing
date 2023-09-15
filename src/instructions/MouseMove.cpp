#include "instructions/MouseMove.h"

MouseMove::MouseMove(char mode, long x, long y, unsigned int waitTime)
    : SendInputInstruction(waitTime)
{
    unsigned long flag = 0ul;
    if (mode == 'A' || mode == 'a') {
        flag = MOUSEEVENTF_ABSOLUTE;

        int screenX = GetSystemMetrics(SM_CXSCREEN);
        int screenY = GetSystemMetrics(SM_CYSCREEN);
        x = lround((65535.0f / screenX) * x);
        y = lround((65535.0f / screenY) * y);
    }

    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    
    input.mi.dwFlags = flag | MOUSEEVENTF_MOVE;
}