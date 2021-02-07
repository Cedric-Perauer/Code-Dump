#include "Complex.h"



namespace C {



Complex::Complex() : real(0), imag(0)
	{

	}
	Complex::Complex(double real, double imag) : real(real), imag(imag)
	{

	}

Complex::Complex(const Complex& other)
	{
		cout << "Copy constructor running" << endl;
		this->real = other.real;
		this->imag = other.imag;
	}

	const Complex &Complex::operator=(const Complex &other) {
		cout << "Assignment running" << endl;
		this->real = other.real;
		this->imag = other.imag;
        return *this;
	}
    ostream &operator<<(ostream &out  ,const Complex &other)
	{
	    out << other.getReal() <<":" << other.getImag();
	    return out;
	}

	Complex operator*(const Complex &c1)  {
	return Complex(c1.getReal(),-c1.getImag());
	}
    Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.getReal()+c2.getReal(),c1.getImag()+c2.getImag());
    }


}
