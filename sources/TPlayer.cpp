#include "../headers/TPlayer.h"

TPlayer::TPlayer()
{
    std::cout << "TPlayer default constructor called" << std::endl;
}

TPlayer::TPlayer(char id, long g, TMap* m) : identity(id), gold(g), map_ptr(m)
{
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

void TPlayer::add_base(std::string line, TMap* m)
{
    size_t space_pos[6]{0,0,0,0,0,0};
    int pos = 0;

    char aff;
    unsigned int id;
    unsigned int x;
    unsigned int y;
    unsigned int stamina;
    char busy;

    for (size_t i = 0; i < line.size(); i++)
    {    
        while (pos < 6)
        {
            if (line[i] == ' ')
                space_pos[pos] = i;

            pos++;
        }
    }

    this->units.push_back(new TUnit()); // modify 
}

void TPlayer::add_unit(std::string line, TMap* m)
{
    this->units.push_back(new TUnit()); // modify
}

TMap* TPlayer::get_map_ptr()
{
    return this->map_ptr;
}