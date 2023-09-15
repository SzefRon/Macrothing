#include "Abort.h"

Abort &Abort::i()
{
    static Abort instance;
    return instance;
}