#include "../headers/TUnit.h"

TUnit::TUnit()
{
    std::cout << "TUnit() called" << std::endl;
}

TUnit::~TUnit()
{
    std::cout << "~TUnit() called" << std::endl;
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