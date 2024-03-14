#include "../headers/TBase.h"

TBase::TBase()
{

}

TBase::TBase(char aff, TMap* m) : TUnit()
{
    set_affiliation(aff);
    set_type('B');

    /* determine coordinates */
    if (aff == 'P')
        set_coordinates(0, 0);
    else if (aff == 'E')
        set_coordinates(m->get_map_size_x() - 1, m->get_map_size_y() - 1);
    
    /* determine id */
    if (aff == 'P')
        set_id(1);
    else if (aff == 'E')
        set_id(2);

    set_stamina(200);
    set_speed(0);
    set_cost(0);
    set_attack_range(0);
    set_training_time(0);
    set_is_base_busy('0');
    set_attack_table(0,0,0,0,0,0,0,0);
    set_as_opponent(7);
    set_is_defeated(false);
    set_training_started_in_the_present_round(false);

    update_unit_counter();

    // std::cout << "2-argument TBase constructor called" << std::endl;
}

TBase::TBase(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm,
                 char b)
{
    set_affiliation(aff);
    set_type('B');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(0);
    set_cost(0);
    set_attack_range(0);
    set_training_time(0);
    set_is_base_busy(b);
    set_attack_table(0,0,0,0,0,0,0,0);
    set_as_opponent(7);
    set_is_defeated(false);
    set_training_started_in_the_present_round(false);

    update_unit_counter();

    // std::cout << "6-argument TBase constructor called" << std::endl;
}

TBase::~TBase()
{

}
