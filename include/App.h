#pragma once

#include "interpreter/Interpreter.h"
#include "Abort.h"

#include <string>
#include <thread>
#include <iostream>

class App
{
private:
    void abortThread(std::thread *&thr);
public:
    void run(int argc, char* argv[]);
};