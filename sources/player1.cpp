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
        /* A round object is created and initialized */
        std::unique_ptr<TRound> round(new TRound('P', argv[1], argv[2], argv[3]));
        
        round->read_status();
        std::cout << round->get_player_ptr();
        std::cout << round->get_player_ptr()->units;

        /*TUnit* u = new TArcher('P', round->get_map_ptr());
        TUnit* u1 = new TKnight('E', round->get_map_ptr());
        TUnit* u2 = new TSwordsman('P', round->get_map_ptr());

        std::cout << u;
        std::cout << u1;
        std::cout << u2;

        delete u;
        delete u1;
        delete u2;*/
    }
    
    return 0;
}