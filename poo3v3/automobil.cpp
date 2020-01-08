#include "automobil.h"
#include <iostream>
#include <iterator>
#include <set>
/// Automobil
automobil::automobil():nume("Automobil"), an_fabricatie(2020), lungime(3.55),pret(0) {}
automobil::automobil(string s,int an, float l,double p):nume(s),an_fabricatie(an),lungime(l),pret(p){}
void automobil::display(){cout<<endl<<nume<<endl<<an_fabricatie<<endl<<lungime<<endl<<pret<<endl;}
double automobil::get_price(){return pret;}
istream& operator>>(istream& input,automobil &ob)
{
    input>>ob.nume>>ob.an_fabricatie>>ob.lungime>>ob.pret;
    return input;
}
void automobil::print(ostream& output) const
{
    output<<nume<<endl<<an_fabricatie<<endl<<lungime<<endl<<pret;
}
ostream& operator<<(ostream& output,const automobil &ob)
{
    ob.print(output);
    return output;
}
automobil& automobil::operator=(const automobil& ob)
{
    if(this==&ob) return *this;
    nume=ob.nume;
    an_fabricatie=ob.an_fabricatie;
    lungime=ob.lungime;
    pret=ob.pret;
    return *this;
}

/// Mini

mini::mini():automobil(),motor(1000),cp(50) {}
mini::mini(string s,int an,float lung, int cap,int cai,double p):automobil(s,an,lung,p),motor(cap),cp(cai) {}
void mini::display(){automobil::display();cout<<motor<<endl<<cp;}
mini& mini::operator=(const mini& ob)
{
    if(this==&ob) return *this;
    nume=ob.nume;
    an_fabricatie=ob.an_fabricatie;
    lungime=ob.lungime;
    pret=ob.pret;
    motor=ob.motor;
    cp=ob.cp;
    return *this;
}

istream& operator>>(istream& input,mini &ob)
{
    input>>ob.nume>>ob.an_fabricatie>>ob.lungime>>ob.pret>>ob.motor>>ob.cp;
    return input;
}

void mini::print(ostream& output) const
{
    //output<<endl<<nume<<endl<<an_fabricatie<<endl<<lungime<<endl<<motor<<endl<<cp;
    output<<nume<<" | An: "<<an_fabricatie<<" | Lungime: "<<lungime<<"m | CC: "<<motor<<" cmc | CP: "<<cp<<" | Pret: $"<<pret;
}
ostream& operator<<(ostream& output,const mini &ob)
{
    ob.print(output);
    return output;
}

/// Mica
mica::mica():automobil(),motor(1000),cp(60){}
mica::mica(string s,int an,float lung, int cap,int cai,double p):automobil(s,an,lung,p),motor(cap),cp(cai) {}
void mica::display(){automobil::display();cout<<motor<<endl<<cp<<endl;}
mica& mica::operator=(const mica& ob)
{
    if(this==&ob) return *this;
    nume=ob.nume;
    an_fabricatie=ob.an_fabricatie;
    lungime=ob.lungime;
    pret=ob.pret;
    motor=ob.motor;
    cp=ob.cp;
    return *this;
}
istream& operator>>(istream& input,mica &ob)
{
    input>>ob.nume>>ob.an_fabricatie>>ob.lungime>>ob.pret>>ob.motor>>ob.cp;
    return input;
}
void mica::print(ostream& output) const
{
    output<<nume<<" | An: "<<an_fabricatie<<" | Lungime: "<<lungime<<"m | CC: "<<motor<<" cmc | CP: "<<cp<<" | Pret: $"<<pret;
    //output<<endl<<nume<<endl<<an_fabricatie<<endl<<lungime<<endl<<motor<<endl<<cp;
}
ostream& operator<<(ostream& output,const mica &ob)
{
    ob.print(output);
    return output;
}

/// Compacta
compacta::compacta():automobil(), motor(1500),cp(65),model("sedan") {}
compacta::compacta(string a, int b, float c, int d, int e, string f,double p):automobil(a,b,c,p),motor(d),cp(e),model(f) {}
void compacta::display(){automobil::display();cout<<motor<<endl<<cp<<endl<<model<<endl<<pret<<endl;}
compacta& compacta::operator=(const compacta& ob)
{
    if(this==&ob) return *this;
    nume=ob.nume;
    an_fabricatie=ob.an_fabricatie;
    lungime=ob.lungime;
    pret=ob.pret;
    motor=ob.motor;
    cp=ob.cp;
    model=ob.model;
    return *this;
}
istream& operator>>(istream& input,compacta &ob)
{
    input>>ob.nume>>ob.an_fabricatie>>ob.lungime>>ob.pret>>ob.motor>>ob.cp>>ob.model;
    return input;
}
void compacta::print(ostream& output) const
{
    output<<nume<<" | An: "<<an_fabricatie<<" | Lungime: "<<lungime<<"m | CC: "<<motor<<" cmc | CP: "<<cp<<" | Caroserie: "<<model<<" | Pret: $"<<pret;
}
ostream& operator<<(ostream& output,const compacta &ob)
{
    ob.print(output);
    return output;
}

