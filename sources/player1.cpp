#include "../headers/TArcher.h"
#include "../headers/TKnight.h"
#include "../headers/TMap.h"
#include "../headers/TPlayer.h"
#include "../headers/TRound.h"
#include "../headers/TUnit.h"

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
        /* A round object is created and initialized */
        std::unique_ptr<TRound> round(new TRound('P', argv[1], argv[2], argv[3]));
        
        TArcher* u = new TArcher('P', round->get_map_ptr());
        TArcher* u1 = new TArcher('E', round->get_map_ptr());

        // std::cout << round->get_player_ptr();
        std::cout << u;

        std::cout << u1;

        delete u;
        delete u1;
    }
    
    return 0;
}