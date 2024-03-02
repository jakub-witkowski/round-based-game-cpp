#ifndef ARCHER_H
#define ARCHER_H

#include "../headers/TUnit.h"

// #include <tuple>
#include <iostream>

class TArcher : public TUnit
{
    public:
        TArcher();
        TArcher(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
        ~TArcher();
};

#endif