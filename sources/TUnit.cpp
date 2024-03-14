#include "../headers/TUnit.h"

TUnit::TUnit()
{
    // std::cout << "TUnit() called" << std::endl;
}

TUnit::~TUnit()
{
    // std::cout << "~TUnit() called" << std::endl;
}

void TUnit::set_affiliation(char c)
{
    this->affiliation = c;
}

void TUnit::set_type( char c)
{
    this->type = c;
}

void TUnit::set_coordinates(unsigned int x, unsigned int y)
{
    this->coordinates.first = x;
    this->coordinates.second = y;
}

void TUnit::set_id(unsigned int id)
{
    this->id = id;
}

void TUnit::set_stamina(unsigned int st)
{
    this->stamina = st;
}

void TUnit::set_speed(unsigned int sp)
{
    this->speed = sp;
}

void TUnit::set_cost(unsigned int c)
{
    this->cost = c;
}

void TUnit::set_attack_range(unsigned int ar)
{
    this->attack_range = ar;
}

void TUnit::set_training_time(unsigned int trt)
{
    this->training_time = trt;
}

void TUnit::set_is_base_busy(char b)
{
    this->is_base_busy = b;
}

void TUnit::set_map_ptr(TMap* m)
{
    this->map_ptr = m;
}

void TUnit::set_may_attack_enemy_units(bool m)
{
    this->may_attack_enemy_units = m;
}

void TUnit::update_remaining_movement_points(int m)
{
    unsigned int new_speed = this->get_remaining_movement_points() - m;
    this->set_speed(new_speed);
}

void TUnit::update_unit_counter()
{
    unit_counter++;
}

unsigned int TUnit::get_unit_count()
{
    return unit_counter;
}

unsigned int TUnit::get_cost()
{
    return this->cost;
}

char TUnit::get_type()
{
    return this->type;
}

unsigned int TUnit::get_training_time()
{
    return this->training_time;
}

unsigned int TUnit::get_remaining_movement_points()
{
    return this->speed;
}

char TUnit::get_affiliation()
{
    return this->affiliation;
}

std::pair<unsigned int, unsigned int> TUnit::get_coordinates()
{
    return this->coordinates;
}

TMap* TUnit::get_map_ptr()
{
    return this->map_ptr;
}

unsigned int TUnit::get_id()
{
    return this->id;
}

bool TUnit::get_may_attack_enemy_units()
{
    return this->may_attack_enemy_units;
}

unsigned int TUnit::get_attack_range()
{
    return this->attack_range;
}

char TUnit::get_is_base_busy()
{
    return this->is_base_busy;
}

unsigned int TUnit::get_stamina()
{
    return this->stamina;
}

void TUnit::set_attack_table(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    this->attack_table[0] = a1;
    this->attack_table[1] = a2;
    this->attack_table[2] = a3;
    this->attack_table[3] = a4;
    this->attack_table[4] = a5;
    this->attack_table[5] = a6;
    this->attack_table[6] = a7;
    this->attack_table[7] = a8;
}

void TUnit::set_as_opponent(int op)
{
    this->as_opponent = op;
}

int TUnit::get_attack_table(int v)
{
    return this->attack_table[v];
}

int TUnit::get_as_opponent()
{
    return this->as_opponent;
}

void TUnit::set_is_defeated(bool def)
{
    this->is_defeated = def;
}

bool TUnit::get_is_defeated()
{
    return this->is_defeated;
}

void TUnit::set_training_time_left(unsigned int t)
{
    this->training_time_left = t;
}

unsigned int TUnit::get_training_time_left()
{
    return this->training_time_left;
}