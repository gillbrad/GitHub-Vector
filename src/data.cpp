
#include <iostream>
#include <vector>
#include <algorithm>
#include "data.h"

void print_coord_vector( const std::vector <Coord<float>> &pointVec )
{
    std::cout << "\n**Print Coord Vector**" << std::endl;
    for ( auto i : pointVec ) {
        std::cout << i << std::endl;
    }
}

void sort_coord_vector( std::vector <Coord<float>> &sortVec )
{
    std::cout << "\n**Sort Coord Vector**" << std::endl;
    //std::sort(sortVec.begin(), sortVec.end(), [](Coord<float> coord) {coord.tStamp.totalMSec;}); 
    std::sort(sortVec.begin(), sortVec.end() ); 
}

void reverse_coord_vector( std::vector <Coord<float>> &revVec )
{
    std::cout << "\n**Reverse Coord Vector**" << std::endl;
    std::reverse(revVec.begin(), revVec.end() );  
}

double get_new_time_stamp( )
{
    return 0;
}


