#ifndef ROUND_H
#define ROUND_H

#include "TMap.h"
#include "TPlayer.h"

class TRound
{
    public:
        TRound();
        TRound(char, std::string, std::string, std::string);
        ~TRound();

        void read_status();
        void write_status();

        TPlayer* get_player_ptr();
        TMap* get_map_ptr();
        // char get_which_player();

        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

    private:
        char which_player;
        std::string status_filename;
        std::string orders_filename;
        TMap* map_ptr{nullptr};
        TPlayer* player_ptr{nullptr};
};

#endif