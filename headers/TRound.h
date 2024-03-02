#ifndef ROUND_H
#define ROUND_H

#include "TMap.h"
#include "TPlayer.h"

class TRound
{
    public:
        TRound(char, std::string);
        ~TRound();

        void read_status();
        void write_orders();
        TPlayer* get_player_ptr();

    private:
        char which_player;
        TMap* map_ptr{nullptr};
        TPlayer* player_ptr{nullptr};
};

#endif