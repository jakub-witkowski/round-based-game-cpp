#ifndef TPIKEMAN_H
#define TPIKEMAN_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TPikeman : public TUnit
{
    public:
        TPikeman();
        TPikeman(char, TMap*);
        TPikeman(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
                
        ~TPikeman();
};

#endif