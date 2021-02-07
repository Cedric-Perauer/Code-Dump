#include <iostream>

using namespace std;

class Canbewrong {
public:
    Canbewrong(){
    char *pMemory = new char[99999999999999999];
    delete[] pMemory;

    }
};

int main()
{
   try {
   Canbewrong wrong;
   }
   catch(bad_alloc &e)
   {
       cout << "Caught exception " << e.what() << endl;
   }

    cout << "Sill running" << endl;
    return 0;
}
