#include "../headers/TKnight.h"

TKnight::TKnight()
{

}

TKnight::TKnight(char aff, TMap* m)
{
    set_affiliation(aff);
    set_type('K');

    /* determine coordinates */
    if (aff == 'P')
        set_coordinates(0, 0);
    else if (aff == 'E')
        set_coordinates(m->get_map_size_x() - 1, m->get_map_size_y() - 1);
    
    set_id(this->get_unit_count() + 1);
    set_stamina(70);
    set_speed(5);
    set_cost(400);
    set_attack_range(1);
    set_training_time(5);
    set_attack_table(35, 35, 35, 35, 35, 35, 35, 35);
    set_as_opponent(0);

    // set_map_ptr(m);
    update_unit_counter();

    // std::cout << "2-argument TKnight constructor called" << std::endl;
}

TKnight::TKnight(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm)
                //  unsigned int trt)
{
    set_affiliation(aff);
    set_type('K');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(5);
    set_cost(400);
    set_attack_range(1);
    set_training_time(0);
    set_may_attack_enemy_units(true);
    set_attack_table(35, 35, 35, 35, 35, 35, 35, 35);
    set_as_opponent(0);

    update_unit_counter();

    // std::cout << "6-argument TKnight constructor called" << std::endl;
}

TKnight::~TKnight()
{

}

int TKnight::get_cost()
{
    return this->cost;
}