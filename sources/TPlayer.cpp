#include "../headers/TPlayer.h"

TPlayer::TPlayer()
{
    std::cout << "TPlayer default constructor called" << std::endl;
}

TPlayer::TPlayer(char id, long g, TMap* m) : identity(id), gold(g), map_ptr(m)
{
    std::cout << "TPlayer constructor called" << std::endl;
}

TPlayer::~TPlayer()
{
    if (this->units.size() > 0)
    {
        for (size_t i = 0; i < units.size(); i++)
        {
            delete units[i];
        }
    }
    std::cout << "TPlayer destructor called" << std::endl;
}

int TPlayer::cast_dice(int min, int max)
{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<> distr(min, max);
    int dice_roll = distr(generator);

    return dice_roll;
}

void TPlayer::order_training()
{
    bool are_funds_sufficient{false};
    int drawing_result{};
    bool choice_made{false};

    std::string prefix{"Started "};
	std::string phrase;

    if (this->gold < 100)
        std::cout << "Insufficient funds to train units." << std::endl;
    else
        are_funds_sufficient = true;

    if (are_funds_sufficient == true)
    {
        drawing_result = TPlayer::cast_dice(0,100);
        // std::cout << "Dice cast: " << drawing_result << std::endl;

        if (drawing_result < 50)
            std::cout << "No training ordered." << std::endl;
        else
        {
            if (this->gold < 200)
            {
                phrase = "training a worker";
                this->units.push_back(new TWorker(this->identity, this->map_ptr));
                choice_made = true;
            }
            else if ((this->gold >= 100) && (this->gold < 250))
            {
                drawing_result = cast_dice(1, 100);
                if (drawing_result <= 50)
                {
                    phrase = "training a worker";
                    units.push_back(new TWorker(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 50)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    choice_made = true;
                }
            }
            else if ((this->gold >= 250) && (this->gold < 400))
            {
                drawing_result = cast_dice(1, 100);
                if (drawing_result <= 25)
                {
                    phrase = "training a worker";
                    units.push_back(new TWorker(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 25 && drawing_result <= 50)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 50 && drawing_result < 75)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 75 && drawing_result <= 100)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    choice_made = true;
                }
            }
            else if ((this->gold >= 400) && (this->gold < 500))
            {
                drawing_result = cast_dice(1,100);
                if (drawing_result <= 20)
                {
                    phrase = "training a worker";
                    units.push_back(new TWorker(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 20 && drawing_result <= 40)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 40 && drawing_result <= 60)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 60 && drawing_result <= 80)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if (drawing_result > 80 && drawing_result <= 100)
                {
                    phrase = "training a knight";
                    units.push_back(new TKnight(this->identity, this->map_ptr));
                    choice_made = true;
                }
            }
            else if ((this->gold >= 500) && (this->gold < 800))
            {
                drawing_result = cast_dice(1,100);
                if ((3 * drawing_result) <= 50)
                {
                    phrase = "training a worker";
                    units.push_back(new TWorker(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 50 && (3 * drawing_result) <= 100)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 100 && (3 * drawing_result) <= 150)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 150 && (3 * drawing_result) <= 200)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 200 && (3 * drawing_result) <= 250)
                {
                    phrase = "training a knight";
                    units.push_back(new TKnight(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 250 && (3 * drawing_result) <= 300)
                {
                    phrase = "producing a ram";
                    units.push_back(new TRam(this->identity, this->map_ptr));
                    choice_made = true;
                }
            }
            else if (this->gold >= 800)
            {
                drawing_result = cast_dice(1,100);
                if ((drawing_result * 3.5) <= 50)
                {
                    phrase = "training a worker";
                    units.push_back(new TWorker(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 50 && (drawing_result * 3.5) <= 100)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 100 && (drawing_result * 3.5) <= 150)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 150 && (drawing_result * 3.5) <= 200)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 200 && (drawing_result * 3.5) <= 250)
                {
                    phrase = "training a knight";
                    units.push_back(new TKnight(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 250 && (drawing_result * 3.5) <= 300)
                {
                    phrase = "producing a ram";
                    units.push_back(new TRam(this->identity, this->map_ptr));
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 300)
                {
                    phrase = "producing a catapult";
                    units.push_back(new TCatapult(this->identity, this->map_ptr));
                    choice_made = true;
                }	
            }
        }
    }

    if (choice_made == true)
	{
		std::cout
		<< std::endl
		<< prefix
		<< phrase << ". "
		<< " Units.size() = "
		<< this->units.size()
		<< std::endl;
	}

}

void TPlayer::move_units()
{

}

void TPlayer::attack_enemy()
{

}

void TPlayer::set_gold(long g)
{
    this->gold = g;
}

void TPlayer::add_base(std::string line, TMap* m)
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

void TPlayer::add_unit(std::string line, TMap* m)
{
    size_t space_pos[5]{0,0,0,0,0};
    int pos = 0;

    char aff{};
    char type{};
    unsigned int id{};
    unsigned int x{};
    unsigned int y{};
    unsigned int stamina{};
    // unsigned int time_left{};

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

TMap* TPlayer::get_map_ptr()
{
    return this->map_ptr;
}