#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
template <class mytype>

mytype print(mytype a)
{
    cout << a << endl;
}

int main()
{   print<string>("Hello");
print<double> (M_PI);
    print("hello");
    return 0;
}
