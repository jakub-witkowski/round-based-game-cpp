#ifndef TARCHER_H
#define TARCHER_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

// #include <tuple>
#include <iostream>

class TArcher : public TUnit
{
    public:
        TArcher();
        TArcher(char, TMap*);
        TArcher(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
                
        ~TArcher();
};

#endif