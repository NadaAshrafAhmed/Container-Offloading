#ifndef CAPACITY_H_INCLUDED
#define CAPACITY_H_INCLUDED
#include <iostream>
using namespace std ;

class capacity
{

private:

    int toxic ;
    int exp ;
    int refr ;
    int heavy ;
    int norm ;
    int all ;
    int weight ;

public:

    capacity() ;
    capacity( int , int , int , int , int , int );

    void set_toxic( int ) ;
    void set_exp( int ) ;
    void set_refr( int ) ;
    void set_heavy( int ) ;
    void set_norm() ;
    void set_all( int ) ;
    void set_weight( int ) ;

    int get_toxic() const ;
    int get_exp() const ;
    int get_refr() const ;
    int get_heavy() const ;
    int get_norm() const ;
    int get_all() const ;
    int get_weight() const ;

    friend istream &operator>>( istream&  , capacity& );
    friend ostream &operator<<( ostream&  , capacity );
    ~capacity() ;

};


#endif // CAPACITY_H_INCLUDED
