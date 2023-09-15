#pragma once

class Abort
{
private:
    Abort() = default;
    static Abort &instance;
public:
    ~Abort() = default;
    static Abort &i();

    bool abort = false;
};