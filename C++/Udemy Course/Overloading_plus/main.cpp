#include <iostream>
#include "Complex.h"

using namespace std;
using namespace C;

int main() {

	Complex c1(4, 5);
	Complex c2(3,4);


    Complex c3 = c2+c1;
	cout << "c2+c1 = :" << c3 << endl;
	Complex C4 = c2+3.2;
	cout << "c2+3.2 = :" << C4  << endl;

	if(c2==c1)
    {  cout << "Equal " << endl;
    }

    else{

        cout << "Not equal" << endl;
    }

    if(c3!=c1)
    {  cout << "Not equal " << endl;
    }

    else{

        cout << "Equal" << endl;
    }
     Complex c5;
    c5 = *c1;
    cout << "Komplex konjugiert zu c1 :" << c5 << endl;

     Complex c6 = c2* (*c2);
    cout << "c6 ist :" << c6 << endl;


     Complex c7 = c1/(*c2);
    cout << "c7 ist :" << c7 << endl;

	return 0;
}
