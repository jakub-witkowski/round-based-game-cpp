#include "../headers/TRound.h"

#include "../headers/functions.h"

#include <string>
#include <memory>
#include <iostream>

int main(int argc, char** argv)
{
    if (!argv[1])
        std::cout << "No map filename given!" << std::endl;
    else if (!argv[2])
        std::cout << "No status filename given!" << std::endl;
    else if (!argv[3])
        std::cout << "No order filename given!" << std::endl;
    else
    {
        /* A TRound object is created and initialized */
        std::unique_ptr<TRound> round(new TRound('P', argv[1], argv[2], argv[3]));
        
        round->read_status();
        round->get_player_ptr()->order_training(argv[3]);
        round->get_player_ptr()->move_units();
        // std::cout << round->get_player_ptr()->units;
        // std::cout << round->get_player_ptr()->get_map_ptr();
        // std::cout << round->get_player_ptr();
    }
    
    return 0;
}