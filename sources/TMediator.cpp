#include "../headers/TMediator.h"
#include "../headers/TArcher.h"
#include "../headers/TBase.h"
#include "../headers/TCatapult.h"
#include "../headers/TKnight.h"
#include "../headers/TPikeman.h"
#include "../headers/TRam.h"
#include "../headers/TSwordsman.h"
#include "../headers/TWorker.h"

TMediator::TMediator(int rounds) : total_number_of_rounds(rounds)
{
    this->map = new TMap("../map.txt");
}

TMediator::~TMediator()
{
    delete map;

    if (this->units.size() > 0)
    {
        for (size_t i = 0; i < units.size(); i++)
        {
            delete units[i];
        }
    }
}

void TMediator::load_status()
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
            // this->set_gold(std::stol(line));
            continue;
        }
        else if (space_count == 6)
        {
            this->add_base(line);
        }
        else if (space_count == 5)
        {
            this->add_unit(line);
        }

        space_count = 0;
    }
}

void TMediator::generate_status_file()
{
    std::ofstream status_output{this->status_filename};
    std::string line;
    unsigned int x = this->map->get_map_size_x() - 1;
    unsigned int y = this->map->get_map_size_y() - 1;

    if (status_output.is_open())
    {
        line.append("2000");
        line.append("\n");
        status_output << line;
        line.clear();

        line.append("P B 1 0 0 200 0");
        line.append("\n");
        status_output << line;
        line.clear();
    
        line.append("E B 2 ");
        line.append(std::to_string(x));
        line.append(" ");
        line.append(std::to_string(y));
        line.append(" 200 0");
        line.append("\n");
        status_output << line;
        line.clear();
    }
}

void TMediator::load_orders()
{
    std::ifstream input{orders_filename};
    unsigned int space_count{0};

    for (std::string line; std::getline(input, line);)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
                space_count++;
        }

        if (space_count == 3)
        {
            update_coordinates(line);
        }
        else if (space_count == 2)
        {
            char action{};
            size_t space_pos[2]{0,0};
            int pos = 0;

            for (size_t i = 0; i < line.size(); i++)
            {    
                if (line.at(i) == ' ')
                {
                    space_pos[pos] = i;
                    pos++;
                }
            }

            pos = 0;

            action = line.at(space_pos[0]+1);

            if (action == 'B')
                start_training(line, space_pos[0], space_pos[1]);
            else if (action == 'A')
                settle_fight(line, space_pos[0], space_pos[1]);     
        }

        space_count = 0;
    }
}

void TMediator::load_player_file(std::string p)
{
    std::ifstream input;
    unsigned int space_count{0};
    size_t space_pos{};

    if (p == "player1")
        input.open(this->player1_filename);
    else if (p == "player2")
        input.open(this->player2_filename);

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

        if (space_count == 0)
        {
            if (p == "player1")
            {
                this->player1_gold_from_previous_round = std::stoi(line);
            }
            else if (p == "player2")
            {
                this->player2_gold_from_previous_round = std::stoi(line);
            }
        }
        else if (space_count == 1)
        {
            if (p == "player1")
            {
                this->units[0]->set_training_time_left(std::stoi(line.substr(space_pos)));

                // if (this->player1_training_time_left == 0)
                // {
                //     add_unit(this->units[0]->get_is_base_busy(), "player1");
                //     this->units[0]->set_is_base_busy('0');
                // }
            }
            else if (p == "player2")
            {
                this->units[1]->set_training_time_left(std::stoi(line.substr(space_pos)));
                // this->player2_training_time_left = std::stoi(line.substr(space_pos));

                // if (this->player2_training_time_left == 0)
                // {
                //     add_unit(this->units[1]->get_is_base_busy(), "player2");
                //     this->units[1]->set_is_base_busy('0');
                // }
            }
        }
        
        space_count = 0;
    }
}

void TMediator::write_status(std::string p)
{
    std::remove(status_filename.c_str());

    std::ofstream status_output{this->status_filename};
    std::string line;
    // status_output.open(this->status_filename, std::ofstream::out | std::ofstream::app);

    if (status_output.is_open())
    {
        if (p == "player1")
        {
            if (player1_round_counter == 1)
            {
                line.append(std::to_string(2000));
                line += "\n";
            }
            else if (player1_round_counter >= 2)
            {
                line.append(std::to_string(this->player2_gold_from_previous_round));
                line += "\n";
            }
        }
        else if (p == "player2")
        {
            line.append(std::to_string(this->player1_gold_from_previous_round));
            line += "\n";    
        }

        status_output << line;
        line.clear();
    

        for (auto el : this->units)
        {
            if (el->get_is_defeated() == true)
                continue;

            // line.append(std::to_string(el->get_affiliation()));
            line += el->get_affiliation();
            line.append(" ");

            // line.append(std::to_string(el->get_type()));
            line += el->get_type();
            line.append(" ");

            line.append(std::to_string(el->get_id()));
            line.append(" ");

            line.append(std::to_string(el->get_coordinates().first));
            line.append(" ");

            line.append(std::to_string(el->get_coordinates().second));
            line.append(" ");
            
            line.append(std::to_string(el->get_stamina()));

            if (el->get_type() == 'B')
            {
                line.append(" ");
                // line.append(std::to_string(el->get_is_base_busy()));
                line += el->get_is_base_busy();
            }

            line.append("\n");
            status_output << line;
            line.clear();
        }
    }

    status_output.close();
    
    if ((this->player1_round_counter + this->player2_round_counter) == (this->total_number_of_rounds - 1))
        perform_unit_census();

    if (this->units.size() > 0)
    {
        for (auto el : units)
            delete el;

        units.clear();
    }
}

