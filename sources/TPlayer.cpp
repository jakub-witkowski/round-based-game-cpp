#include "../headers/TPlayer.h"

#include <fstream>

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

void TPlayer::order_training(std::string orders)
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

        if (drawing_result < 50)
            std::cout << "No training ordered." << std::endl;
        else
        {
            if (this->gold < 200)
            {
                phrase = "training a worker";
                this->units.push_back(new TWorker(this->identity, this->map_ptr));
                this->set_base_busy(this->identity, 'W');
                choice_made = true;
            }
            else if ((this->gold >= 100) && (this->gold < 250))
            {
                drawing_result = cast_dice(1, 100);
                if (drawing_result <= 50)
                {
                    phrase = "training a worker";
                    units.push_back(new TWorker(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'W');
                    choice_made = true;
                }
                else if (drawing_result > 50)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'P');
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
                    this->set_base_busy(this->identity, 'W');
                    choice_made = true;
                }
                else if (drawing_result > 25 && drawing_result <= 50)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'P');
                    choice_made = true;
                }
                else if (drawing_result > 50 && drawing_result < 75)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'S');
                    choice_made = true;
                }
                else if (drawing_result > 75 && drawing_result <= 100)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'A');
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
                    this->set_base_busy(this->identity, 'W');
                    choice_made = true;
                }
                else if (drawing_result > 20 && drawing_result <= 40)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'P');
                    choice_made = true;
                }
                else if (drawing_result > 40 && drawing_result <= 60)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'S');
                    choice_made = true;
                }
                else if (drawing_result > 60 && drawing_result <= 80)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'A');
                    choice_made = true;
                }
                else if (drawing_result > 80 && drawing_result <= 100)
                {
                    phrase = "training a knight";
                    units.push_back(new TKnight(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'K');
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
                    this->set_base_busy(this->identity, 'W');
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 50 && (3 * drawing_result) <= 100)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'P');
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 100 && (3 * drawing_result) <= 150)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'S');
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 150 && (3 * drawing_result) <= 200)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'A');
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 200 && (3 * drawing_result) <= 250)
                {
                    phrase = "training a knight";
                    units.push_back(new TKnight(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'K');
                    choice_made = true;
                }
                else if ((3 * drawing_result) > 250 && (3 * drawing_result) <= 300)
                {
                    phrase = "producing a ram";
                    units.push_back(new TRam(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'R');
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
                    this->set_base_busy(this->identity, 'W');
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 50 && (drawing_result * 3.5) <= 100)
                {
                    phrase = "training a pikeman";
                    units.push_back(new TPikeman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'P');
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 100 && (drawing_result * 3.5) <= 150)
                {
                    phrase = "training a swordsman";
                    units.push_back(new TSwordsman(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'S');
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 150 && (drawing_result * 3.5) <= 200)
                {
                    phrase = "training an archer";
                    units.push_back(new TArcher(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'A');
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 200 && (drawing_result * 3.5) <= 250)
                {
                    phrase = "training a knight";
                    units.push_back(new TKnight(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'K');
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 250 && (drawing_result * 3.5) <= 300)
                {
                    phrase = "producing a ram";
                    units.push_back(new TRam(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'R');
                    choice_made = true;
                }
                else if ((drawing_result * 3.5) > 300)
                {
                    phrase = "producing a catapult";
                    units.push_back(new TCatapult(this->identity, this->map_ptr));
                    this->set_base_busy(this->identity, 'C');
                    choice_made = true;
                }	
            }
        }
    }

    if (choice_made == true)
	{
        std::ofstream output;
        output.open(orders, std::ofstream::out | std::ofstream::app);
        std::string training_output;
        char suffix;

        if (output.is_open())
        {
            if (this->identity == 'P')
                training_output.append("0 B ");
            else
                training_output.append("1 B ");

            suffix = this->units[units.size() - 1]->get_type();
            training_output += suffix;
            training_output.append("\n");

            output << training_output;
            output.close();
        }

        this->update_gold(units[units.size() - 1]->get_cost());
		std::cout << prefix	<< phrase << ". " << std::endl;
	}

}

void TPlayer::update_gold(int cost)
{
    this->gold -= cost;
}

void TPlayer::move_units(std::string orders)
{
    for (auto el : this->units)
    {
        if (el->get_affiliation() != this->identity)
            continue;
        if (el->get_type() == 'B')
            continue;
        if (el->get_training_time() > 0)
            continue;
        if (el->get_training_time() == 0 && el->get_remaining_movement_points() > 0)
        {
            order_move(el, orders);
        }
    }
}

void TPlayer::order_move(TUnit* u, std::string orders)
{
    /* how many fields a unit is ordered to move in x and y direction */
    int x_axis_move{};
    int y_axis_move{};

    int row_number{}; // controls the use of the spread arrays
    bool is_dice_cast = false; // controls the validation process: 0 = no move generated; 1 = moves for two axes generated;
    unsigned int distance{}; // the distance the unit is attempting to cover
    int target_x{}; // target x coordinate
    int target_y{}; // target y coordinate

    /* auxiliary arrays for determining the x vs y spread in distance */
    const int spread1[2][2] = { {0, 1}, {1, 0} };
    const int spread2[3][2] = { {0, 2}, {1, 1}, {2, 0} };
    const int spread3[4][2] = { {0, 3}, {1, 2}, {2, 1}, {3, 0} };
    const int spread4[5][2] = { {0, 4}, {1, 3}, {2, 2}, {3, 1}, {4, 0} };
    const int spread5[6][2] = { {0, 5}, {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0} };

    if (u->get_type() == 'K')
    {
        distance = cast_dice(1,5);
        switch (distance)
        {
            /*case 0:
                x_axis_move = 0;
                y_axis_move = 0;
                dice_cast = false;
                break;*/
            case 1:
                row_number = cast_dice(0,1);
                x_axis_move = spread1[row_number][0];
                y_axis_move = spread1[row_number][1];
                is_dice_cast = true;
                break;
            case 2:
                row_number = cast_dice(0,2);
                x_axis_move = spread2[row_number][0];
                y_axis_move = spread2[row_number][1];
                is_dice_cast = true;
                break;
            case 3:
                row_number = cast_dice(0,3);
                x_axis_move = spread3[row_number][0];
                y_axis_move = spread3[row_number][1];
                is_dice_cast = true;
                break;
            case 4:
                row_number = cast_dice(0,4);
                x_axis_move = spread4[row_number][0];
                y_axis_move = spread4[row_number][1];
                is_dice_cast = true;
                break;
            case 5:
                row_number = cast_dice(0,5);
                x_axis_move = spread5[row_number][0];
                y_axis_move = spread5[row_number][1];
                is_dice_cast = true;
                break;
        } 
    }
    else if (u->get_type() != 'K' && u->get_type() != 'B')
    {
        distance = cast_dice(1,2);
        //distance = r(0,2);
        switch (distance)
        {
            /*case 0:
                x_axis_move = 0;
                y_axis_move = 0;
                dice_cast = false;
                break;*/
            case 1:
                row_number = cast_dice(0,1);
                x_axis_move = spread1[row_number][0];
                y_axis_move = spread1[row_number][1];
                is_dice_cast = true;
                break;
            case 2:
                row_number = cast_dice(0,2);
                x_axis_move = spread2[row_number][0];
                y_axis_move = spread2[row_number][1];
                is_dice_cast = true;
                break;
        }
    }

        /* Validating target coordinates */
        if (is_dice_cast == true)
        {
            /* validating the draws against the map */
            if (u->get_affiliation() == 'P')
                if (((u->get_coordinates().first + x_axis_move) >= this->map_ptr->get_map_size_x()) || ((u->get_coordinates().second + y_axis_move) >= this->map_ptr->get_map_size_y()))
                    is_dice_cast = false; // cannot go outside the map
            if (u->get_affiliation() == 'E')
                if (((u->get_coordinates().first - x_axis_move) < 0) || ((u->get_coordinates().second - y_axis_move) < 0))
                    is_dice_cast = false; // cannot go outside the map
        }

        if (is_dice_cast == true)
        {
            if (distance > u->get_remaining_movement_points())
                is_dice_cast = false; // cannot exceed remaining movement
        }

        if (is_dice_cast == true)
        {
            if (u->get_affiliation() == 'P')
            {
                if (this->map_ptr->get_map_field_info(u->get_coordinates().first + x_axis_move, u->get_coordinates().second + y_axis_move) == 9)
                    is_dice_cast = false; // cannot go on natural obstacles
            }
            if (u->get_affiliation() == 'E')
            {
                if (this->map_ptr->get_map_field_info(u->get_coordinates().first - x_axis_move, u->get_coordinates().second - y_axis_move) == 9)
                    is_dice_cast = false; // cannot go on natural obstacles
            }
        }

        if (is_dice_cast == true)
        {
            if (is_map_field_occupied(u->get_affiliation(), u->get_coordinates().first, u->get_coordinates().second) == true)
                is_dice_cast = false;
            else
                is_dice_cast = true;
        }

        if (is_dice_cast == true)
        {
            if (u->get_affiliation() == 'P')
            {
                target_x = u->get_coordinates().first + x_axis_move;
                target_y = u->get_coordinates().second + y_axis_move;
            }
            else if (u->get_affiliation() == 'E')
            {
                target_x = u->get_coordinates().first - x_axis_move;
                target_y = u->get_coordinates().second - y_axis_move;
            }

            u->update_remaining_movement_points(distance);
            
            std::ofstream output;
            output.open(orders, std::ofstream::out | std::ofstream::app);

            std::string move_order_output;
            move_order_output.append(std::to_string(u->get_id()));
            move_order_output.append(" M ");
            move_order_output.append(std::to_string(target_x));
            move_order_output.append(" ");
            move_order_output.append(std::to_string(target_y));
            move_order_output.append("\n");

            output << move_order_output;
            output.close();

            std::cout
            << "Ordering unit "
            << u->get_id()
            << " to move to x: "
            << target_x
            << ", y: "
            << target_y
            << ". "
            << std::endl;
    
            u->set_coordinates(target_x, target_y);
        }
}
void TPlayer::attack_enemy(std::string orders)
{
    for (auto el : this->units)
    {
        if (el->get_affiliation() != this->identity)
            continue;
        if (el->get_type() == 'B')
            continue;
        if (el->get_training_time() > 0)
            continue;
        if ((el->get_training_time() == 0) && (el->get_remaining_movement_points() > 0) && (el->get_may_attack_enemy_units() == true))
        {
            order_attack(el, orders);
        }
    }
}

void TPlayer::order_attack(TUnit* u, std::string orders)
{
    for (auto el : this->units)
    {
        unsigned int distance = abs(u->get_coordinates().first - el->get_coordinates().first)
                    + abs(u->get_coordinates().second - el->get_coordinates().second);
        if (el->get_affiliation() == u->get_affiliation())
            continue;
        if (el->get_affiliation() != u->get_affiliation())
        {
            if ((distance <= u->get_attack_range() - 1) && (u->get_may_attack_enemy_units() == true))
            {
                u->set_may_attack_enemy_units(0);
                u->set_speed(0);

                std::cout << "Ordering unit " << u->get_id() << " to attack the opponent unit " << el->get_id() << ". " << std::endl;
            
                std::ofstream output;
                output.open(orders, std::ofstream::out | std::ofstream::app);

                std::string attack_order_output;
                attack_order_output.append(std::to_string(u->get_id()));
                attack_order_output.append(" A ");
                attack_order_output.append(std::to_string(el->get_id()));
                attack_order_output.append("\n");

                if (output.is_open())
                {
                    output << attack_order_output;
                }

                output.close();
            }
        }
    }       
}

bool TPlayer::is_map_field_occupied(char aff, unsigned int x, unsigned int y)
{
    int number_of_units_at_the_field{0};
    char opponent_affiliation;

    if (aff == 'P')
        opponent_affiliation = 'E';
    else if (aff == 'E')
        opponent_affiliation = 'P';

    for (size_t i = 0; i < this->units.size(); i++)
    {
        if (this->units[i]->get_affiliation() == opponent_affiliation)
        {
            if (this->units[i]->get_coordinates().first == x && this->units[i]->get_coordinates().second == y)
            number_of_units_at_the_field++;
        }
    }

    if (number_of_units_at_the_field > 0)
    {
        std::cout << "Cannot move to enemy-held territory." << std::endl;
        return true;
    }
    else
        return false;
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

void TPlayer::set_base_busy(char aff, char t)
{
    if (aff == 'P')
        this->units[0]->set_is_base_busy(t);
    else if (aff == 'E')
        this->units[1]->set_is_base_busy(t);
}

void TPlayer::write_player_file()
{
    std::ofstream output;
    std::string fname;
    std::string player_file;
    int base_index;

    if (this->identity == 'P')
    {
        fname = "../player1.txt";
        base_index = 0;
    }
    else if (this->identity == 'E')
    {
        fname = "../player2.txt";
        base_index = 1;
    }

    std::remove(fname.c_str());

    output.open(fname, std::ofstream::out | std::ofstream::app);

    if (output.is_open())
    {
        if (this->units[base_index]->get_is_base_busy() != '0')
        {
            player_file.append("T ");
            player_file.append(std::to_string(this->units[units.size() - 1]->get_training_time() - 1));
            player_file.append("\n");
        }
        
        player_file.append(std::to_string(this->gold));
    }

    output << player_file;
    output.close();
}