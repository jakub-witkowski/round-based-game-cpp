#include "../headers/TMap.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

/* Constructor */
TMap::TMap(std::string f) : filename(f), map_size_x(parse_map_x()), map_size_y(parse_map_y()), map_fields(new int*[map_size_x])
{
    /* allocating a 2D array to hold the map field int representation */
    for (size_t i = 0; i < map_size_x; i++)
    {
        map_fields[i] = new int[map_size_y];
    }

    this->load_map();

    /*std::cout << "Map created, filename: "
              << this->filename
              << ", x-dimension: "
              << this->map_size_x
              << ", y-dimension: "
              << this->map_size_y << std::endl;*/
}

/* Destructor */
TMap::~TMap()
{
    /* free 2D array */
    for (size_t i = 0; i < this->map_size_x; i++)
        delete[] map_fields[i];

    delete[] map_fields;

    // std::cout << "~TMap()" << std::endl;
}

/* read the horizontal dimension from txt file */
unsigned int TMap::parse_map_x()
{
    std::ifstream input{this->filename};
    
    std::string line;
    std::getline(input, line);

    return static_cast<unsigned int>(line.size());
}

/* read the vertical dimension from txt file */
unsigned int TMap::parse_map_y()
{
    std::ifstream input{this->filename};
    unsigned int row_count{};

    for (std::string line; std::getline(input, line);)
        row_count++;

    return row_count;
}

void TMap::load_map()
{
    std::ifstream input{this->filename};
    int row{};
    
    for (std::string line; std::getline(input, line);)
    {
        for (size_t i = 0; i < line.size(); i++)
        {
            std::stringstream field;
            int temp;
            field << line.at(i);
            field >> temp;
            this->map_fields[row][i] = temp;
        }
        row++;
    }
}