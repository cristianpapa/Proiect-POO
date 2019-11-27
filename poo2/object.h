#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <vector>
using namespace std;

class object
{
    int x;
    int y;
public:
    object();
    object(int,int);
    object(const object&);
    virtual ~object(){};

    virtual void display()=0;
    void print(std::ostream&) const;

    object& operator=(const object&);
    friend istream& operator>>(istream&, object&);
    friend ostream& operator<<(ostream&, const object&);

};

class complex:public object
{
private:
    int x;
    int y;
public:
    complex();
    complex(int,int);
    complex(const complex&);
    virtual ~complex(){};

    virtual void display();

    void print(std::ostream&) const;

    complex& operator=(const complex&);
    friend istream& operator>>(istream&, complex&);
    friend ostream& operator<<(ostream&, const complex&);
};
class point:public object
{
private:
    int x;
    int y;
public:
    point();
    point(int, int);
    point(const point&);
    virtual ~point(){};

    virtual void display();
    void print(std::ostream&) const;

    point& operator=(const point&);
    friend istream& operator>>(istream&, point&);
    friend ostream& operator<<(ostream&, const point&);
};

/// /////////////////////////////////////////////////////////////////////////
class ob_array:public object
{
private:
    vector<object*>v;
    int dim; /// n-am pus size si grows pentru ca n-am inteles la ce trebuie folosite
public:
    ob_array();
    ob_array(int); /// constructor care introduce int/2 puncte (0,0) si int/2 complexe 0 + 0*i
    virtual ~ob_array(){};

    object* get_at(int);
    int getsize();
    void insert_at(int,object*); /// era int in cerinta, n-am inteles de ce
    void remove_at(int); ///           ---------//---------
    void remove_all();
    void add(object*); ///            ---------//---------

    virtual void display();
};


#endif