/// Monovolum
monovolum::monovolum():automobil(),motor(2000),cp(100),nr_locuri(5) {}
monovolum::monovolum(string a, int b, float c, int d,int e, int f,double p):automobil(a,b,c,p), motor(d),cp(e),nr_locuri(f) {}
void monovolum::display(){automobil::display();cout<<motor<<cp<<nr_locuri<<pret;}
monovolum& monovolum::operator=(const monovolum& ob)
{
    if(this==&ob) return *this;
    nume=ob.nume;
    an_fabricatie=ob.an_fabricatie;
    lungime=ob.lungime;
    pret=ob.pret;
    motor=ob.motor;
    cp=ob.cp;
    nr_locuri=ob.nr_locuri;
    return *this;
}
istream& operator>>(istream& input,monovolum &ob)
{
    input>>ob.nume>>ob.an_fabricatie>>ob.lungime>>ob.pret>>ob.motor>>ob.cp>>ob.nr_locuri;

    return input;
}
void monovolum::print(ostream& output) const
{
    output<<nume<<" | An: "<<an_fabricatie<<" | Lungime: "<<lungime<<"m | CC: "<<motor<<" cmc | CP: "<<cp<<" | Locuri: "<<nr_locuri<<" | Pret: $"<<pret;
}
ostream& operator<<(ostream& output,const monovolum &ob)
{
    ob.print(output);
    return output;
}

/// vanzare

vanzare::vanzare()
{
    s_car_n=0;
    car_n=7;
    stoc.insert(make_pair(new monovolum("Mercedes-Benz Vito",2012,5.65,2000,100,15,17400),false ));
    stoc.insert(make_pair(new mini("Mini Cooper",2020,3.2,1500,110,5350),true ));
    stoc.insert(make_pair(new mica("Ford Focus",2013,3.4,1300,96,3100),false ));
    stoc.insert(make_pair(new compacta("BMW x5",2018,4.3,4000,300,"SUV",40000),false ));
    stoc.insert(make_pair(new compacta("Renault Megane",2012,4.3,1500,110,"SUV",7600),false ));
    stoc.insert(make_pair(new mica("Audi A1",2010,2.9,100,60,2500),false ));
    stoc.insert(make_pair(new monovolum("Volkswagen Vitara",2015,5.15,2700,147,12,13900),false ));
}

void vanzare::add_car()
{
    int op,an,cc,cp,loc;
    double pret;
    float l;
    bool nsv=false;
    string nume;
    string model;
        cout<<"\n Alegeti tipul de automobil:\n 1) Mini (3-4m Lungime)\n 2) Mic (3.85-4.1m Lungime)\n 3) Compact (4.2-4.5m Lungime)\n 4) Monovolum (van)";
        cout<<endl<<endl<<" >> ";
        cin>>op;
        cout<<"\n Numele automobilului: ";cin>>nume;
        cout<<"\n Anul fabricatiei: ";cin>>an; if(an==2020) nsv=true;
        cout<<"\n Lungimea automobilului: ";cin>>l;
        cout<<" \n Capacitatea cilindrica(CC): ";cin>>cc;
            cout<<"\n Cai putere(CP): ";cin>>cp;

        if(op==3)
            {
                cout<<"\n Modelul caroseriei: ";
                cin>>model;
            }
        if(op==4)
            {
                  cout<<"\n Numarul de locuri: ";
                  cin>>loc;
            }

        cout<<"\n Pretul automobilului($): ";cin>>pret;
    switch(op)
    {
    case 1:
        stoc.insert(make_pair(new mini(nume,an,l,cc,cp,pret),nsv ));
        break;
    case 2:
        stoc.insert(make_pair(new mica(nume,an,l,cc,cp,pret),nsv ));
        break;
    case 3:
        stoc.insert(make_pair(new compacta(nume,an,l,cc,cp,model,pret),nsv ));
        break;
    case 4:
        stoc.insert(make_pair(new monovolum(nume,an,l,cc,cp,loc,pret),nsv ));
        break;
    }
    car_n++;
}

void vanzare::display_stoc()
{
    cout<<"\n Automobile de vanzare: \n\n";
    set<pair<automobil*,bool>> :: iterator it;
    int cnt=1;
    for(it=stoc.begin();it!=stoc.end();it++)
      {
        cout<<" "<<cnt<<") ";cnt++;
        if(dynamic_cast<mini*>((*it).first))
            cout<<*(static_cast<mini*>((*it).first));

        else if(dynamic_cast<mica*>((*it).first))
            cout<<*(static_cast<mica*>((*it).first));

        else if(dynamic_cast<compacta*>((*it).first))
            cout<<*(static_cast<compacta*>((*it).first));

        else if(dynamic_cast<monovolum*>((*it).first))
            cout<<*(static_cast<monovolum*>((*it).first));

        if((*it).second==true) cout<<"  ---> NOU";
        else cout<<"  ---> UTILIZAT";

            cout<<endl<<endl;
      }
}

void vanzare::buy_car(int poz)
{
    poz--;
    int cnt=0;
    set<pair<automobil*,bool>> :: iterator it=stoc.begin();

    for(int i=0;i<poz;i++)
       {
           it++;
           cnt++;
           //cout<<cnt;
       }

    stoc.erase(it);
    sold.push_back((*it).first);
}

void vanzare::display_sold()
{
    int i;
    for(i=0;i<sold.size();i++)
   {

if(dynamic_cast<mini*>(sold[i]))
            cout<<*(static_cast<mini*>(sold[i]))<<endl;
        if(dynamic_cast<mica*>(sold[i]))
            cout<<*(static_cast<mica*>(sold[i]))<<endl;
        if(dynamic_cast<compacta*>(sold[i]))
            cout<<*(static_cast<compacta*>(sold[i]))<<endl;
        if(dynamic_cast<monovolum*>(sold[i]))
            cout<<*(static_cast<monovolum*>(sold[i]))<<endl;
   }
   car_n--;
   s_car_n++;

}







