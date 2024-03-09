#include "../headers/TPikeman.h"

TPikeman::TPikeman()
{

}

TPikeman::TPikeman(char aff, TMap* m) : TUnit()
{
    set_affiliation(aff);
    set_type('P');
    
    /* determine coordinates */
    if (aff == 'P')
        set_coordinates(0, 0);
    else if (aff == 'E')
        set_coordinates(m->get_map_size_x() - 1, m->get_map_size_y() - 1);
    
    set_id(this->get_unit_count() + 1);
    set_stamina(50);
    set_speed(2);
    set_cost(200);
    set_attack_range(2);
    set_training_time(3);
    set_attack_table(35, 15, 15, 15, 15, 10, 15, 10);
    set_as_opponent(3);
    set_is_defeated(false);

    // set_map_ptr(m);
    update_unit_counter();

    // std::cout << "2-argument TPikeman constructor called" << std::endl;
}

TPikeman::TPikeman(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm)
                //  unsigned int trt)
{
    set_affiliation(aff);
    set_type('P');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(2);
    set_cost(200);
    set_attack_range(2);
    set_training_time(0);
    set_may_attack_enemy_units(true);
    set_attack_table(35, 15, 15, 15, 15, 10, 15, 10);
    set_as_opponent(3);
    set_is_defeated(false);

    update_unit_counter();

    // std::cout << "6-argument TPikeman constructor called" << std::endl;
}

TPikeman::~TPikeman()
{

}

int TPikeman::get_cost()
{
    return this->cost;
}