void TMediator::run(std::string p)
{
    if (p == "player1")
    {
        std::cout << "Player 1, Round " << player1_round_counter << std::endl;
        std::system("./player1 ../map.txt ../status.txt ../orders.txt 2");
    }
    if (p == "player2")
    {
        std::cout << "Player 2, Round " << player2_round_counter << std::endl;
        std::system("./player2 ../map.txt ../status.txt ../orders.txt 2");
    }
}

unsigned int TMediator::get_player1_round_number()
{
    return this->player1_round_counter;
}

unsigned int TMediator::get_player2_round_number()
{
    return this->player2_round_counter;
}

std::string TMediator::get_player1_filename()
{
    return this->player1_filename;
}

std::string TMediator::get_player2_filename()
{
    return this->player2_filename;
}

void TMediator::update_round_number(std::string p)
{
    if (p == "player1")
        this->player1_round_counter++;
    else if (p == "player2")
        this->player2_round_counter++;
}

void TMediator::perform_unit_census()
{
for (auto el : this->units)
    {
        if (el->get_affiliation() == 'P')
            this->player1_units += 1;
        else if (el->get_affiliation() == 'E')
            this->player2_units += 1;
    }
}

void TMediator::settle_outcome()
{
    std::cout << "Player 1: " << this->player1_units << " units on the map." << std::endl;
    std::cout << "Player 2: " << this->player2_units << " units on the map." << std::endl;

    if (this->player1_units > this->player2_units)
        std::cout << "Player 1 wins!" << std::endl;
    else if (this->player2_units > this->player1_units)
        std::cout << "Player 2 wins!" << std::endl;
    if (this->player1_units == this->player2_units)
        std::cout << "It's a tie!" << std::endl;
}

void TMediator::add_base(std::string line)
{
    size_t space_pos[6]{0,0,0,0,0,0};
    int pos = 0;

    char aff{};
    unsigned int id{};
    unsigned int x{};
    unsigned int y{};
    unsigned int stamina{};
    char busy{};

    for (size_t i = 0; i < line.size(); i++)
    {    
        if (line.at(i) == ' ')
        {
            space_pos[pos] = i;
            pos++;
        }
    }

    pos = 0;

    aff = line[0];
    // aff = (char) stoi(line.substr(0,space_pos[0]));
    id = stoi(line.substr(space_pos[1], space_pos[2]));
    x = stoi(line.substr(space_pos[2], space_pos[3]));
    y = stoi(line.substr(space_pos[3], space_pos[4]));
    stamina = stoi(line.substr(space_pos[4], space_pos[5]));
    busy = line[line.size() - 1];

    this->units.push_back(new TBase(aff, x, y, id, stamina, busy));

    // if (aff == 'P')
    //     this->player1_units++;
    // else if (aff == 'E')
    //     this->player2_units++;
}

void TMediator::add_unit(char type, std::string player)
{
    char aff;
    if (player == "player1")
        aff = 'P';
    else if (player == "player2")
        aff = 'E';

    switch(type)
    {
        case 'A':
            this->units.push_back(new TArcher(aff, this->map));
            break;
        case 'C':
            this->units.push_back(new TCatapult(aff, this->map));
            break;
        case 'K':
            this->units.push_back(new TKnight(aff, this->map));
            break;
        case 'P':
            this->units.push_back(new TPikeman(aff, this->map));
            break;
        case 'R':
            this->units.push_back(new TRam(aff, this->map));
            break;
        case 'S':
            this->units.push_back(new TSwordsman(aff, this->map));
            break;
        case 'W':
            this->units.push_back(new TWorker(aff, this->map));
            break;
    }

    // if (player == "player1")
    //     this->player1_units++;
    // else if (player == "player2")
    //     this->player2_units++;
}

