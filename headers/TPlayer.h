#ifndef PLAYER_H
#define PLAYER_H

#include "TArcher.h"
#include "TBase.h"
#include "TCatapult.h"
#include "TKnight.h"
#include "TPikeman.h"
#include "TRam.h"
#include "TSwordsman.h"
#include "TUnit.h"
#include "TWorker.h"
#include "TMap.h"

#include <random>
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
        void set_base_busy(char, char);
        // TPlayer* get_player_ptr();

        int cast_dice(int, int);
        void order_training();
        void update_gold(int);
        void move_units();
        void order_move(TUnit*);
        bool is_map_field_occupied(char, unsigned int, unsigned int);
        void attack_enemy();

    private:
        char identity;
        long gold{2000};
        TMap* map_ptr{nullptr};
        // TBase* base_ptr{nullptr};
        // TPlayer* player_ptr{&*this};
};


#endif