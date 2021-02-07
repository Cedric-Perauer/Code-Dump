#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{   string value;

    decltype(value) name= "Bob";
    cout << typeid(value).name() << endl;
    return 0;
}
