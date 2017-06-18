#include "normal.h"

normal::normal():container(){}
normal::normal( int a , string b , int c , int d , int e ):container( a , b , c , d , e ){}

void normal::t( transportation** a , int n ){

    for( int i=0 ; i<n ; i++ ){

        if( weight<=a[i]->get_weight() ){

            a[i]->set_weight( a[i]->get_weight()-weight ) ;
            trans = a[i]->get_type() ;
            trans_num = a[i]->get_serial() ;
            break ;
        }
    }
}

normal::~normal(){}
