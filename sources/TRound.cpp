#include "../headers/TRound.h"

#include <string>
#include <fstream>

TRound::TRound()
{
    // std::cout << "TRound default constructor called" << std::endl;
}

TRound::TRound(char who, std::string s1, std::string s2, std::string s3)
{
    this->which_player = who;
    this->map_ptr = new TMap(s1);
    this->status_filename = s2;
    this->orders_filename = s3;
    this->player_ptr = new TPlayer(this->which_player, 2000, this->map_ptr);
    // std::cout << "4-argument TRound constructor called" << std::endl;
}

TRound::~TRound()
{
    delete map_ptr;
    delete player_ptr;
    // std::cout << "TRound destructor called" << std::endl;
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
    std::remove(this->status_filename.c_str());
    // output.open(this->status_filename, std::ofstream::out | std::ofstream::app);
    std::ofstream output{this->status_filename};

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
            // output_line.append(std::to_string(el->get_affiliation()));
            output_line.append(" ");
            // output_line.append(std::to_string(el->get_type()));
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
                // output_line.append(std::to_string(el->get_is_base_busy()));
            }

            output_line.append("\n");

            output << output_line;
            output_line.clear();            
        }
    }

    output.close();
}

void TRound::load_player_file()
{
    std::ifstream input;
    unsigned int space_count{0};
    size_t space_pos{};
    int base_index;

    if (this->get_player_ptr()->get_identity() == 'P')
    {
        input.open("../player1.txt");
        base_index = 0;
    }
    else if (this->get_player_ptr()->get_identity() == 'E')
    {
        input.open("../player2.txt");
        base_index = 1;
    }

    for (std::string line; std::getline(input, line);)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                space_count++;
                space_pos = i;
            }
        }

        if (space_count == 1)
        {
            this->get_player_ptr()->units[base_index]->set_training_time_left(std::stoi(line.substr(space_pos)));
        }
        
        space_count = 0;
    }
}

void TRound::update_training_times()
{
    int base_index;

    if (this->get_player_ptr()->get_identity() == 'P')
    {
        base_index = 0;
    }
    else if (this->get_player_ptr()->get_identity() == 'E')
    {
        base_index = 1;
    }

    if (this->get_player_ptr()->units[base_index]->get_training_time_left() == 1)
    {
        char unit_type = this->get_player_ptr()->units[base_index]->get_is_base_busy();

        switch(unit_type)
        {
            case 'A':
                this->get_player_ptr()->units.push_back(new TArcher(this->get_player_ptr()->get_identity(), this->map_ptr));
                break;
            case 'C':
                this->get_player_ptr()->units.push_back(new TCatapult(this->get_player_ptr()->get_identity(), this->map_ptr));
                break;
            case 'K':
                this->get_player_ptr()->units.push_back(new TKnight(this->get_player_ptr()->get_identity(), this->map_ptr));
                break;
            case 'P':
                this->get_player_ptr()->units.push_back(new TPikeman(this->get_player_ptr()->get_identity(), this->map_ptr));
                break;
            case 'R':
                this->get_player_ptr()->units.push_back(new TRam(this->get_player_ptr()->get_identity(), this->map_ptr));
                break;
            case 'S':
                this->get_player_ptr()->units.push_back(new TSwordsman(this->get_player_ptr()->get_identity(), this->map_ptr));
                break;
            case 'W':
                this->get_player_ptr()->units.push_back(new TWorker(this->get_player_ptr()->get_identity(), this->map_ptr));
                break; 
        }

        this->get_player_ptr()->units[base_index]->set_training_time_left(0);
        this->get_player_ptr()->units[base_index]->set_is_base_busy('0');
    }
    else if (this->get_player_ptr()->units[base_index]->get_training_time_left() > 1)
    {
        unsigned int current_training_time_left = this->get_player_ptr()->units[base_index]->get_training_time_left();
        this->get_player_ptr()->units[base_index]->set_training_time_left(current_training_time_left - 1);
    }
}

TPlayer* TRound::get_player_ptr()
{
    return this->player_ptr;
}

TMap* TRound::get_map_ptr()
{
    return this->map_ptr;
}
