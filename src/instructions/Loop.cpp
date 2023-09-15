#include "instructions/Loop.h"

#include <iostream>

Loop::Loop(unsigned int loops) : loops(loops)
{

}

bool Loop::run()
{
    for (unsigned int i = 0u; i < loops || loops == 0u; i++) {
        for (auto &instruction : instructions) {
            WaitableInstruction *waitableInstruction = dynamic_cast<WaitableInstruction *>(instruction);
            if (instruction->run()) return true;
            if (waitableInstruction && waitableInstruction->wait()) return true;
        }
    }
    return false;
}

void Loop::add(Instruction *instruction)
{
    instructions.push_back(instruction);
}