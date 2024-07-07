
#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>

const int mSecPerHour  = ( 1000 * 60 * 60 );
const int mSecPerMin  =  ( 1000 * 60 );
const int mSecPerSec  =  ( 1000 );

double get_new_time_stamp( );

class HMSMs
{
    public:
        int hour; 
        int min;
        int sec;
        int mSec;
        HMSMs ( ) : hour{0}, min{0}, sec{0}, mSec{0} { }
        HMSMs ( int hVal, int minVal, int secVal, int mSecVal) : hour{hVal}, min{minVal}, sec{secVal}, mSec{mSecVal} { }
};


class TimeStamp
{
    public:
        HMSMs hMSMs;
        double totalMSec;
        TimeStamp( ) : totalMSec{0} { }
        TimeStamp( double mS ) : totalMSec{mS} 
        {
            auto &[hour, min, sec, mSec] = hMSMs;

            double tempMSec = totalMSec;
            hour = (int) ( tempMSec / mSecPerHour );
            tempMSec -= ( (double) hour * (double) mSecPerHour );
            min = (int) ( tempMSec / mSecPerMin );
            tempMSec -= ( (double) min * (double) mSecPerMin );
            sec = (int) ( tempMSec / mSecPerSec );
            tempMSec -= ( (double) sec * (double) mSecPerSec );
            mSec = tempMSec;
        };
    
        friend std::ostream& operator<<( std::ostream& os, const TimeStamp& tStamp )
        {
            auto &[hour, min, sec, mSec] = tStamp.hMSMs;

            os << "Hour " << hour << " Min " << min << " Sec " << sec << " MilSec " << mSec << std::endl;
            return os;
        }
};

template <class data_t>
class Point
{
    public:
        data_t  x = 0;
        data_t  y = 0;
        data_t  z = 0;
        Point( data_t xVal, data_t yVal, data_t zVal ) : x{xVal}, y{yVal}, z{zVal} { }
        
        Point operator+ ( Point<data_t> ob2 )
        {
            return Point (x + ob2.x, y + ob2.y, z + ob2.z);
        }
};

template <class data_t> 
class Coord
{
    public :
        Point<data_t> point;
        TimeStamp tStamp;
        // Constructers
        Coord ( ) : tStamp{0}, point( ) { }
        Coord ( data_t xVal, data_t yVal, data_t zVal, double tStampMSec ) : point( xVal, yVal, zVal )
        { 
            TimeStamp tempTStamp( tStampMSec );
            tStamp = tempTStamp;
        }
        // Operator Overload
        Coord operator+ (Coord<data_t> ob2)
        {
            Coord temp;
            temp.point = point + ob2.point;
            temp.tStamp = get_new_time_stamp( );
            return temp;
        }
        friend std::ostream& operator<< ( std::ostream& os, const Coord<data_t>& lCoord )
        {
            auto &[x, y, z] = lCoord.point;
            os << "[" << x << "," << y << "," << z << "]" " Time Stamp " << lCoord.tStamp << std::endl;
            return os;
        }
        bool operator< (Coord<data_t> ob2) const
        {
            return ( tStamp.totalMSec < ob2.tStamp.totalMSec );
        }       
};

void print_coord_vector     ( const std::vector <Coord<float>> &pointVec );
void sort_coord_vector      ( std::vector <Coord<float>> &sortVec );
void reverse_coord_vector   ( std::vector <Coord<float>> &sortVec );

template <class data_t>
class CoordData
{
    private:
        std::vector<Coord<data_t>> coordVec;
    public:
        CoordData( const std::string &fileName, char delim )
        {
            read_data_file( coordVec, fileName, delim );
            sort_coord_vector( coordVec );
        }
        void print( )
        {
            print_coord_vector( coordVec );
        }
        void add ( data_t x, data_t y, data_t z, double milSec )
        {
            coordVec.emplace_back( x, y, z, milSec );
            sort_coord_vector( coordVec );
        }
        void length( )
        {
            data_t len = calc_total_dist_of_coords( coordVec );
            std::cout << "Total length of coord vector is " << len << std::endl;    
        }
        void reverse( )
        {
            reverse_coord_vector( coordVec );   
        }
};

#endif // #ifndef DATA_H