#include "capacity.h"

capacity::capacity(){

    toxic = 0 ;
    exp = 0 ;
    refr = 0 ;
    heavy = 0 ;
    norm = 0 ;
    all = 0 ;
    weight = 0 ;
}
capacity::capacity( int a , int b , int c , int d , int e , int f ){

    toxic = a ;
    exp = b ;
    refr = c ;
    heavy = d ;
    all = e ;
    norm = e - ( c+d ) ;
    weight = f ;

}

void capacity::set_toxic( int a ){

    toxic = a ;
}
void capacity::set_exp( int a ){

    exp = a ;
}
void capacity::set_refr( int a ){

    refr = a ;
}
void capacity::set_heavy( int a ){

    heavy = a ;
}
void capacity::set_all( int a ){

    norm = a ;
}
void capacity::set_norm(){

    norm = all - ( heavy + refr ) ;
}
void capacity::set_weight( int a ){

    weight = a ;
}

int capacity::get_toxic() const {

    return toxic ;
}
int capacity::get_exp() const {

    return exp ;
}
int capacity::get_refr() const {

    return refr ;
}
int capacity::get_heavy() const {

    return heavy ;
}
int capacity::get_all() const {

    return all ;
}
int capacity::get_norm() const {

    return norm ;
}
int capacity::get_weight() const{

    return weight ;
}

istream& operator>> ( istream& in , capacity& c ){

    in >> c.toxic >> c.exp >> c.heavy >> c.refr >> c.all >> c.weight ;

    c.set_norm() ;

    return in ;
}
ostream& operator<< ( ostream& in , capacity c ){

    in << c.toxic<<"\t" << c.exp <<"\t" << c.heavy <<"\t" << c.refr <<"\t" << c.all <<"\t" << c.weight ;

    return in ;
}

capacity::~capacity(){}
