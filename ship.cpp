#include "ship.h"

ship::ship(){

    serial = 0 ;
    c.set_toxic(0) ;
    c.set_exp(0) ;
    c.set_refr(0) ;
    c.set_heavy(0) ;
    c.set_all(0) ;
    c.set_norm() ;
    c.set_weight(0) ;
}
ship::ship ( int a , capacity & b ){

    serial = a ;
    c = b ;
}
ship::ship( ship& s ){

    serial = s.serial ;
    c = s.c ;
}

void ship::set_serial( int a ){

    serial = a ;
}
void ship::set_capacity( capacity& d ){

    c = d ;
}

int ship::get_serial() const {

    return serial ;
}
capacity ship::get_capacity() const {

    return c ;
}

ship& ship::operator = ( const ship& s ){

    serial = s.serial ;
    c = s.c ;
    return *this ;
}
bool ship::operator >( const ship& s ){

    if( c.get_weight()>s.c.get_weight() ){

        return true ;
    }
    else{

        return false ;
    }
}

istream& operator >> (istream& in ,ship& s)
{
	int x;
	capacity c;
	in>>x>>c;
	s.set_serial(x);
	s.set_capacity(c);
	return in;
}
ostream& operator << (ostream& out, ship& s)
{
	out<<s.get_serial()<<" "<<s.get_capacity();
}

ship::~ship(){}
