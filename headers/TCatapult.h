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

        int get_cost();

        // private:
        //         int attack_table[8] = { 40, 40, 40, 40, 40, 40, 40, 50 };
        //         int as_opponent = 4;
};

#endif