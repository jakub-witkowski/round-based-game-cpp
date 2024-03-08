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
                unsigned int);
                // unsigned int);
                
        ~TPikeman();

        int get_cost();

        // private:
        //         int attack_table[8] = { 35, 15, 15, 15, 15, 10, 15, 10 };
        //         int as_opponent = 3;
};

#endif