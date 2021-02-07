#include <iostream>

using namespace std;

void Print(int d)  {
cout << "Hello world!" << d << endl;
}

void calc(float a,float b,float *c)  {

*c = a+b;

}




int main()
{   int d = 3;
float a = 1.2;
float b = 5.4;
float x;

    void (*Ptest)(int);
    void (*calculate)(float,float,float*) = calc;


    Ptest = &Print;


    (*Ptest)(d);
    (*calculate)(a,b,&x);
    cout << x << endl;

    return 0;
}
