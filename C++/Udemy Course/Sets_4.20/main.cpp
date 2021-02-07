#include <iostream>
#include <set>
#include <windows.h>

using namespace std;

class Test
{
private:
    string name;
    int id;
public:
    Test(int id, string name):id(id),name(name){
    }
    void print() const {


cout << name <<"=" << id << endl;}

    bool operator <(const Test &other) const
    {
        return name < other.name;
    }

};





int main()
{    set <float> numbers;
    numbers.insert(10);
   numbers.insert(20);
    numbers.insert(30);



  Sleep(100);

    for(set <float>::iterator it= numbers.begin(); it!=numbers.end();it++ )
      {
        cout << *it << endl;

      }


      set <float>::iterator itfind = numbers.find(30);

      if(itfind!=numbers.end())
      {
          cout << "Found:" << *itfind << endl;
      }
     if(numbers.count(30)==1)
      {
        cout << "Number found woohoo:" << *itfind << endl;
      }

      set<Test> tests;


         for(set <Test>::iterator it= tests.begin(); it!=tests.end();it++ )
      {
        it->print();

      }


    return 0;
}
