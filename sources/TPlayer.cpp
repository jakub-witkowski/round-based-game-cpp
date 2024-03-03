#include "../headers/TPlayer.h"

TPlayer::TPlayer()
{
    std::cout << "TPlayer default constructor called" << std::endl;
}

TPlayer::TPlayer(char id, long g)
{
    this->identity = id;
    this->gold = g;
    std::cout << "TPlayer constructor called" << std::endl;
}

TPlayer::~TPlayer()
{
    if (this->units.size() > 0)
    {
        for (size_t i = 0; i < units.size(); i++)
        {
            delete units[i];
        }
    }
    std::cout << "TPlayer destructor called" << std::endl;
}

void TPlayer::order_training(char aff)
{

}

void TPlayer::move_units()
{

}

void TPlayer::attack_enemy()
{

}

void TPlayer::set_gold(long g)
{
    this->gold = g;
}

void TPlayer::add_base(std::string line)
{
    this->units.push_back(new TUnit()); // modify 
}

void TPlayer::add_unit(std::string line)
{
    this->units.push_back(new TUnit()); // modify
}