#include "Complex.h"




namespace C {
Complex::Complex():real(0),imag(0){}
Complex::Complex(double real,double imag):real(real),imag(imag) {}

Complex::Complex(const Complex &other)  {
       cout<<"Copy Constructor Running" << endl;
      this->real = other.real;
		this->imag = other.imag;

}

const Complex &Complex::operator=(const Complex &other) {
		cout << "Assignment running" << endl;
		this->real = other.real;
		this->imag = other.imag;
        return *this;
	}

	Complex operator+(const Complex &c1,const Complex &c2 ) {
	return Complex(c1.getReal()+c2.getReal(), c1.getImag()+c2.getImag());


	}
	 Complex operator+(const Complex &c1,double d ) {
	 return Complex(c1.getReal()+d,c1.getImag());
	 }
  Complex operator+(double d,const Complex &c1 ){
  return Complex(c1.getReal()+d,c1.getImag());
  }
  bool Complex:: operator==(const Complex &other) const {
  return (real == other.real) && (imag == other.imag);
  }
  bool Complex:: operator!=(const Complex &other) const {
 return (real != other.real) && (imag != other.imag);

  }
  Complex operator*(const Complex &c1)  {
 return Complex(c1.getReal(),-c1.getImag());

 }
     Complex operator*(const Complex &c1, const Complex &c2)  {
     return Complex(c1.getReal()*c2.getReal()-(c1.getImag()*c2.getImag()),c1.getReal()*c2.getImag()+c1.getImag()*c2.getReal());
     }

     Complex operator/(const Complex &c1, const Complex &c2)
     {
     Complex c6 = c2* (*c2);
         return Complex((c1.getReal()*c2.getReal()- c1.getImag()*c2.getImag())/(c6.getReal()), (c1.getReal()*c2.getImag()+c1.getImag()*c2.getReal())/(c6.getReal()));
     }


ostream &operator<<(ostream &out, const Complex &other)  {
out << other.getReal() << " : "<< other.getImag() <<"i";

return out;

}

}
