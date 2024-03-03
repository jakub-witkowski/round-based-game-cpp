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

        std::vector<TUnit*> units{};

        friend std::ostream& operator<<(std::ostream&, TPlayer*);
        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

        void set_gold(long);
        void add_base(std::string);
        void add_unit(std::string);

    void order_training(char);
    void move_units();
    void attack_enemy();

    private:
        char identity;
        long gold{2000};
};


#endif