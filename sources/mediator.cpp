#include "../headers/TMediator.h"

#include "../headers/functions.h"

const unsigned int max_round_number{20};

int main()
{
    TMediator arbiter = TMediator();

    while ((arbiter.get_player1_round_number() + arbiter.get_player2_round_number()) <= max_round_number)
    {
        arbiter.run("player1");

        arbiter.load_status();
        // std::cout << "From within mediator: status loaded " << std::endl;
        // std::cout << arbiter.units;
        arbiter.load_orders();
        // std::cout << "From within mediator: orders loaded " << std::endl;
        // std::cout << arbiter.units;
        arbiter.load_player_file("player1");
        // std::cout << "From within mediator: player file loaded" << std::endl;
        // std::cout << arbiter.units;
        arbiter.write_status("player1");
        arbiter.update_round_number("player1");

        arbiter.run("player2");

        arbiter.load_status();
        // std::cout << "From within mediator: status loaded " << std::endl;
        arbiter.load_orders();
        // std::cout << "From within mediator: orders loaded " << std::endl;
        arbiter.load_player_file("player2");
        // std::cout << "From within mediator: player file loaded" << std::endl;
        // std::cout << arbiter.units;
        arbiter.write_status("player2");
        arbiter.update_round_number("player2");
    }

    return 0;
}