void TMediator::add_unit(std::string line)
{
    size_t space_pos[5]{0,0,0,0,0};
    int pos = 0;

    char aff{};
    char type{};
    unsigned int id{};
    unsigned int x{};
    unsigned int y{};
    unsigned int stamina{};

    for (size_t i = 0; i < line.size(); i++)
    {    
        if (line.at(i) == ' ')
        {
            space_pos[pos] = i;
            pos++;
        }
    }

    pos = 0;

    aff = line[0];
    type = line[2];
    id = stoi(line.substr(space_pos[1], space_pos[2]));
    x = stoi(line.substr(space_pos[2], space_pos[3]));
    y = stoi(line.substr(space_pos[3], space_pos[4]));
    stamina = stoi(line.substr(space_pos[4]));

    switch(type)
    {
        case 'A':
            this->units.push_back(new TArcher(aff, x, y, id, stamina));
            break;
        case 'C':
            this->units.push_back(new TCatapult(aff, x, y, id, stamina));
            break;
        case 'K':
            this->units.push_back(new TKnight(aff, x, y, id, stamina));
            break;
        case 'P':
            this->units.push_back(new TPikeman(aff, x, y, id, stamina));
            break;
        case 'R':
            this->units.push_back(new TRam(aff, x, y, id, stamina));
            break;
        case 'S':
            this->units.push_back(new TSwordsman(aff, x, y, id, stamina));
            break;
        case 'W':
            this->units.push_back(new TWorker(aff, x, y, id, stamina));
            break;
    }

    // if (aff == 'P')
    //     this->player1_units++;
    // else if (aff == 'E')
    //     this->player2_units++;
}

void TMediator::update_coordinates(std::string line)
{
    size_t space_pos[3]{0,0,0};
    int pos = 0;

    unsigned int selected_unit{};
    unsigned int target_x{};
    unsigned int target_y{};

    for (size_t i = 0; i < line.size(); i++)
    {    
        if (line.at(i) == ' ')
        {
            space_pos[pos] = i;
            pos++;
        }
    }

    pos = 0;

    /* extract from string based on the positions of spaces */
    selected_unit = std::stoi(line.substr(0,space_pos[0]));
    target_x = std::stoi(line.substr(space_pos[1], space_pos[2]));
    target_y = std::stoi(line.substr(space_pos[2]));

    /* update the unit coordinates */
    for (auto el : this->units)
    {
        if (el->get_id() == selected_unit)
        {
            el->set_coordinates(target_x, target_y);
        }
    }
}

void TMediator::settle_fight(std::string line, size_t first_space, size_t second_space)
{
    unsigned int attacker_id = std::stoi(line.substr(0,first_space));
    unsigned int attacked_id = std::stoi(line.substr(second_space));
    std::pair<unsigned int, unsigned int> attacked_unit_coordinates{};
    unsigned int damage{};
    unsigned int key{};
    bool victory{false};

    /* determine the kinds of units that are to fight against one another */
    for (auto el : this->units)
    {
        if (el->get_id() == attacked_id)
        {
            key = el->get_as_opponent();
            attacked_unit_coordinates.first = el->get_coordinates().first;
            attacked_unit_coordinates.second = el->get_coordinates().second;
        }
    }

    /* Determine the damage that is beaing dealt by the attacker using the attack tables */
    for (auto el : this->units)
    {
        if (el->get_id() == attacker_id)
        {
            damage = el->get_attack_table(key);
        }
    }

    /* update the attacked unit stamina */
    for (auto el : this->units)
    {
        if (el->get_id() == attacked_id)
        {
            el->set_stamina(el->get_stamina() - damage);

            if (el->get_stamina() <= 0)
            {
                el->set_is_defeated(true);
                victory = true;
                std::cout << "Unit " << el->get_id() << " is defeated." << std::endl;

                // char aff = el->get_affiliation();

                // if (aff == 'P')
                //     this->player1_units--;
                // else if (aff == 'E')
                //     this->player2_units--;

                /* if base is defeated, the game is over */
                if (el->get_type() == 'B')
                {
                    std::cout << "Game over. ";

                    if (el->get_affiliation() == 'P')
                        std::cout << "Player 2 wins!" << std::endl;
                    if (el->get_affiliation() == 'E')
                        std::cout << "Player 1 wins!" << std::endl;
                    
                    std::exit(EXIT_SUCCESS);
                }
            }
        }
    }

    /* if victorious, the attacker moves to the spot previously occupied by the attacked unit */
    if (victory == true)
    {   
        for (auto i : this->units)
        {
            if (i->get_id() == attacker_id)
            {
                i->set_coordinates(attacked_unit_coordinates.first, attacked_unit_coordinates.second);
            }
        }
    }    
}

void TMediator::start_training(std::string line, size_t first_space, size_t second_space)
{
    unsigned int base_id = std::stoi(line.substr(0,first_space));
    char unit_to_be_trained = line.at(second_space + 1);

    for (auto el : this->units)
    {
        if (el->get_id() == base_id)
            el->set_is_base_busy(unit_to_be_trained);
    }
}