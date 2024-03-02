#include "../headers/TRound.h"

#include <string>
#include <fstream>

TRound::TRound(char who, std::string s1, std::string s2, std::string s3)
{
    this->which_player = who;
    this->map_ptr = new TMap(s1);
    this->status_filename = s2;
    this->orders_filename = s3;
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

TMap* TRound::get_map_ptr()
{
    return this->map_ptr;
}
