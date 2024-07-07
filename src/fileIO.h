#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include "data.h"

void create_txt_file_data( );
void read_data_file( std::vector<Coord<float>> &vec, std::string fileName, char c );

template <typename data_t>
Coord<data_t> get_coords_from_string( std::string &str, char c )
{
    std::istringstream input;
    std::string str2;
    data_t x, y, z;
    double milSecs;
    input.str(str);
    std::getline(input, str2, c);
    x = std::stof(str2);
    std::getline(input, str2, c);
    y = std::stof(str2);
    std::getline(input, str2, c);
    z = std::stof(str2);
    std::getline(input, str2, c);
    milSecs = std::stod(str2);
    return Coord{ x, y, z, milSecs };
};
#endif // #ifndef FILEIO_H