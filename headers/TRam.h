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
                unsigned int);
                // unsigned int);
                
        ~TRam();

        int get_cost();

        // private:
        //         int attack_table[8] = { 10, 10, 10, 10, 10, 10, 10, 50 };
        //         int as_opponent = 5;
};

#endif