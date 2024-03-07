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
        TPlayer(char, TMap*);
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
        void order_training(std::string);
        void update_gold(int);
        void mine_gold(unsigned int);
        long get_gold();
        void move_units(std::string);
        void order_move(TUnit*, std::string);
        bool is_map_field_occupied(char, unsigned int, unsigned int);
        unsigned int are_there_workers_at_the_mine();
        void attack_enemy(std::string);
        void order_attack(TUnit*, std::string);
        void write_player_file();

    private:
        char identity;
        long gold{2000};
        TMap* map_ptr{nullptr};
        // TBase* base_ptr{nullptr};
        // TPlayer* player_ptr{&*this};
};


#endif