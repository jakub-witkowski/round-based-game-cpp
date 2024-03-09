#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

#include "TMap.h"
#include "TUnit.h"
#include "TRound.h"

/* display the map */
std::ostream& operator<<(std::ostream& view, TMap* m)
{
    view << "Map fields: " << std::endl;
    
    for (size_t i = 0; i < m->map_size_x; i++)
    {
        for (size_t j = 0; j < m->map_size_y; j++)
        {
            view << m->map_fields[j][i] << " ";
        }

        view << std::endl;
    }

    return view;
}

/* display a unit */
std::ostream& operator<<(std::ostream& view, TUnit* u)
{
    view << "Affiliation: " << u->affiliation << " " << std::endl;
    view << "Id: " << u->id << " " << std::endl;
    view << "Type: " << u->type << " " << std::endl;
    view << "X coord: " << u->coordinates.first << ", Y coord: " << u->coordinates.second << std::endl;
    view << "Current stamina: " << u->stamina << " " << std::endl;
    view << "Speed: " << u->speed << " " << std::endl;
    view << "Cost: " << u->cost << " " << std::endl;
    view << "Attack range: " << u->attack_range << " " << std::endl;
    view << "Training time left: " << u->training_time << " " << std::endl;

    return view;
}

/* print units currently in play */
std::ostream& operator<<(std::ostream& view, std::vector<TUnit*> u)
{
    view
        << " Id:"
        << std::setw(9) << "Aff"
        << std::setw(9) << "Type"
        << std::setw(9) << "X"
        << std::setw(9) << "Y"
        << std::setw(9) << "St"
        << std::setw(9) << "Time"
        << std::setw(9) << "Busy"
        << std::endl;

    for (auto i : u)
    {
        if (i->get_is_defeated() == true)
            continue;

        view
            << " " << i->id
            << std::setw(11) << i->affiliation
            << std::setw(9) << i->type
            << std::setw(9) << i->coordinates.first
            << std::setw(9) << i->coordinates.second
            << std::setw(9) << i->stamina
            << std::setw(9) << i->training_time;
        
        if (i->type == 'B')
            view 
            << std::setw(9) << i->is_base_busy;
        
        view << std::endl;
    }

    return view;
}

/* display a player */
std::ostream& operator<<(std::ostream& view, TPlayer* p)
{
    view << "Player: " << std::endl;
    view << "Identity: " << p->identity << std::endl;
    view << "Gold: " << p->gold << std::endl;

    return view;
}

/* Play one round */
void play_round(char aff, std::string s1, std::string s2, std::string s3)
{
    /* A TRound object is created and initialized */
    std::unique_ptr<TRound> round(new TRound(aff, s1, s2, s3));
    // std::cout << "Mine coordinates: " << round->get_map_ptr()->find_mine().first << ", " << round->get_map_ptr()->find_mine().second;
    round->read_status();
    round->get_player_ptr()->mine_gold(round->get_player_ptr()->are_there_workers_at_the_mine() * 100);
    round->get_player_ptr()->order_training(s3);
    round->get_player_ptr()->move_units(s3);
    round->get_player_ptr()->attack_enemy(s3);
    round->get_player_ptr()->write_player_file();
    round->write_status();
}

#endif