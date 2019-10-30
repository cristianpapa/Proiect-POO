#include "Complex.h"
#include <istream>
#include <ostream>
#include <cmath>

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Complex::Complex(double x, double y)
{
    real=x;
    imaginar=y;
}

Complex::Complex(const Complex& ob)
{
    real=ob.real;
    imaginar=ob.imaginar;
}

Complex::~Complex() {
	real = imaginar = 0;
}

Complex& Complex::operator=(const Complex& ob) {
	if (this == &ob) {
		return *this;
	}
	real = ob.real;
	imaginar = ob.imaginar;
	return *this;
}

double Complex::get_real() const {
	return real;
}

double Complex::get_imaginar() const {
	return imaginar;
}

void Complex::set_real(double re) {
	real = re;
}

void Complex::set_imaginar(double im) {
	imaginar = im;
}

void Complex::print(std::ostream& outputer) const {
	if (real != 0) {
		outputer << real;
		if (imaginar != 0) {
			if (imaginar > 0)
				outputer << " + " << imaginar << "i";
			else
				outputer << " - " << -imaginar << "i";
		}
	}
	else {
		if (imaginar != 0) {
			outputer << imaginar << "i";
		}
		else {
			outputer << 0;
		}
	}
}

double Complex::modul() const {
	return sqrt(real*real+imaginar*imaginar);
}

Complex Complex::operator+(const Complex& ob) const {
	Complex Suma;
	Suma.real = real + ob.real;
	Suma.imaginar = imaginar + ob.imaginar;
	return Suma;
}

Complex Complex::operator-(const Complex& ob) const {
	Complex Diferenta;
	Diferenta.real = real - ob.real;
	Diferenta.imaginar = imaginar - ob.imaginar;
	return Diferenta;
}

Complex Complex::operator*(const Complex& ob) const {
	Complex Produs;
	Produs.real = real * ob.real - imaginar * ob.imaginar;
	Produs.imaginar = real * ob.imaginar + imaginar * ob.real;
	return Produs;
}

Complex Complex::operator*(double nr) const {
	Complex Produs;
	Produs.real = real * nr;
	Produs.imaginar = imaginar * nr;
	return Produs;
}

Complex Complex::operator/(const Complex& ob) const {
	if (ob.real == ob.imaginar && ob.real == 0) {
		return Complex();
	}
	Complex Cat;
	Cat.real = (real * ob.real + imaginar * ob.imaginar) / (pow(ob.real, 2) + pow(ob.imaginar, 2));
	Cat.imaginar = (-real * ob.imaginar + imaginar * ob.real) / (pow(ob.real, 2) + pow(ob.imaginar, 2));
	return Cat;
}



Complex operator*(double nr, const Complex& ob) {
	Complex Produs;
	Produs.real = nr * ob.real;
	Produs.imaginar = nr * ob.imaginar;
	return Produs;
}

Complex operator-(const Complex& ob) {
	return -1 * ob;
}


istream& operator>>(istream& input, Complex& ob) {
	input >> ob.real >> ob.imaginar;
	return input;
}

ostream& operator<<(ostream& output, const Complex& ob) {
	ob.print(output);
	return output;
}

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector_complex::vector_complex(int n, Complex nr): n(n), v(new Complex[n]) {
	for (int i = 0; i < n; ++i)
		v[i] = nr;
}

vector_complex::vector_complex(const vector_complex& ob): n(ob.n), v(new Complex[n]) {
	for (int i = 0; i < n; ++i)
		v[i] = ob.v[i];
}

vector_complex::~vector_complex() {
	n = 0;
	delete[] v;
}

vector_complex& vector_complex::operator=(const vector_complex& ob) {
	if (this == &ob) {
		return *this;
	}
	n = ob.n;
	delete[] v;
	v = new Complex[n];
	for (int i = 0; i < n; ++i)
		v[i] = ob.v[i];
	return *this;
}

vector_complex vector_complex::vector_module() const {
	vector_complex Module(n);
	for (int i = 0; i < n; ++i)
		Module.v[i] = v[i].modul();
	return Module;
}

void vector_complex::sortare_module() {
	for (int i = n - 1; i > 0; --i)
		for (int j = 0; j < i; ++j)
			if (v[j].modul() > v[j + 1].modul())
				swap(v[j], v[j + 1]);
}

Complex vector_complex::suma() const {
	Complex sum(0,0);
	for (int i = 0; i < n; ++i)
		sum = sum + v[i];
	return sum;
}

Complex vector_complex::operator*(const vector_complex& ob) const
{
	if (n != ob.n)
		return Complex();

	vector_complex produs_scalar(n);
	for (int i = 0; i < n; ++i)
		produs_scalar.v[i] = v[i] * ob.v[i];
	return produs_scalar.suma();
}

istream& operator>>(istream& input, vector_complex& ob) {
	delete[] ob.v;
	input >> ob.n;
	ob.v = new Complex[ob.n];
	for (int i = 0; i < ob.n; ++i)
		input >> ob.v[i];
	return input;
}

ostream& operator<<(ostream& output, const vector_complex& ob) {

	for (int i = 0; i < ob.n; ++i)
		output << "(" << ob.v[i] << ") ";

	return output;
}

