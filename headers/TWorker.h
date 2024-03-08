#ifndef TWORKER_H
#define TWORKER_H

#include "../headers/TUnit.h"
#include "../headers/TMap.h"

#include <iostream>

class TWorker : public TUnit
{
    public:
        TWorker();
        TWorker(char, TMap*);
        TWorker(char,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int);
                // unsigned int);
                
        ~TWorker();

        int get_cost();

        // private:
        //         int attack_table[8] = { 5, 5, 5, 5, 5, 5, 5, 1 };
        //         int as_opponent = 6;
};

#endif