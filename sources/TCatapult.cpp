#include "../headers/TCatapult.h"

TCatapult::TCatapult()
{

}

TCatapult::TCatapult(char aff, TMap* m) : TUnit()
{
    set_affiliation(aff);
    set_type('C');

    /* determine coordinates */
    if (aff == 'P')
        set_coordinates(0, 0);
    else if (aff == 'E')
        set_coordinates(m->get_map_size_x() - 1, m->get_map_size_y() - 1);
        
    set_id(this->get_unit_count() + 1);
    set_stamina(50);
    set_speed(2);
    set_cost(800);
    set_attack_range(7);
    set_training_time(6);
    set_attack_table(40, 40, 40, 40, 40, 40, 40, 50);
    set_as_opponent(4);
    set_is_defeated(false);
    set_training_started_in_the_present_round(false);

    // set_map_ptr(m);
    update_unit_counter();

    // std::cout << "2-argument TCatapult constructor called" << std::endl;
}

TCatapult::TCatapult(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm)
                //  unsigned int trt)
{
    set_affiliation(aff);
    set_type('C');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(2);
    set_cost(800);
    set_attack_range(7);
    set_training_time(0);
    set_may_attack_enemy_units(true);
    set_attack_table(40, 40, 40, 40, 40, 40, 40, 50);
    set_as_opponent(4);
    set_is_defeated(false);
    set_training_started_in_the_present_round(false);

    update_unit_counter();

    // std::cout << "6-argument TCatapult constructor called" << std::endl;
}

TCatapult::~TCatapult()
{

}

int TCatapult::get_cost()
{
    return this->cost;
}