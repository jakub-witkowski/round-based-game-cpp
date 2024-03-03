#include "../headers/TRound.h"

#include <string>
#include <fstream>

TRound::TRound()
{
    std::cout << "TRound default constructor called" << std::endl;
}

TRound::TRound(char who, std::string s1, std::string s2, std::string s3)
{
    this->which_player = who;
    this->map_ptr = new TMap(s1);
    this->status_filename = s2;
    this->orders_filename = s3;
    this->player_ptr = new TPlayer(this->which_player, 2000);
    std::cout << "4-argument TRound constructor called" << std::endl;
}

TRound::~TRound()
{
    delete map_ptr;
    delete player_ptr;
    std::cout << "TRound destructor called" << std::endl;
}

void TRound::read_status()
{
    std::ifstream input{status_filename};
    unsigned int space_count{0};

    for (std::string line; std::getline(input, line);)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
                space_count++;
        }

        if (space_count == 0)
        {
            this->player_ptr->set_gold(std::stol(line));
        }
        else if (space_count == 6)
        {
            this->player_ptr->add_base(line);
        }
        else if (space_count == 5)
        {
            this->player_ptr->add_unit(line);
        }

        space_count = 0;
    }
}

void TRound::write_orders()
{
    
}

TPlayer* TRound::get_player_ptr()
{
    return this->player_ptr;
}

TMap* TRound::get_map_ptr()
{
    return this->map_ptr;
}
