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

void TUnit::update_unit_counter()
{
    unit_counter++;
}

unsigned int TUnit::get_unit_count()
{
    return unit_counter;
}