#include "../headers/TMediator.h"
#include "../headers/TArcher.h"
#include "../headers/TBase.h"
#include "../headers/TCatapult.h"
#include "../headers/TKnight.h"
#include "../headers/TPikeman.h"
#include "../headers/TRam.h"
#include "../headers/TSwordsman.h"
#include "../headers/TWorker.h"

TMediator::TMediator()
{

}

TMediator::~TMediator()
{
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
            this->set_gold(std::stol(line));
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

void TMediator::load_orders()
{

}

void TMediator::load_player_file()
{

}

void TMediator::write_status()
{

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

void TMediator::update_round_number(std::string p)
{
    if (p == "player1")
        this->player1_round_counter++;
    else if (p == "player2")
        this->player2_round_counter++;
}

void TMediator::set_gold(long g)
{
    this->gold = g;
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
    id = stoi(line.substr(space_pos[1], space_pos[2]));
    x = stoi(line.substr(space_pos[2], space_pos[3]));
    y = stoi(line.substr(space_pos[3], space_pos[4]));
    stamina = stoi(line.substr(space_pos[4], space_pos[5]));
    busy = line[line.size() - 1];

    this->units.push_back(new TBase(aff, x, y, id, stamina, busy));
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
}