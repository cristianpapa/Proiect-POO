#include <iostream>
#include <fstream>
#include <cmath>
#include "Complex.h"
using namespace std;
ifstream in("date.in");

int main()
{


   /* Complex a(3,2);
    vector_complex zero(5,a);
    //cout<<zero;
    Complex b(1,3);
    Complex h(a);
    cout<<" 2*A= "<<a*2<<endl;
    cout<<" A-B= "<<a-b<<endl;
    vector_complex d(5,Complex(3,5));
    cout<<" d= "<<d;
    cout<<"\n h= "<<h;
    vector_complex e;
    in>>e;
    cout<<endl<<" E= "<<e;
    Complex f=e.suma();
    cout<<endl<<" Suma elementelor din E= "<<f<<endl;
        */
    Complex a(3,5);
    vector_complex b(5,a);
    cout<<"-----------------------------------------------------------------------------------------------------------------------\n\n";
    cout<<" a= "<<a<<endl;
    cout<<" b= "<<b<<"  <-- initializare cu un Complex(a) pe toate componentele";
    vector_complex c(b);
    cout<<"\n c= "<<c<<"  <-- constructor de copiere";
    vector_complex d;
    in>>d;
    cout<<"\n d= "<<d<<"       <-- supraincarcare << si >>";

    cout<<"\n vm= "<<d.vector_module()<<"  <-- vector de module(d)";
    d.sortare_module();
    cout<<"\n d= "<<d<<"       <-- vectorul d sortat dupa module(crescator)";
    cout<<"\n sum= "<<d.suma()<<"                                     <-- suma elementelor din d ";
    vector_complex e;
    ///
    vector_complex v1,v2;
    in>>v1;
    in>>v2;
    cout<<endl<<endl<<" V1= "<<v1<<endl<<" V2= "<<v2<<"\n Produs scalar= "<<v1*v2<<endl;
    ///

    //cout<<" "<<e.suma()<<endl;
  /*  vector_complex g;
    int n;
    in_out test;
    in>>n;
    test.citire(n,in,&g);
    //test.afisare(n,cout,g);
    */
    return 0;
}
