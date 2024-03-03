#ifndef TSWORDSMAN_H
#define TSWORDSMAN_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TSwordsman : public TUnit
{
    public:
        TSwordsman();
        TSwordsman(char, TMap*);
        TSwordsman(char,
                   unsigned int,
                   unsigned int,
                   unsigned int,
                   unsigned int,
                   unsigned int);
                
        ~TSwordsman();
};

#endif