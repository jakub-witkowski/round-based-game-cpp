#ifndef TKNIGHT_H
#define TKNIGHT_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

// #include <tuple>
#include <iostream>

class TKnight : public TUnit
{
    public:
        TKnight();
        TKnight(char, TMap*);
        TKnight(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);

        ~TKnight();
};

#endif