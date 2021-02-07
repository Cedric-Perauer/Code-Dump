#include <iostream>

using namespace std;

template<class T>

class Test{
private:
    T obj;
public:
    Test(T obj) : obj(obj) {}

//    Test(T obj){
//    this-> obj= obj;
//    }
    void print()
    { cout << obj << endl;

    }



};

int main()
{
    Test<string> h("hello");

    h.print();

    return 0;
}
