#include <iostream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Test {
int id;
string name;

public:
    Test(int id, string name): id(id),name(name) {

    }
    void print()  {

    cout << id <<":" << name << endl;
    }

  /*  bool operator<(const Test &other) const
{
   if(name==other.name) {
    return id< other.id;
   }
   else{
    return name<other.name;
   }
}  */


  friend bool comp(const Test &a, const Test &b);



};

bool comp(const Test &a, const Test &b) {
return a.name < b.name;
}


int main()
{  vector<Test> tests;
   tests.push_back(Test(2,"Cedric"));
   tests.push_back(Test(45,"Cedric"));
   tests.push_back(Test(5,"Vel"));

   std::sort(tests.begin(),tests.end(),comp);

   for(int i =0; i< tests.size(); i++)
   {  tests[i].print();

   }





    return 0;
}
