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
    this->player_ptr = new TPlayer(this->which_player, 2000, this->map_ptr);
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
            this->player_ptr->add_base(line, this->player_ptr->get_map_ptr());
        }
        else if (space_count == 5)
        {
            this->player_ptr->add_unit(line, this->player_ptr->get_map_ptr());
        }

        space_count = 0;
    }
}

void TRound::write_status()
{
    std::ofstream output;
    std::remove(this->status_filename.c_str());
    output.open(this->status_filename, std::ofstream::out | std::ofstream::app);

    std::string output_line;

    if (output.is_open())
    {
        output_line.append(std::to_string(this->player_ptr->get_gold()));
        output_line.append("\n");

        output << output_line;
        output_line.clear();

        for (auto el : this->player_ptr->units)
        {
            output_line += el->get_affiliation();
            output_line.append(" ");
            output_line += el->get_type();
            output_line.append(" ");
            output_line.append(std::to_string(el->get_id()));
            output_line.append(" ");
            output_line.append(std::to_string(el->get_coordinates().first));
            output_line.append(" ");
            output_line.append(std::to_string(el->get_coordinates().second));
            output_line.append(" ");
            output_line.append(std::to_string(el->get_stamina()));

            if (el->get_type() == 'B')
            {
                output_line.append(" ");
                output_line += el->get_is_base_busy();
            }

            output_line.append("\n");

            output << output_line;
            output_line.clear();            
        }
    }

    output.close();
}

TPlayer* TRound::get_player_ptr()
{
    return this->player_ptr;
}

TMap* TRound::get_map_ptr()
{
    return this->map_ptr;
}
