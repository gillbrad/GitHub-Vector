
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include "fileIO.h"
#include "data.h"
#include "vecMath.h"
#include "unitTest.h"

int main( [[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    
    try {
        unit_test ( );
        
        create_txt_file_data( );
        CoordData<float> coordData{"data.txt", ' ' };
        coordData.print( );
        coordData.length( );
        coordData.add( 1.1, 2.2, 3.3, 1234567 );
        coordData.print( );
        coordData.length( );
        coordData.reverse( );
        coordData.print( );
    }

    catch( const Status ) {
        std::cout << "Unit Test Failure" << std::endl;
        exit(1);
    }

    catch( const std::logic_error& e ) {
        std::cout << e.what() << std::endl;
        // logic error exit with error condition 2
        exit(2);
    }

    catch( const std::runtime_error& e ) {
        std::cout << e.what() << std::endl;
        // runtime error exit with error condition 1
        exit(3);
    }

    catch(...) {
        std::cout << "Unexpected Exception" << std::endl;
        // Unexpected Exception exit with error condition 3
        exit(4);   
    }
       
    return 0;
}