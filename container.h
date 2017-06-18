#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED
#include "transportation.h"
using namespace std ;

class container{

protected:

    int snum ;
    string type ;
    int toxic ;
    int exp ;
    int weight ;
    string trans ;
    int ship_num ;
    int trans_num ;

public:

    container() ;
    container( int , string , int , int , int ) ;
    container( container& ) ;

    void set_snum( int ) ;
    void set_type( string ) ;
    void set_toxic( int ) ;
    void set_exp( int ) ;
    void set_weight( int ) ;
    void set_trans( string ) ;
    void set_ship_num( int ) ;
    void set_trans_num( int ) ;

    int get_snum() const ;
    string get_type() const ;
    int get_toxic() const ;
    int get_exp() const ;
    int get_weight() const ;
    string get_trans() const ;
    int get_ship_num() const ;
    int get_trans_num() const ;

    container& operator = (const container& );
    friend istream& operator>>( istream&  , container& );
    friend ostream& operator<<( ostream&  , container& );
    virtual void t(transportation** , int )=0 ;

    virtual~container() ;

};

#endif // CONTAINER_H_INCLUDED
