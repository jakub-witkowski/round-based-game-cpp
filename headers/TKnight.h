#ifndef KNIGHT_H
#define KNIGHT_H

#include "../headers/TUnit.h"

// #include <tuple>
#include <iostream>

class TKnight : public TUnit
{
    public:
        TKnight();
        TKnight(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
        ~TKnight();
};

#endif