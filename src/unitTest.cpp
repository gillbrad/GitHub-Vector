
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "vecMath.h"
#include "fileIO.h"
#include "unitTest.h"


void create_txt_file_w_error( ) {
    std::ofstream outFile("testdata.txt");

    if(!outFile) {
        std::cout << "\nCan't open file" << std::endl;
        throw( std::runtime_error ("Cannot open outFile") );
    }

    outFile << "1.3 4.6 8.3 4585245892\n" << "2.3 asdf 1.38 123456\n" << "3.3 4.945 3.2 524\n";
    outFile << "5.3 4585698569852453153123213213213213213214582244.2 4.131 283245892\n" << "63 7.47 6.93 5185896\n";
    outFile.close(); 
}

Status file_io_validation_test( )
{
    Status status = PASS;
    std::cout << "Run File IO test" << std::endl;
    std::vector <Coord<float>> testVec; 
    create_txt_file_w_error( );
    read_data_file(testVec, "testdata.txt", ' ' );
    if (testVec.size() != 3)
    {
        status = status;
        throw status;
    }
    return status;  
}

Status unit_test_dis_between_two_pt ( )
{
    Status status = PASS;

    std::cout << "Run Test Distance between two pts" << std::endl;
    
    Coord<float> coord1( 0.0, 0.0, 0.0, 123 );
    Coord<float> coord2( 0.0, 0.0, 0.0, 567 );
    // Expected result is 0
    float len_i = calc_dis_between_two_pts<float>( coord1, coord2 );
    if (len_i != 0.0)
    {
        status = FAIL;
        throw status;
    }
    coord2.point.z = 1.0;
    // Expected result is 1
    len_i = calc_dis_between_two_pts<float>( coord1, coord2 );
    if (len_i != 1.0)
    {
        status = FAIL;
        throw status;
    }
    coord2.point.z = 0.0;
    coord2.point.y = 1;
    // Expected result is 1
    len_i = calc_dis_between_two_pts<float>( coord1, coord2 );
    if (len_i != 1.0)
    {
        status = FAIL;
        throw status;
    }
    coord2.point.y = 0;
    coord2.point.x = 1;
    // Expected result is 1
    len_i = calc_dis_between_two_pts<float>( coord1, coord2 );
    if (len_i != 1.0)
    {
        status = FAIL;
        throw status;
    }
    Coord<float> coord3( 1.6, 5.8, 2.3, 123 );
    Coord<float> coord4( 1.9, 2.4, 6.6, 123 );
    // Expected result is 5.4899 ( 2 point of precision is excepted error )
    float len_f = calc_dis_between_two_pts<float>( coord3, coord4 ); 
    if ( len_f > 5.5 || len_f < 5.48 ) 
    {
        status = FAIL;
        throw status;    
    }
    return status;
}

Status unit_test_length_of_coord_vec( )
{
    Status status = PASS;

    std::cout << "Run Test Length of Vector" << std::endl;

    Coord<int> coord1( 0, 0, 0, 123 );
    Coord<int> coord2( 1, 0, 0, 123 );
    Coord<int> coord3( 2, 0, 0, 123 );
    Coord<int> coord4( 3, 0, 0, 123 );

    std::vector<Coord<int>> testVector {coord1, coord2, coord3, coord4};
    int len = calc_total_dist_of_coords<int>( testVector );

    if (len != 3)
    {
        status = FAIL;
        throw FAIL;
    }

    return status;
}

Status run_all_unit_tests(  )
{
    std::cout << "\n********Running Unit Tests********\n" << std::endl;
    Status status = unit_test_dis_between_two_pt ( );
    status = unit_test_length_of_coord_vec( ); 
    status = file_io_validation_test( );
    return status;  
}

void unit_test( )
{
    Status status = run_all_unit_tests(  );
    if ( status == PASS )
    {
        std::cout << "\n**********Unit Test Pass**********" << std::endl;
    }  
}


