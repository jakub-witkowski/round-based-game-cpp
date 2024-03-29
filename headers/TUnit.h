#ifndef UNIT_H
#define UNIT_H

#include "TMap.h"

#include <iostream>
#include <vector>

class TUnit
{   
    public:
        TUnit();
        ~TUnit();

        friend std::ostream& operator<<(std::ostream&, TUnit*);
        friend std::ostream& operator<<(std::ostream&, std::vector<TUnit*>);

        // friend int TPlayer::cast_dice(int,int);

        void set_affiliation(char);
        void set_type(char);
        void set_coordinates(unsigned int, unsigned int);
        void set_id(unsigned int);
        void set_stamina(int);
        void set_speed(unsigned int);
        void set_cost(unsigned int);
        void set_attack_range(unsigned int);
        void set_training_time(unsigned int);
        void set_is_base_busy(char);
        void set_map_ptr(TMap*);
        void set_may_attack_enemy_units(bool);

        void update_remaining_movement_points(int);
        void update_unit_counter();

        unsigned int get_unit_count();
        unsigned int get_cost();
        char get_type();
        unsigned int get_training_time();
        unsigned int get_remaining_movement_points();
        char get_affiliation();
        std::pair<unsigned int, unsigned int> get_coordinates();
        TMap* get_map_ptr();
        unsigned int get_id();
        bool get_may_attack_enemy_units();
        unsigned int get_attack_range();
        char get_is_base_busy();
        int get_stamina();
        void set_attack_table(int, int, int, int, int, int, int, int);
        void set_as_opponent(int);
        int get_attack_table(int);
        int get_as_opponent();
        void set_is_defeated(bool);
        bool get_is_defeated();
        void set_training_time_left(unsigned int);
        unsigned int get_training_time_left();
        void set_training_started_in_the_present_round(bool);
        bool get_training_started_in_the_present_round();   

    protected:
        inline static unsigned int unit_counter;

        char affiliation;
        char type;
        std::pair<unsigned int,unsigned int> coordinates;
        unsigned int id;
        int stamina;
        unsigned int speed;
        unsigned int cost;
        unsigned int attack_range;
        unsigned int training_time;
        char is_base_busy;
        bool may_attack_enemy_units;
        TMap* map_ptr;
        bool is_defeated;

        int attack_table[8];
        int as_opponent;
        unsigned int training_time_left;
        bool training_started_in_the_present_round{false};
};

#endif