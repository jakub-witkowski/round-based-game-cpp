#ifndef TMAP_H
#define TMAP_H

#include <string>
#include <vector>
#include <iostream>

class TMap
{
    public:
        TMap();
        TMap(std::string);
        ~TMap();

        unsigned int parse_map_x();
        unsigned int parse_map_y();
        void load_map();
        
        unsigned int get_map_size_x();
        unsigned int get_map_size_y();
        
        friend std::ostream& operator<<(std::ostream&, TMap*);


    private:
        std::string filename;
        unsigned int map_size_x;
        unsigned int map_size_y;
        int** map_fields{nullptr};

};

#endif