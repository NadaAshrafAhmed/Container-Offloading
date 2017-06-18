#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED
#include "capacity.h"

class ship{

private:
    int serial ;
    capacity c ;

public:

    ship() ;
    ship ( int , capacity & ) ;
    ship( ship& ) ;

    void set_serial( int ) ;
    void set_capacity( capacity& ) ;

    int get_serial() const ;
    capacity get_capacity() const ;


    ship& operator =( const ship& ) ;
    bool operator >( const ship& ) ;
    friend istream& operator >> (istream& ,ship& );
	friend ostream& operator << (ostream& ,ship& );
    ~ship() ;

};


#endif // SHIP_H_INCLUDED
