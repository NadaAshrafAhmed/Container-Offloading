#ifndef REFRIGERATED_H_INCLUDED
#define REFRIGERATED_H_INCLUDED
#include "heavy.h"

class refrigerated : public heavy {

public:

    refrigerated() ;
    refrigerated( int , string , int , int , int ) ;

    void t( transportation** , int ) ;

    ~refrigerated() ;

};

#endif // REFRIGERATED_H_INCLUDED
