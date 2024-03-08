#ifndef TARCHER_H
#define TARCHER_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

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
                unsigned int);
                // unsigned int);
                
        ~TArcher();

        int get_cost();

        // private:
        //         int attack_table[8] = { 15, 15, 15, 15, 10, 10, 15, 15 };
        //         int as_opponent = 2;
};

#endif