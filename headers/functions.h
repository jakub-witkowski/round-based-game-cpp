#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include "TMap.h"
#include "TUnit.h"

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
        << std::setw(9) << "X, Y"
        << std::setw(9) << "St"
        << std::setw(9) << "Time"
        << std::setw(9) << "Busy"
        << std::endl;

    for (auto i : u)
    {
        view
            << " " << i->id
            << std::setw(9) << i->affiliation
            << std::setw(9) << i->type
            << std::setw(3) << i->coordinates.first << ", " << i->coordinates.second
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

#endif