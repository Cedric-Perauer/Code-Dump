#ifndef COMPLEX_H_
#define COMPLEX_H_


#include <iostream>

using namespace std;

namespace C {

class Complex {
private:
	double real;
	double imag;

public:
	Complex();
	Complex(double real, double imag);
	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);

	double getReal() const {
		return real;
	}
	double getImag() const {
		return imag;
	}
	  bool operator==(const Complex &other) const;
	bool operator!=(const Complex &other) const;

};

ostream &operator<<(ostream &out, const Complex &other);
Complex operator+(const Complex &c1,const Complex &c2 );
Complex operator+(const Complex &c1,double d );
Complex operator+(double d,const Complex &c2 );
Complex operator*(const Complex &c1);
Complex operator*(const Complex &c1, const Complex &c2);
Complex operator/(const Complex &c1, const Complex &c2);



} /* namespace caveofprogramming */

#endif /* COMPLEX_H_ */
