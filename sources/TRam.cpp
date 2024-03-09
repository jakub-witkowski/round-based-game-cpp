#include "../headers/TRam.h"

TRam::TRam()
{

}

TRam::TRam(char aff, TMap* m) : TUnit()
{
    set_affiliation(aff);
    set_type('R');

    /* determine coordinates */
    if (aff == 'P')
        set_coordinates(0, 0);
    else if (aff == 'E')
        set_coordinates(m->get_map_size_x() - 1, m->get_map_size_y() - 1);
    
    set_id(this->get_unit_count() + 1);
    set_stamina(90);
    set_speed(2);
    set_cost(500);
    set_attack_range(1);
    set_training_time(4);
    set_attack_table(10, 10, 10, 10, 10, 10, 10, 50);
    set_as_opponent(5);
    set_is_defeated(false);

    // set_map_ptr(m);
    update_unit_counter();

    // std::cout << "2-argument TRam constructor called" << std::endl;
}

TRam::TRam(char aff,
                 unsigned int x,
                 unsigned int y,
                 unsigned int id,
                 unsigned int stm)
                //  unsigned int trt)
{
    set_affiliation(aff);
    set_type('R');
    set_coordinates(x,y);
    set_id(id);
    set_stamina(stm);
    set_speed(2);
    set_cost(500);
    set_attack_range(1);
    set_training_time(0);
    set_may_attack_enemy_units(true);
    set_attack_table(10, 10, 10, 10, 10, 10, 10, 50);
    set_as_opponent(5);
    set_is_defeated(false);

    update_unit_counter();

    // std::cout << "6-argument TRam constructor called" << std::endl;
}

TRam::~TRam()
{

}

int TRam::get_cost()
{
    return this->cost;
}