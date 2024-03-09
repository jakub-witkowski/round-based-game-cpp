#include "../headers/TArcher.h"

TArcher::TArcher()
{

}

TArcher::TArcher(char aff, TMap* m) : TUnit()
{
    set_affiliation(aff);
    set_type('A');

    /* determine coordinates */
    if (aff == 'P')
        set_coordinates(0, 0);
    else if (aff == 'E')
        set_coordinates(m->get_map_size_x() - 1, m->get_map_size_y() - 1);
    
    set_id(this->get_unit_count() + 1);
    set_stamina(40);
    set_speed(2);
    set_cost(250);
    set_attack_range(5);
    set_training_time(3);
    set_attack_table(15, 15, 15, 15, 10, 10, 15, 15);
    set_as_opponent(2);
    set_is_defeated(false);

    update_unit_counter();
    
    // std::cout << "2-argument TArcher constructor called" << std::endl;
}

TArcher::TArcher(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm)
                //  unsigned int trt)
{
    set_affiliation(aff);
    set_type('A');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(2);
    set_cost(250);
    set_attack_range(5);
    set_training_time(0);
    set_may_attack_enemy_units(true);
    set_attack_table(15, 15, 15, 15, 10, 10, 15, 15);
    set_as_opponent(2);
    set_is_defeated(false);

    update_unit_counter();

    // std::cout << "6-argument TArcher constructor called" << std::endl;
}

TArcher::~TArcher()
{

}

int TArcher::get_cost()
{
    return this->cost;
}