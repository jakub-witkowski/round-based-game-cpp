#ifndef TCATAPULT_H
#define TCATAPULT_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TCatapult : public TUnit
{
    public:
        TCatapult();
        TCatapult(char, TMap*);
        TCatapult(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
                // unsigned int);
                
        ~TCatapult();
};

#endif