#ifndef VECMATH_H
#define VECMATH_H

#include <cmath>
#include <vector>
#include <iostream>
#include "vecMath.h"
#include "data.h"

const int square  = 2;

template <typename data_t>
data_t calc_dis_between_two_pts( const Coord<data_t> &p1, const Coord<data_t> &p2 )
{
    const auto&[x1, y1, z1] = p1.point;
    const auto&[x2, y2, z2] = p2.point;
    // max and  min were used to ensure no negitive values will be used
    data_t xSquareVal = std::pow( ( std::max(x1, x2) - std::min(x1, x2) ), square );
    data_t ySquareVal = std::pow( ( std::max(y1, y2) - std::min(y1, y2) ), square );
    data_t zSquareVal = std::pow( ( std::max(z1, z2) - std::min(z1, z2) ), square );

    return data_t (std::sqrt( xSquareVal + ySquareVal + zSquareVal ));
};

template <typename data_t>
data_t calc_total_dist_of_coords( const std::vector<Coord<data_t>> &coordVec )
{
    data_t vecLength = 0;
    
    for( size_t i = 0; i < (coordVec.size( ) - 1); ++i ) {
        vecLength += calc_dis_between_two_pts( coordVec.at(i), coordVec.at(i+1) );
    }
    return vecLength;
};
#endif // #ifndef VECMATH_H