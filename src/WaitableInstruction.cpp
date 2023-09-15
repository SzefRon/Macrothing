#include "WaitableInstruction.h"

WaitableInstruction::WaitableInstruction(unsigned int waitTime)
{
    waiter = new Wait::Wait(waitTime);
}

bool WaitableInstruction::wait()
{
    if (waiter->run()) return true;
    return false;
}