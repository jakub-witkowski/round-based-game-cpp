#ifndef PLAYER_H
#define PLAYER_H

#include "TBase.h"
#include "TUnit.h"
#include "TMap.h"
#include <vector>
#include <iostream>

class TPlayer
{
    public:
        TPlayer();
        TPlayer(char, long, TMap*);
        ~TPlayer();

        std::vector<TUnit*> units{};

        friend std::ostream& operator<<(std::ostream&, TPlayer*);
        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

        void set_gold(long);
        void add_base(std::string, TMap*);
        void add_unit(std::string, TMap*);
        TMap* get_map_ptr();

    void order_training(char);
    void move_units();
    void attack_enemy();

    private:
        char identity;
        long gold{2000};
        TMap* map_ptr{nullptr};
};


#endif