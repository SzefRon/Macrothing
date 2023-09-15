#include "SendInputInstruction.h"

SendInputInstruction::SendInputInstruction(unsigned int waitTime)
    : WaitableInstruction(waitTime)
{
}

bool SendInputInstruction::run()
{
    SendInput(1, &input, sizeof(input));
    return false;
}
