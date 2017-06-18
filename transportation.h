#ifndef TRANSPORTATION_H_INCLUDED
#define TRANSPORTATION_H_INCLUDED
#include <string>
#include <iostream>
using namespace std ;

class transportation{

protected:

    string type ;
    int serial ;
    int weight ;

public:

    transportation() ;
    transportation( int , string , int ) ;
    transportation( const transportation& ) ;

    void set_type( string ) ;
    void set_serial( int ) ;
    void set_weight( int ) ;

    string get_type() const ;
    int get_serial() const ;
    int get_weight() const ;

    transportation& operator =( const transportation& ) ;
    bool operator >( const transportation& ) ;
    friend istream& operator >>( istream&  , transportation& );
    friend ostream& operator <<( ostream&  , transportation& );

    ~transportation() ;

};

#endif // TRANSPORTATION_H_INCLUDED
