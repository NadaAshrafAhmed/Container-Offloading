#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED
#include "transportation.h"

class truck : public transportation{

public:

    truck() ;
    truck( int , string , int ) ;

    ~truck() ;

};

#endif // TRUCK_H_INCLUDED
