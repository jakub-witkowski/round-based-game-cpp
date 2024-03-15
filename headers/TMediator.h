#ifndef TMEDIATOR_H
#define TMEDIATOR_H

#include "TUnit.h"
#include "TMap.h"

#include <vector>
#include <string>
#include <fstream>

class TMediator
{
    public:
        TMediator(int);
        ~TMediator();

        void load_status();
        void generate_status_file();
        void load_orders();
        void load_player_file(std::string);
        void write_status(std::string);
        void run(std::string);

        unsigned int get_player1_round_number();
        unsigned int get_player2_round_number();
        std::string get_player1_filename();
        std::string get_player2_filename();
        void update_round_number(std::string);
        void perform_unit_census();
        void settle_outcome();

        // void set_gold(long);
        void add_base(std::string);
        void add_unit(char, std::string);
        void add_unit(std::string);
        void update_coordinates(std::string);
        void settle_fight(std::string, size_t, size_t);
        void start_training(std::string, size_t, size_t);

        std::vector<TUnit*> units{};
        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

    private:
        TMap* map{nullptr};
        unsigned int total_number_of_rounds;
        long player1_gold_from_previous_round{};
        long player2_gold_from_previous_round{};
        // unsigned int player1_training_time_left;
        // unsigned int player2_training_time_left;
        std::string status_filename = "../status.txt";
        std::string orders_filename = "../orders.txt";
        std::string player1_filename = "../player1.txt";
        std::string player2_filename = "../player2.txt";
        unsigned int player1_round_counter{1};
        unsigned int player2_round_counter{1};
        // long previous_player_gold{};
        int player1_units{0};
        int player2_units{0};
};

#endif