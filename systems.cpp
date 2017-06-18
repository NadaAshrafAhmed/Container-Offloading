#include "systems.h"

systems::systems()
{

    num_conts = 0 ;
    num_ships = 0 ;
    num_trans = 0 ;
    conts = NULL ;
    ships = NULL ;
    trans = NULL ;
    counter_c = 0 ;
    counter_s = 0 ;
    counter_t = 0 ;
}
systems::systems( int a , int b , int c )
{

    num_conts = c ;
    num_ships = a ;
    num_trans = b ;
    conts = new container*[c] ;
    ships = new ship*[a] ;
    trans = new transportation*[b] ;
    counter_c = 0 ;
    counter_s = 0 ;
    counter_t = 0 ;
}

void systems::set_num_conts( int a )
{

    num_conts = a ;
    conts = new container*[a] ;
}
void systems::set_num_ships( int a )
{

    num_ships = a ;
    ships = new ship*[a] ;
}
void systems::set_num_trans( int a )
{

    num_trans = a ;
    trans = new transportation*[a] ;
}

int systems::get_num_conts() const
{

    return num_conts ;
}
int systems::get_num_ships() const
{

    return num_ships ;
}
int systems::get_num_trans() const
{

    return num_trans ;
}
void systems:: print() const
{

	cout<<num_ships<<endl;
	for (int i=0;i<num_ships;i++)
	{
		cout<< ships[i]->get_serial()<<" "<< ships[i]->get_capacity()<<endl;
	}
	cout<<num_trans<<endl;
	for (int i=0;i<num_trans;i++)
	{
		cout<< *(trans[i])<<endl;
	}
	cout<<num_conts<<endl;
	for (int i=0;i<num_conts;i++)
	{
		cout<< *(conts[i])<<endl;
	}

}

