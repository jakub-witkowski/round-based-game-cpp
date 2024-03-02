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

void TPlayer::order_traning()
{

}

void TPlayer::move_units()
{

}

void TPlayer::attack_enemy()
{

}