#include <iostream>
#include <ostream>
#include "object.h"
#include <vector>
using namespace std;
ob_array w;
void info()
{
    cout<<"\n 1) Add";
    cout<<"\n 2) Remove_at(pos)";
    cout<<"\n 3) Insert_at(pos, object)";
    cout<<"\n 4) Get_Object(pos)";
    cout<<"\n 5) Get_Size";
    cout<<"\n 6) Remove_all";
    cout<<"\n 7) Display";
    cout<<"\n 8) Exit";
}
void array_preset()
{
    w.add(new point(3,7));
    w.add(new point(5,0));
    w.add(new complex(2,-2));
    w.add(new point(3,10));
    w.add(new complex(16,5));
    w.add(new complex(7,-9));
    w.add(new point(2,0));
    w.add(new complex(0,6));
    w.add(new point(0,0));
    w.add(new complex(7,3));
}
void tree()
{
    int choice,choice2,x,y,i;
    do
    {
        w.display();
        info();
        cout<<"\n >> ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\n Add a point(1) or a complex(2)";
            cout<<"\n >> ";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                cout<<"\n Enter the point's coordinates(x *ENTER* y):\n x= ";
                cin>>x;
                cout<<" y= ";
                cin>>y;
                w.add(new point(x,y));
                break;
            case 2:
                cout<<"\n Enter the complex's characteristics(real *ENTER* imaginary):\n Real= ";
                cin>>x;
                cout<<" Imaginary= ";
                cin>>y;
                w.add(new complex(x,y));
                break;
            }
            break;
        case 2:
            cout<<"\n Enter the position of the object you want to remove: ";
            cout<<"\n >> ";
            cin>>choice2;
            w.remove_at(choice2);
            break;
        case 3:
            cout<<"\n Insert a point(1) or a complex(2): ";
            cout<<"\n >> ";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                cout<<"\n Enter the point's coordinates(x *ENTER* y):\n x= ";
                cin>>x;
                cout<<" y= ";
                cin>>y;
                cout<<" position= ";
                cin>>i;
                w.insert_at(i,new point(x,y));
                break;
            case 2:
                cout<<"\n Enter the complex's characteristics(real *ENTER* imaginary):\n Real= ";
                cin>>x;
                cout<<" Imaginary= ";
                cin>>y;
                cout<<" Position= ";
                cin>>i;
                w.insert_at(i,new complex(x,y));
                break;

            }
            break;
        case 4:
            cout<<"\n Position= ";
            cin>>choice2;

            if( dynamic_cast<complex*>( w.get_at(choice2) ) )
                cout<<" Obiectul de pe pozitia "<<choice2<<" este "<<*(static_cast<complex*>(w.get_at(choice2)));
            else if(dynamic_cast<point*>( w.get_at(choice2) ))
                cout<<" Obiectul de pe pozitia "<<choice2<<" este "<<*(static_cast<point*>(w.get_at(choice2)));
            break;
        case 5:
            cout<<"\n The array has "<<w.getsize()<<" objects.";
            break;
        case 6:
            cout<<"\n All the objects have been deleted!";
            w.remove_all();
            break;
        case 7:
            break;
        }
    }
    while(choice!=8);
}
int main()
{
     ///array_preset(); ///   <- vector prestabilit
     tree(); /// <- arbore cu toate functiile din ob_array + citirea, memorarea si afisarea obiectelor


    return 0;
}
