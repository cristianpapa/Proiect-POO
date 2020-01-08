#ifndef AUTOMOBIL_H_INCLUDED
#define AUTOMOBIL_H_INCLUDED
#include <iostream>
#include <set>
#include <vector>
using namespace std;


class automobil
{
protected:
    string nume;
    int an_fabricatie;
    float lungime;
    double pret;
public:
    automobil();
    automobil(string,int,float,double);
    virtual ~automobil(){};
    virtual void display()=0;

    double get_price();
    void print(std::ostream&) const;
    friend istream& operator>>(istream&,automobil&);
    friend ostream& operator<<(ostream&,const automobil&);
    automobil& operator=(const automobil&);
};


class mini:public automobil
{
    int motor;
    int cp;
public:
    mini();
    mini(string,int,float,int,int,double);
    virtual ~mini(){};
    void display();

    void print(std::ostream&) const;
    friend istream& operator>>(istream&,mini&);
    friend ostream& operator<<(ostream&,const mini&);
    mini& operator=(const mini&);
};
class mica:public automobil
{
    int motor;
    int cp;
public:
    mica();
    mica(string, int, float, int, int,double);
    virtual ~mica(){};
    void display();

    void print(std::ostream&) const;
    friend istream& operator>>(istream&,mica&);
    friend ostream& operator<<(ostream&,const mica&);
    mica& operator=(const mica&);
};
class compacta:public automobil
{
    int motor;
    int cp;
    string model;  ///hatch, combi, sedan
public:
    compacta();
    compacta(string,int, float, int, int, string,double);
    virtual ~compacta(){};

    void display();

    void print(std::ostream&) const;
    friend istream& operator>>(istream&,compacta&);
    friend ostream& operator<<(ostream&,const compacta&);
    compacta& operator=(const compacta&);
};
class monovolum:public automobil
{
    int motor;
    int cp;
    int nr_locuri;
public:
    monovolum();
    monovolum(string,int, float, int,int, int,double);
    virtual ~monovolum(){};
    void display();

    void print(std::ostream&) const;
    friend istream& operator>>(istream&,monovolum&);
    friend ostream& operator<<(ostream&,const monovolum&);
    monovolum& operator=(const monovolum&);
};

class vanzare
{
    set<pair<automobil*,bool>> stoc;
    int car_n;
    vector<automobil*>sold;
    int s_car_n;
public:
    vanzare();

    void buy_car(int);
    void add_car();

    void display_sold();
    void display_stoc();
};
#endif // AUTOMOBIL_H_INCLUDED
