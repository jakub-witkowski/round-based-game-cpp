#include "../headers/TArcher.h"
#include "../headers/TBase.h"
#include "../headers/TCatapult.h"
#include "../headers/TKnight.h"
#include "../headers/TMap.h"
#include "../headers/TPikeman.h"
#include "../headers/TPlayer.h"
#include "../headers/TRam.h"
#include "../headers/TRound.h"
#include "../headers/TSwordsman.h"
#include "../headers/TUnit.h"
#include "../headers/TWorker.h"

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

        round->get_player_ptr()->order_training();

        std::cout << round->get_player_ptr()->units;
        std::cout << round->get_player_ptr();
    }
    
    return 0;
}