#include "../headers/TMediator.h"

#include "../headers/functions.h"

std::string bar(50, '=');

int main(int argc, char** argv)
{
    unsigned int max_round_number;
    
    if (!argv[1])
        max_round_number = 6;
    else
    {
        max_round_number = std::stoi(argv[1]);
    
        if ((max_round_number % 2) != 0)
            max_round_number++;
    }

    TMediator arbiter = TMediator();

    /* CLEAR PLAYER AND STATUS FILES */
    std::remove(arbiter.get_player1_filename().c_str());
    std::remove(arbiter.get_player2_filename().c_str());
    std::remove("../status.txt");
    arbiter.generate_status_file();

    /* Main loop */
    while ((arbiter.get_player1_round_number() + arbiter.get_player2_round_number()) <= max_round_number)
    {
        std::cout << std::endl << bar << std::endl << std::endl;

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

        std::cout << std::endl << bar << std::endl << std::endl;

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