#include "../headers/TKnight.h"

TKnight::TKnight()
{
    set_affiliation('P');
    set_type('K');
    set_coordinates(0,0);
    set_id(0);
    set_stamina(70);
    set_speed(5);
    set_cost(400);
    set_attack_range(1);
    set_training_time(5);

    std::cout << "Default constructor called" << std::endl;
}

TKnight::TKnight(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm)
{
    set_affiliation(aff);
    set_type('K');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(5);
    set_cost(400);
    set_attack_range(1);
    set_training_time(5);

    std::cout << "5-argument constructor called" << std::endl;
}

TKnight::~TKnight()
{

}
