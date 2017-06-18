#include "container.h"

container::container(){

    snum = 0 ;
    type = "" ;
    toxic = 0 ;
    exp = 0 ;
    weight = 0 ;
    trans = "" ;
    ship_num = -1 ;
    trans_num = -1 ;
}
container::container( int a , string b , int c , int d , int e ){

    snum = a ;
    type = b ;
    toxic = c ;
    exp = d ;
    weight = e ;
    trans = "" ;
    ship_num = -1 ;
    trans_num = -1 ;
}
container::container( container& c ){

    snum =c.snum;
    type=c.type ;
    toxic=c.toxic ;
    exp =c.exp;
    weight=c.weight ;
    trans=c.trans ;
    ship_num=c.ship_num ;
    trans_num=c.trans_num ;
}

void container::set_snum( int a ){

    snum = a ;
}
void container::set_type( string a ){

    type = a ;
}
void container::set_toxic( int a ){

    toxic = a ;
}
void container::set_exp( int a ){

    exp = a ;
}
void container::set_weight( int a ){

    weight = a ;
}
void container::set_trans( string a ){

    trans = a ;
}
void container::set_ship_num( int a ){

    ship_num = a ;
}
void container::set_trans_num( int a ){

    trans_num = a ;
}

int container::get_snum() const {

    return snum ;
}
string container::get_type() const {

    return type ;
}
int container::get_toxic() const {

    return toxic ;
}
int container::get_exp() const {

    return exp ;
}
int container::get_weight() const {

    return weight ;
}
string container::get_trans() const {

    return trans ;
}
int container::get_ship_num() const {

    return ship_num ;
}
int container::get_trans_num() const {

    return trans_num ;
}

container& container::operator = (const container& c){

    snum =c.snum;
    type=c.type ;
    toxic=c.toxic ;
    exp =c.exp;
    weight=c.weight ;
    trans=c.trans ;
    ship_num=c.ship_num ;
    trans_num=c.trans_num ;
    return *this;
}
istream& operator>>( istream& in , container& x ){

    in >> x.snum >> x.toxic >> x.exp >> x.weight ;

    return in ;
}
ostream& operator<<( ostream& in , container& x ){

    in << x.type << " " << x.snum << " " << x.toxic << " " << " " << x.exp << " " << x.weight ;

    return in ;
}

container::~container(){}