void systems::offloading( int x )
{
	sort_list( ships , num_ships ) ;
    sort_list( trans , num_trans ) ;

    container* a;

    bool k = false ;

    for (int i=0; i<num_conts; i++ )
    {

        if(conts[i]->get_snum()==x)
        {

       	   if(conts[i]->get_type()=="Normal")
           {
               a=new normal;
           }
           else if(conts[i]->get_type()=="Heavy")
           {
               a=new heavy;
           }
           else if(conts[i]->get_type()=="Refrigerated")
           {
               a=new refrigerated;
           }
           *a=*conts[i];
            k = true ;
           break;
        }
    }

    if(k){
    a->t( trans , num_trans ) ;
    for( int i=0 ; i<num_ships ; i++ )
    {

        capacity x=ships[i]->get_capacity();
        if( x.get_weight()>=a->get_weight() && x.get_toxic()>=a->get_toxic() &&x.get_exp()>=a->get_exp() )
        {

            if(( a->get_type()=="Normal" && x.get_norm()>0 )||
                    ( a->get_type()=="Heavy" && x.get_heavy()>0 )||
                    ( a->get_type()=="Refrigerated" && x.get_refr()>0 ))
            {

                x.set_weight(x.get_weight()-a->get_weight() ) ;
                x.set_toxic(x.get_toxic()-a->get_toxic() ) ;
                x.set_exp(x.get_exp()-a->get_exp() ) ;
                x.set_all(x.get_all()-1) ;
                a->set_ship_num( ships[i]->get_serial() ) ;
                if( a->get_type()=="Normal" && x.get_norm()>0 )
                {

                    x.set_norm() ;
                }
                else if( a->get_type()=="Heavy" && x.get_heavy()>0 )
                {

                    x.set_heavy(x.get_heavy()-1) ;
                }
                else if ( a->get_type()=="Refrigerated" && x.get_refr()>0 )
                {

                    x.set_refr(x.get_refr()-1) ;
                }
                ships[i]->set_capacity(x);
                break;
            }
        }
    }
    if( a->get_trans_num()!=-1 ){

            cout << "Container# "<<a->get_snum()<<" has been offloaded on "<<a->get_trans()<<"# "<<a->get_trans_num()<< endl ;
        }
        else{

            throw 2 ;
        }

        if( a->get_ship_num()!=-1 ){

            cout << "Container#" <<a->get_snum()<<" has been offloaded on ship# "<<a->get_ship_num()<< endl << endl ;
        }
        else{

            throw 4 ;
        }

    }
    else{

        throw 1 ;
    }
}
void systems::add_cont( container* c )
{
    bool k = false ;
    for( int i=0 ; i<counter_c ; i++ ){

        if( c->get_snum()==conts[i]->get_snum() ){

            cout << "This Container is already exist." << endl ;
            k = true ;
            break ;
        }
    }
    if(!k){
    if( counter_c<num_conts ){

        if(c->get_type()=="Normal")
           {
               conts[counter_c]=new normal;
           }
           else if(c->get_type()=="Heavy")
           {
               conts[counter_c]=new heavy;
           }
           else if(c->get_type()=="Refrigerated")
           {
               conts[counter_c]=new refrigerated;
           }
           *conts[counter_c]=*c;
    }
    else{

        container** temp=new container*[num_conts] ;
        for( int i=0 ; i<num_conts ; i++ )
        {

            temp[i] = conts[i] ;
        }
        if(num_conts>0)
        {
            delete[] conts ;
        }
        conts = new container*[num_conts+1] ;
        for( int i=0 ; i<num_conts ; i++ )
        {

            conts[i] = temp[i] ;
        }
        delete[] temp;
        conts[num_conts] = c ;
        num_conts ++ ;
    }
    counter_c ++ ;
    //cout << num_conts << " " << counter_c << endl ;
    cout << "The Container has been successfully added." << endl ;
    }
}
void systems::remove_cont( int a)
{

    int indx=-1;
    for (int i=0; i<num_conts; i++)
    {
        if(conts[i]->get_snum()==a)
        {
            indx=i;
            break;
        }
    }
    if(indx!=-1)
    {
        if (conts[indx]->get_trans_num()!=-1)
        {
            for (int i=0; i<num_trans; i++)
            {
                if(trans[i]->get_serial()==conts[indx]->get_trans_num())
                {
                    trans[i]->set_weight(trans[i]->get_weight()+conts[indx]->get_weight());
                    break;
                }
            }
        }
        capacity x;
        if(conts[indx]->get_ship_num()!=-1)
        {
            for (int i=0; i<num_ships; i++)
            {
                if(ships[i]->get_serial()==conts[indx]->get_ship_num())
                {
                    x=ships[i]->get_capacity();
                    x.set_weight(x.get_weight()+conts[indx]->get_weight());
                    x.set_toxic(x.get_toxic()+conts[indx]->get_toxic());
                    x.set_exp(x.get_exp()+conts[indx]->get_exp());
                    x.set_all(x.get_all()+1);
                    if(conts[indx]->get_type()=="Normal")
                    {
                        x.set_norm();
                    }
                    else if(conts[indx]->get_type()=="Heavy")
                    {
                        x.set_heavy(x.get_heavy()+1);
                    }
                    else if(conts[indx]->get_type()=="Refrigerated")
                    {
                        x.set_refr(x.get_refr()+1);
                    }
                    ships[i]->set_capacity(x);
                    break;
                }
            }
        }
        container** temp=new container*[num_conts-1];
        for (int i=0,j=0; i<num_conts; i++)
        {
            if(i!=indx)
            {
                temp[j]=conts[i];
                j++;
            }
        }
        if(num_conts>0)
        {
            delete[] conts;
        }
        num_conts--;
        counter_c-- ;
        conts=new container*[num_conts];
        for (int i=0; i<num_conts; i++)
        {
            conts[i]=temp[i];
        }
        delete[] temp;
        //cout << num_conts << " " << counter_c << endl ;
        cout << "The Container has been successfully removed." << endl ;
    }
    else{

        cout << "There is no such Container with this serial number." << endl ;
    }
}
void systems::add_ship( ship* s )
{
    bool k = false ;
    for( int i=0 ; i<counter_s ; i++ ){

        if( s->get_serial()==ships[i]->get_serial() ){

            cout << "This Ship is already exist." << endl ;
            k = true ;
            break ;
        }
    }

    if(!k){
    if(counter_s<num_ships)
    {
        ships[counter_s] = new ship;
        *ships[counter_s]=*s;

    }
    else
    {
        ship**temp=new ship*[num_ships];
        for (int i=0; i<num_ships; i++)
        {
            temp[i]=ships[i];
        }
        if(num_ships>0)
        {
            delete[] ships;
        }
        ships=new ship*[num_ships+1];
        for (int i=0; i<num_ships; i++)
        {
            ships[i]=temp[i];
        }
        delete[] temp;
        ships[num_ships]=s;
        num_ships++;
    }
    counter_s++;
    cout << "The Ship has been successfully added." << endl ;
    }
}
void systems::remove_ship( int a)
{
    int indx=-1;
    for (int i=0; i<num_ships; i++)
    {
        if(ships[i]->get_serial()==a)
        {
            indx=i;
            break;
        }
    }
    if(indx!=-1)
    {
        for (int i=0; i<num_conts; i++)
        {
            if (conts[i]->get_ship_num()==ships[indx]->get_serial())
            {
                conts[i]->set_ship_num(-1);
            }
        }
        ship** temp=new ship*[num_ships-1];
        for (int i=0,j=0; i<num_ships; i++)
        {
            if(i!=indx)
            {
                temp[j]=ships[i];
                j++;
            }
        }
        delete[] ships;
        num_ships--;
        counter_s--;
        ships=new ship*[num_ships];
        for (int i=0; i<num_ships; i++)
        {
            ships[i]=temp[i];
        }
        delete[] temp;
        cout << "The Ship has been successfully removed." << endl ;
    }
    else{

        cout << "There is no such a Ship with this serial number." << endl ;
    }
}
void systems::add_trans( transportation* t )
{
    bool k = false ;
    for( int i=0 ; i<counter_t ; i++ ){

        if( t->get_serial()==trans[i]->get_serial() ){

            cout << "This Vehicle is already exist." << endl ;
            k = true ;
            break ;
        }
    }

    if(!k){
    if(counter_t<num_trans)
    {
        trans[counter_t] = new transportation;
        *trans[counter_t] = *t;
    }
    else
    {
        transportation** temp=new transportation*[num_trans];
        for (int i=0; i<num_trans; i++)
        {
            temp[i]=trans[i];
        }
        if(num_trans>0)
        {
            delete[] trans;
        }
        trans=new transportation*[num_trans+1];
        for (int i=0; i<num_trans; i++)
        {
            trans[i]=temp[i];
        }
        delete[]temp;
        trans[num_trans]=t;
        num_trans++;
    }
    counter_t++;
    cout << "The Vehicle has been successfully added." << endl ;
    }
}
void systems::remove_trans( int a)
{
    int indx=-1;
    for (int i=0; i<num_trans; i++)
    {
        if(trans[i]->get_serial()==a)
        {
            indx=i;
            break;
        }
    }
    if(indx!=-1)
    {
        for (int i=0; i<num_conts; i++)
        {
            if (conts[i]->get_trans_num()==trans[indx]->get_serial())
            {
                conts[i]->set_trans_num(-1);
            }
        }
        transportation** temp=new transportation*[num_trans-1];
        for (int i=0,j=0; i<num_trans; i++)
        {
            if(i!=indx)
            {
                temp[j]=trans[i];
                j++;
            }
        }
        delete[] trans;
        num_trans--;
        counter_t--;
        trans=new transportation*[num_trans];
        for (int i=0; i<num_trans; i++)
        {
            trans[i]=temp[i];
        }
        delete[] temp;
        cout << "The Vehicle has been successfully removed." << endl ;
    }
    else{

        cout << "There is no such a Vehicle with this serial number." << endl ;
    }
}

template <class T>
T systems ::sort_list( T* arr , int n )
{
	for( int i=0 ; i<n-1 ; i++ )
    {
        for( int j=i+1 ; j<n ; j++ )
        {
            if( *(arr+j)>*(arr+i) )
            {

                T temp = *(arr+i) ;
                *(arr+i) = *(arr+j) ;
                *(arr+j) = temp ;
            }
        }
    }
}

systems::~systems()
{
    delete[] conts ;
    delete[] ships ;
    delete[] trans ;
}
