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
                   unsigned int);
                //    unsigned int);
                
        ~TSwordsman();

        int get_cost();

    // private:
    //     int attack_table[8] = { 30, 30, 30, 20, 20, 30, 30, 30 };
    //     int as_opponent = 1;
};

#endif