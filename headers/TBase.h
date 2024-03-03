#ifndef TBASE_H
#define TBASE_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TBase : public TUnit
{
    public:
        TBase();
        TBase(char, TMap*);
        TBase(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int,
                bool);

        ~TBase();
};

#endif