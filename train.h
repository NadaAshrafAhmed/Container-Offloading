#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED
#include "transportation.h"

class train: public  transportation{

public:

    train() ;
    train( int , string , int ) ;

    ~train() ;

};

#endif // TRAIN_H_INCLUDED
