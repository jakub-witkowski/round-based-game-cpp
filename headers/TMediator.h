#ifndef TMEDIATOR_H
#define TMEDIATOR_H

#include "TUnit.h"

#include <vector>
#include <string>
#include <fstream>

class TMediator
{
    public:
        TMediator();
        ~TMediator();

        void load_status();
        void load_orders();
        void load_player_file();
        void write_status();
        void run(std::string);

        unsigned int get_player1_round_number();
        unsigned int get_player2_round_number();
        void update_round_number(std::string);

        void set_gold(long);
        void add_base(std::string);
        void add_unit(std::string);
        void update_coordinates(std::string);
        void settle_fight(std::string, size_t, size_t);

        std::vector<TUnit*> units{};
        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

    private:
        long gold{};
        std::string status_filename = "../status.txt";
        std::string orders_filename = "../orders.txt";
        std::string player1_filename = "../player1.txt";
        std::string player2_filename = "../player2.txt";
        unsigned int player1_round_counter{1};
        unsigned int player2_round_counter{1};
        // std::vector<TUnit*> units{};
        // std::vector<std::string> status{};
        // std::vector<std::string> orders{};
        // std::vector<std::string> player_file{};
};

#endif