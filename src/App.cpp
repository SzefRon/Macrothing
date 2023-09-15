#include "App.h"

void App::abortThread(std::thread *&thr)
{
    Abort::i().abort = true;
    if (thr != nullptr && thr->joinable()) {
        thr->join();
        delete thr;
        thr = nullptr;
    } 
    Abort::i().abort = false;
}

void App::run(int argc, char *argv[])
{
    std::string filePath;
    if (argc == 1) {
        std::cout << "Path to macro: ";
        std::cin >> filePath;
    }
    else {
        filePath = std::string(argv[1]);
    }

    Interpreter interpreter(filePath);
    Loop *macro = interpreter.interpretFile();

    std::thread *thr = nullptr;
    bool blockStart1 = true;
    bool blockStart2 = true;

    while (true) {
        if (GetAsyncKeyState(VK_RSHIFT)) {
            if (blockStart1) {
                abortThread(thr);

                thr = new std::thread([macro](){
                    macro->run();
                });

                blockStart1 = false;
            }
        }
        else {
            blockStart1 = true;
        }
        if (GetAsyncKeyState(VkKeyScan('['))) {
            if (blockStart2) {
                abortThread(thr);
                
                blockStart2 = false;
            }
        } else {
            blockStart2 = true;
        }
    }
}
