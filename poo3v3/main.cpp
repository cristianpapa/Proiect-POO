#include <iostream>
#include <ostream>
#include "automobil.h"
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int main()
{
    int id,op;
    cout<<"\n\n\n -----------------------------------------------AUTOVIT.RO---------------------------------------------\n\n\n\n";
    vanzare v;
    v.display_stoc();
    do
    {
        cout<<"\n\n Introduceti ID-ul automobilului pe care doriti sa-l achizitionati (0->exit): ";cin>>id;
        v.buy_car(id);
        cout<<"\n Acestea sunt automobilele cumparate de dvs: \n";
        v.display_sold();
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        v.display_stoc();

    }while(id!=0);


    //vector<automobil*>w;
    //v.add_car();
    //v.display_stare();
    //v.get_car();
    //v.display_stare();
    //cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
    //automobil *a=v.del_car(1);
    //cout<<*a<<endl;
    //w.push_back(v.del_car(1));

}
