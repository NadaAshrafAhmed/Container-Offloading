#include "refrigerated.h"

refrigerated::refrigerated():heavy(){}
refrigerated::refrigerated( int a , string b , int c , int d , int e ):heavy( a , b , c , d , e ){}

void refrigerated::t( transportation** a , int n ){

    bool check = false ;
    for( int i=0 ; i<n ; i++ ){

        if( a[i]->get_type()=="Train"&&weight <= a[i]->get_weight() ){
			a[i]->set_weight( a[i]->get_weight()-weight ) ;
          	trans = "Train" ;
            trans_num = a[i]->get_serial() ;
          	check = true ;
         	break ;
        }
    }
    if ( !check ){

        for( int i=0 ; i<n ; i++ ){

            if( weight<=a[i]->get_weight() ){

                a[i]->set_weight( a[i]->get_weight()-weight ) ;
                trans = a[i]->get_type() ;
                trans_num = a[i]->get_serial() ;
                break ;
            }
        }
    }
}

refrigerated::~refrigerated(){}
