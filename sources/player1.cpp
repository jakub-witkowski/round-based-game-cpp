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
        std::cout << "No filename given!" << std::endl;
    else
    {
        /* A round object is created and initialized */
        std::unique_ptr<TRound> round(new TRound('P', argv[1], argv[2], argv[3]));

        std::cout << round->get_player_ptr();
    }
    
    return 0;
}