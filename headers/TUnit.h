#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <vector>

class TUnit
{   
    public:
        TUnit();
        ~TUnit();

        friend std::ostream& operator<<(std::ostream&, TUnit*);
        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

        void set_affiliation(char);
        void set_type(char);
        void set_coordinates(unsigned int, unsigned int);
        void set_id(unsigned int);
        void set_stamina(unsigned int);
        void set_speed(unsigned int);
        void set_cost(unsigned int);
        void set_attack_range(unsigned int);
        void set_training_time(unsigned int);
        void set_is_base_busy(bool);
        void update_unit_counter();
        unsigned int get_unit_count();

    protected:
        inline static unsigned int unit_counter;

        char affiliation;
        char type;
        std::pair<unsigned int,unsigned int> coordinates;
        unsigned int id;
        unsigned int stamina;
        unsigned int speed;
        unsigned int cost;
        unsigned int attack_range;
        unsigned int training_time;
        bool is_base_busy;
};

#endif