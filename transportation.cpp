#include "transportation.h"

transportation::transportation(){

    type = "" ;
    serial = 0 ;
    weight = 0 ;
}
transportation::transportation( int a , string b , int c ){

    type = b ;
    serial = a ;
    weight = c ;
}
transportation::transportation( const transportation& t ){

    type = t.type ;
    serial = t.serial ;
    weight = t.weight ;
}

void transportation::set_type( string a ){

    type = a ;
}
void transportation::set_serial( int a ){

    serial = a ;
}
void transportation::set_weight( int a ){

    weight = a ;
}

string transportation::get_type() const {

    return type ;
}
int transportation::get_serial() const {

    return serial ;
}
int transportation::get_weight() const {

    return weight ;
}

transportation& transportation::operator =( const transportation& t ){

    type = t.type ;
    serial = t.serial ;
    weight = t.weight ;

    return *this ;
}
 bool transportation::operator >( const transportation& t ){

    if( weight>t.weight ){

        return true ;
    }
    else{

        return false ;
    }
 }

istream& operator>>( istream& in  , transportation& x ){

    in >> x.serial >> x.weight ;

    return in ;
}
ostream& operator<<( ostream& in  , transportation& x ){

    in << x.type << " " << x.serial << " " << x.weight ;

    return in ;
}

transportation::~transportation(){}
