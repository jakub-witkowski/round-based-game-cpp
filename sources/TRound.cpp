#include "../headers/TRound.h"
#include <string>

TRound::TRound(char who, std::string s)
{
    this->which_player = who;
    this->map_ptr = new TMap(s);
    this->player_ptr = new TPlayer(this->which_player, 2000);
    std::cout << "TRound constructor called" << std::endl;
}

TRound::~TRound()
{
    delete map_ptr;
    delete player_ptr;
    std::cout << "TRound destructor called" << std::endl;
}

void TRound::read_status()
{

}

void TRound::write_orders()
{
    
}

TPlayer* TRound::get_player_ptr()
{
    return this->player_ptr;
}