#ifndef TKNIGHT_H
#define TKNIGHT_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TKnight : public TUnit
{
    public:
        TKnight();
        TKnight(char, TMap*);
        TKnight(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
                // unsigned int);

        ~TKnight();

        int get_cost();

        // private:
        //         int attack_table[8] = { 35, 35, 35, 35, 35, 35, 35, 35 };
        //         int as_opponent{0};
};

#endif