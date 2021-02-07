#include <iostream>

using namespace std;

struct Testt{

virtual bool operator()(string text)=0;
~Testt(){}
};

struct matchtest:public Testt{
bool operator()(string text){     //Functor
    return text=="Dog";           //Functor

}
};

void check(string text,Testt &test)  {
    if(test(text))
    {
       cout << "Match" << endl;
    }
    else
    {
             cout << "No Match" << endl;


    }
}



int main()
{   matchtest test;

    string value ="Pup";
    matchtest a;
    cout << test(value) << endl;
    value = "Dog";
    check(value,a);

    return 0;
}
