#include "object.h"
#include <istream>
#include <ostream>
#include <cmath>
#include <vector>



object::object(): x(0),y(0) {}
object::object(int a,int b): x(a),y(b) {}
object::object(const object& ob): x(ob.x),y(ob.y) {}

void object::display()
{
    cout<<"["<<x<<","<<y<<"] ";
}

object& object::operator=(const object& ob)
{
    if(this==&ob) return *this;
    x=ob.x;
    y=ob.y;
    return *this;
}

void object::print(ostream& output) const
{
    output<<"["<<x<<","<<y<<"] ";
}

ostream& operator<<(ostream& output, const object& ob)
{
    ob.print(output);
    return output;
}

istream& operator>>(istream& input, object& ob)
{
    input >> ob.x >> ob.y;
    return input;
}
                                                                                                ///  ^ class Object
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

complex::complex():object(),x(0),y(0){}
complex::complex(int a,int b): object(a,b),x(a),y(b){}
complex::complex(const complex &ob): x(ob.x),y(ob.y){}

void complex::display()
{
    if(y>=0)
    cout<<x<<" + "<<y<<"*i";
    else cout<<x<<" - "<<-y<<"*i";
}

complex& complex::operator=(const complex& ob)
{
    if(this==&ob) return *this;
    x=ob.x;
    y=ob.y;
    return *this;
}

void complex::print(ostream& output) const
{
    if (x != 0) {
		output << x;
		if (y != 0) {
			if (y > 0)
				output << " + " << y << "i";
			else
				output << " - " << -y << "i";
		}
	}
	else {
		if (y != 0) {
			output << y << "i";
		}
		else {
			output << 0;
		}
	}
}

istream& operator>>(istream& input, complex& ob)
{
    input >> ob.x >> ob.y;
    return input;
}

ostream& operator<<(ostream& output, const complex& ob)
{
    ob.print(output);
    return output;
}
                                                                                                /// ^ class Complex
/// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
point::point():object(),x(0),y(0){}
point::point(int a,int b): object(a,b),x(a),y(b){}
point::point(const point &ob): x(ob.x),y(ob.y) {}

void point::display()
{
    cout<<"("<<x<<","<<y<<") ";
}

void point::print(ostream& output) const
{
    output<<"("<<x<<","<<y<<") ";
}

point& point::operator=(const point& ob)
{
    if(this==&ob) return *this;
    x=ob.x;
    y=ob.y;
    return *this;
}

istream& operator>>(istream& input, point& ob)
{
    input >> ob.x >> ob.y;
    return input;
}

ostream& operator<<(ostream& output, const point& ob)
{
    ob.print(output);
    return output;
}
                                                                                                        /// ^class Point
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ob_array::ob_array():dim(0){}
ob_array::ob_array(int d):dim(d)
{
    //object *p=new point;
    //object *c=new complex;
    for(int i=0; i<d; i++)
    {
        if(i%2==0)
        {
            v.push_back(new point);
            //cout<<" p";
        }
        else
        {
            v.push_back(new complex);
            //cout<<" c";
        }
    }
}

void ob_array::display()
{
    int i;
    int cntp=0,cntc=0;
    cout<<"\n                                                                    Array:\n\n";
    for(i=0; i<v.size(); i++)
     {
         if(dynamic_cast<point*>(v[i])) cntp++;
         if(dynamic_cast<complex*>(v[i])) cntc++;
         if(dynamic_cast<point*>(v[i]))
         {
             cout<<"                                                                    "<<*(static_cast<point*>(v[i]))<<endl;
         }
         else if(dynamic_cast<complex*>(v[i]))
         {
             cout<<"                                                                    "<<*(static_cast<complex*>(v[i]))<<endl;
         }
         //cout<<"\n "<<*v[i];  /// le afiseaza ca obiecte
     }
    // cout<<"\n complexe: "<<cntc;
     //cout<<"\n puncte: "<<cntp;


}

int ob_array::getsize()
{
    return dim;
}

void ob_array::add(object* ob)
{
    dim++;
    v.push_back(ob);
}

void ob_array::remove_all()
{
    int i;
    for(i=0;i<dim;i++)
       {
           v.pop_back();
           //cout<<"* ";
       }
    dim=0;
}

void ob_array::insert_at(int k,object* ob)
{
    dim++;
    v.insert(v.begin()+k-1,ob);
}

void ob_array::remove_at(int k)
{
    dim--;
    v.erase(v.begin()+k-1);
}

object* ob_array::get_at(int k)
{
    return v[k-1];
}
                                                                                                /// ^class Ob_array
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
