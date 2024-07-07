#include "fileIO.h"

void create_txt_file_data( ) {
    std::ofstream outFile("data.txt");

    if(!outFile) {
        std::cout << "\nCan't open file" << std::endl;
        throw( std::runtime_error ("Cannot open outFile") );
    }

    outFile << "1.3 4.65 8.3 4585245892\n" << "2.3 34.3 11.38 123456\n" << "3.3 4.945 3.2 524\n" << "63 7.47 6.93 5185896\n";
    outFile << "5.3 4.2 4.131 283245892\n" << "5.697 3.22 1.38 13263\n" << "2.69 1.739 32.11 56564\n" << "163 7.47 6.93 518896\n";
    outFile.close(); 
}

void read_data_file( std::vector<Coord<float>> &vec, std::string fileName, char c ) {
    vec.clear( );
    
    std::ifstream inFile(fileName);

    if(!inFile) {
        std::cout << "\nCan't open file" << std::endl;
        throw( std::runtime_error ("Cannot open inFile") );
    }

    std::string str;

    while ( std::getline(inFile, str) ) { 
        try {
            vec.push_back( get_coords_from_string<float>( str, c ) );
        }
        //  stof & stod will both throw std::invalid_argument 
        //  if no conversion could be performed  
        catch( const std::invalid_argument& e ) {
            std::cout << e.what() << std::endl;
            std::cout << "invalid argument continue to next Point" << std::endl;
            continue;
        }
        //  stof & stod will both throw std::out_of_range 
        //  if the converted value would fall out of the range 
        //  of the result type or if the underlying function
        //  (std::strtol or std::strtoll) sets errno to ERANGE.
        catch( const std::out_of_range& e ) {
            std::cout << e.what() << std::endl;
            std::cout << "out of range error continue to next Point" << std::endl;
            continue;
        }
        // Unexpected Exception move to next point
        catch(...) {
            std::cout << "Unexpected Exception continue to next Point" << std::endl;
            continue;   
        } 
    }
    inFile.close();
    if ( vec.size() == 0 ) {
        std::cout << "No valid Cartesian coordinate in data file" << std::endl;
        exit(5);
    } 
}
