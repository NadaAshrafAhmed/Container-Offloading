#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include <iostream>
#include "refrigerated.h"
#include "ship.h"
#include "train.h"
#include "truck.h"
#include <fstream>

//ofstream output("out.txt");

class system{

private:

    int num_conts ;
    int num_ships ;
    int num_trans ;
    container** conts ;
    ship** ships ;
    transportation** trans ;
    int counter_c ;
    int counter_s ;
    int counter_t ;

public:

    system() ;
    system( int , int , int ) ;

    void set_num_conts( int ) ;
    void set_num_ships( int ) ;
    void set_num_trans( int ) ;

    int get_num_conts() const ;
    int get_num_ships() const ;
    int get_num_trans() const ;

	void print() const;

    void offloading( int ) ;
    void add_cont( container* ) ;
    void remove_cont( int ) ;
    void add_ship( ship* ) ;
    void remove_ship( int ) ;
    void add_trans( transportation* ) ;
    void remove_trans( int ) ;

    template <class T>
	T sort_list( T* , int ) ;

    ~system() ;

};

#endif // systems_H_INCLUDED
