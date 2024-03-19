#include "../headers/TMediator.h"

#include "../headers/functions.h"

std::string bar(58, '=');

int main(int argc, char** argv)
{
    unsigned int max_round_number;
    
    if (!argv[1])
    {
        max_round_number = 6;
        std::cout << "No number of rounds passed as parameter; default set at 6 (3 rounds each)." << std::endl;
    }
    else
    {
        max_round_number = std::stoi(argv[1]);
    
        if ((max_round_number % 2) != 0)
            max_round_number++;
    }

    std::cout << std::endl << "Playing " << max_round_number / 2 << " rounds each." << std::endl;

    TMediator arbiter = TMediator(max_round_number);

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
        arbiter.load_orders();
        arbiter.load_player_file("player1");
        arbiter.write_status("player1");
        arbiter.update_round_number("player1");

        std::cout << std::endl << bar << std::endl << std::endl;

        arbiter.run("player2");

        arbiter.load_status();
        arbiter.load_orders();
        arbiter.load_player_file("player2");
        arbiter.write_status("player2");
        arbiter.update_round_number("player2");
    }

    std::cout << std::endl << bar << std::endl << std::endl;
    arbiter.settle_outcome();

    return 0;
}