#pragma once

#include "instructions/InstructionsTypedef.h"

#include <string>
#include <fstream>
#include <deque>
#include <regex>
#include <iostream>

class Interpreter
{
private:
    std::string filePath;
public:
    Interpreter(std::string filePath);
    Loop *interpretFile();
};