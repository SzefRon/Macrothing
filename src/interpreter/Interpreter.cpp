#include "interpreter/Interpreter.h"

Interpreter::Interpreter(std::string filePath) : filePath(filePath)
{}

Loop *Interpreter::interpretFile()
{
    std::ifstream file;
    file.open(filePath);

    if (!file.is_open()) return nullptr;

    int loopDepth = 0;
    std::deque<Loop *> loopInstances;
    loopInstances.push_back(new Loop(1));

    std::string line;
    std::smatch match;
    while (std::getline(file, line)) {
        //  LOOP
        if (std::regex_search(line, match, std::regex("loop\\((\\d+)\\)"))) {
            int loops = std::stoul(match[1].str());
            Loop *loop = new Loop(loops);

            loopInstances.at(loopDepth)->add(loop);
            loopInstances.push_back(loop);
            loopDepth++;
        }
        //  ;
        else if (std::regex_search(line, match, std::regex(";"))) {
            loopDepth--;
        }
        //  WAIT
        else if (std::regex_search(line, match, std::regex("wait\\((\\d+)\\)"))) {
            unsigned int waitTime = std::stoul(match[1].str());
            Wait::Wait *wait = new Wait::Wait(waitTime);

            loopInstances.at(loopDepth)->add(wait);
        }
        //  KBP
        else if (std::regex_search(line, match, std::regex("kbp\\((.+),(\\d+)\\)"))) {
            KeyboardPress *kbp;
            unsigned int waitTime = std::stoul(match[2].str());
            if (match[1].length() == 1) {
                char ch = match[1].str().at(0);
                kbp = new KeyboardPress(ch, waitTime);
            }
            else {
                std::string key = match[1].str();
                kbp = new KeyboardPress(key, waitTime);
            }
            loopInstances.at(loopDepth)->add(kbp);
        }
        // KBR
        else if (std::regex_search(line, match, std::regex("kbr\\((.+),(\\d+)\\)"))) {
            KeyboardRelease *kbr;
            unsigned int waitTime = std::stoul(match[2].str());
            if (match[1].length() == 1) {
                char ch = match[1].str().at(0);
                kbr = new KeyboardRelease(ch, waitTime);
            }
            else {
                std::string key = match[1].str();
                kbr = new KeyboardRelease(key, waitTime);
            }
            loopInstances.at(loopDepth)->add(kbr);
        }
        //  MP
        else if (std::regex_search(line, match, std::regex("mp\\((.),(\\d+)\\)"))) {
            char key = match[1].str().at(0);
            unsigned int waitTime = std::stoul(match[2].str());
            MousePress *mp = new MousePress(key, waitTime);
            
            loopInstances.at(loopDepth)->add(mp);
        }
        //  MR
        else if (std::regex_search(line, match, std::regex("mr\\((.),(\\d+)\\)"))) {
            char key = match[1].str().at(0);
            unsigned int waitTime = std::stoul(match[2].str());
            MouseRelease *mr = new MouseRelease(key, waitTime);

            loopInstances.at(loopDepth)->add(mr);
        }
        //  MM
        else if (std::regex_search(line, match, std::regex("mm\\((.),(-?\\d+),(-?\\d+),(\\d+)\\)"))) {
            char mode = match[1].str().at(0);
            long x = std::stol(match[2].str());
            long y = std::stol(match[3].str());
            unsigned int waitTime = std::stoul(match[4].str());
            MouseMove *mm = new MouseMove(mode, x, y, waitTime);

            loopInstances.at(loopDepth)->add(mm);
        }
    }
    file.close();
    return loopInstances.at(0);
}