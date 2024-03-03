#ifndef TRAM_H
#define TRAM_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TRam : public TUnit
{
    public:
        TRam();
        TRam(char, TMap*);
        TRam(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
                
        ~TRam();
};

#endif