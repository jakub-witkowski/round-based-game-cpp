#include "../headers/TMediator.h"

#include "../headers/functions.h"

const unsigned int max_round_number{6};

int main()
{
    TMediator arbiter = TMediator();

    while ((arbiter.get_player1_round_number() + arbiter.get_player2_round_number()) <= max_round_number)
    {
        arbiter.run("player1");

        arbiter.load_status();
        arbiter.load_orders();
        // arbiter.load_player_file();
        // std::cout << arbiter.units;
        // arbiter.write_status();
        arbiter.update_round_number("player1");

        arbiter.run("player2");

        arbiter.load_status();
        arbiter.load_orders();
        // arbiter.load_player_file();
        // arbiter.write_status();
        arbiter.update_round_number("player2");
    }

    return 0;
}