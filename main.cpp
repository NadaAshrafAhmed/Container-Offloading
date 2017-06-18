#include "systems.h"
#include <algorithm>

int main()
{
  bool check = true ;
  while( check ){
    ifstream input( "in.txt" ) ;
    int x , y , z ;

    input >> x ;

    systems st ;
    st.set_num_ships( x ) ;

    for ( int i=0 ; i<x ; i++ )
    {
    	ship* s =new ship ;
        input >> *s;
        st.add_ship( s ) ;
    }

    string type ;
    input >> y ;

    st.set_num_trans( y ) ;

    for ( int i=0 ; i<y ; i++ )
    {

        input >> type ;
        if( type=="Train" )
        {
            train* t1 = new train ;
            t1->set_type( type ) ;
            input >> *t1 ;
            st.add_trans( t1 ) ;
        }
        else
        {
            truck* t2=new truck ;
            t2->set_type( type ) ;
            input >> *t2 ;
            st.add_trans( t2 ) ;
        }
    }


    input >> z ;
	st.set_num_conts( z ) ;

    for( int i=0 ; i<z ; i++ )
    {
		input >> type ;
        if( type=="Normal" )
        {
            container* c1=new normal ;
            c1->set_type( type ) ;
            input >> *c1 ;
            st.add_cont( c1 ) ;
        }
        else if( type=="Heavy" )
        {
            container* c2=new heavy ;
            c2->set_type( type ) ;
            input >> *c2 ;
            st.add_cont( c2 ) ;
        }
        else if ( type=="Refrigerated" )
        {
            container* c3 =new refrigerated;
            c3->set_type( type ) ;
            input >> *c3 ;
            st.add_cont( c3 ) ;
        }
        else{

            cout << "The type of the Container is not included in this system it should be Normal or Heavy or Refrigerated." << endl ;
        }
    }

	for (int i=0;i<10;i++)
	{
		int x= (rand() %5 )+1;
		//output<<x<<endl;
		//st.offloading( x ) ;
		try{

        st.offloading(x);

    }catch( int p ){

        if( p==1 ){

            cout << "There is no such a Container to be offloaded." << endl << endl ;
        }

        if( p==2 ){

            cout << "Container#" << x <<"couldn't be able to be offloaded on any vehicle."<< endl ;
        }
        if( p==4 ){

            cout << "Container#" << x <<"couldn't be able to be offloaded on any ship."<< endl << endl ;
        }
    }
	}

	/*refrigerated r( 6 , "Refrigerated" , 0 , 150 , 500 ) ;
	capacity q( 250 , 600 , 10 , 7 , 20 , 1000 ) ;
	ship f( 5 , q ) ;
	train t( 11 , "Train" , 2500 ) ;

    st.add_cont( &r ) ;
    st.add_ship( &f ) ;
    st.add_trans( &t ) ;
    st.remove_cont( 5 ) ;
    st.remove_ship( 5 ) ;
    st.remove_trans( 5 ) ;
    st.remove_cont( 5 ) ;
    st.remove_ship( 5 ) ;
    st.remove_trans( 5 ) ;
    //st.print() ;

    st.offloading( 5 ) ;*/

    input.close();
    bool m=true;
    while (m)
    {
    	cout<<"1)Offload Container\n2)Add Container\n3)Add Ship\n4)Add Vehicle\n5)Remove Container\n6)Remove Ship\n7)Remove Vehicle\n8)Print\n9)New System\n10)Exist";
		cin>>x;
		switch(x)
		{
			case 1:
			{
				cout<<"Enter the number of the container: ";
				cin >> y ;
				try{

				        st.offloading(y);

				    }catch( int p ){

				        if( p==1 ){

				            cout << "There is no such a Container to be offloaded." << endl << endl ;
				        }

				        if( p==2 ){

				            cout << "Container#" << x <<"couldn't be able to be offloaded on any vehicle."<< endl ;
				        }
				        if( p==4 ){

				            cout << "Container#" << x <<"couldn't be able to be offloaded on any ship."<< endl << endl ;
				        }
				    }
				break;
			}
			case 2:
			{
				bool a = true ;
				cout<<"Enter the type of the container: ";
				cin>>type;
				container* c;
				if( type=="Normal" )
       			{
         			c=new normal ;
       			}
        		else if( type=="Heavy" )
       			{
            		c=new heavy ;
        		}
        		else if (type=="Refrigerated")
        		{
        		    c=new refrigerated;
       		 	}
       		 	else{

                    cout << "The type of the Container is not included in this system it should be Normal or Heavy or Refrigerated." << endl ;
                    a = false ;
       		 	}
       		 	if ( a ){
       		 	c->set_type( type ) ;
       		 	cout<<"Enter Serial number, Toxic, Explosive, Weight.\n";
            	cin >> *c ;

            	st.add_cont( c ) ;
                }
            	break;
			}
       		case 3:
       		{
       			cout<<"Enter Serial number, Toxic, Explosive, Heavy, Refrigerated, All, Weight.\n";
       		 	ship*h=new ship ;
		        cin >> *h;

        		st.add_ship( h ) ;
        		break;
			}
       		case 4:
       		{
       			cout<<"Enter the type of the vehicle: ";
        		cin >> type ;
        		transportation* t;
       		 	if( type=="Train" )
        		{
            		t= new train ;
        		}
       		 	else if( type=="Truck" )
      		  	{
            		t=new truck ;
        		}
        		t->set_type( type ) ;
        		cout<<"Enter Serial number, Weight.\n";
            	cin >> *t ;

            	st.add_trans( t ) ;
            	break;
			}
            case 5:
            {
            	cout<<"Enter the number of the container: ";
            	cin>>y;

            	st.remove_cont(y);
       		 	break;
			}
       		case 6:
       		{
       			bool a = false ;
       			cout<<"Enter the number of the ship: ";
            	cin>>y;

            	st.remove_ship(y);
       		 	break;
			}
       		case 7:
       		{
       			bool a = false ;
       			cout<<"Enter the number of the vehicle: ";
            	cin>>y;

            	st.remove_trans(y);
       		 	break;
			}
       		case 8:
       		{
       			st.print();
       			break;
			}
			case 9:
            {
                m = false ;
                break ;
            }
			case 10:
			{
				m=false ;
				check = false ;
				break ;
			}
       		default:
       		{
       			cout<<"Invalid choice.\n";
       			break ;
			}
		}
	}
  }
    return 0;
}
