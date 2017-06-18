#ifndef NORMAL_H_INCLUDED
#define NORMAL_H_INCLUDED
#include "container.h"

class normal : public container {

public :

    normal() ;
    normal( int , string , int , int , int ) ;

    void t( transportation** , int ) ;

    virtual~normal() ;

};

#endif // NORMAL_H_INCLUDED
