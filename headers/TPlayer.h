#ifndef PLAYER_H
#define PLAYER_H

#include "TUnit.h"
#include <vector>
#include <iostream>

class TPlayer
{
    public:
        TPlayer();
        TPlayer(char, long);
        ~TPlayer();

        friend std::ostream& operator<<(std::ostream&, TPlayer*);

    void order_traning(char);
    void move_units();
    void attack_enemy();

    private:
        char identity;
        long gold{2000};
        std::vector<TUnit*> units{};
};


#endif