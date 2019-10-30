#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class vector_complex;

class Complex {
	double real, imaginar;
public:
	friend class vector_complex;
	Complex(double real=0, double imaginar=0);
	Complex(const Complex&);
	~Complex();
	Complex& operator=(const Complex&);
	double get_real() const;
	double get_imaginar() const;
	void set_real(double);
	void set_imaginar(double);
	void print(std::ostream&) const;
	double modul() const;
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator*(double) const;
	Complex operator/(const Complex&) const;
	friend Complex operator*(double, const Complex&);
	friend Complex operator-(const Complex&);
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, const Complex&);
};

class vector_complex {
	int n;
	Complex* v;
public:
	vector_complex(int n = 0, Complex nr = { 0,0 });
	vector_complex(const vector_complex&);
	~vector_complex();
	friend istream& operator>>(istream&, vector_complex&);
	friend ostream& operator<<(ostream&, const vector_complex&);
	vector_complex& operator=(const vector_complex&);
	vector_complex vector_module() const;
	void sortare_module();
	Complex suma() const;
	Complex operator*(const vector_complex&) const;


};
class in_out
{
    int n;
public:
   void citire(int n, istream& in, vector_complex *v)
   {
       if(v!=NULL)
            delete[]v;

       v=new vector_complex[n];

       for(int i=0;i<n;i++)
       {
           in>>v[i];
       }

   }
   void afisare(int n, ostream& out, vector_complex *v)
   {

       for(int i=0;i<n;i++)
       {
           out<<v[i]<<endl;
       }

   }
};

#endif
