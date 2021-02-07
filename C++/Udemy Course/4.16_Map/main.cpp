#include <iostream>
#include <map>
using namespace std;

int main()
{  map<string,int> age;
   age["Cedric"]= 21;
   age["Brisa"]= 20;
   age["Celine"]= 19;

   if(age.find("Velia")!= age.end())
   {
       cout << "Found Velia" << endl;

   }

   else
   {
       cout << "Key not found" << endl;
   }
   age.insert(make_pair("Velia",20));
   for(map<string,int>::iterator it = age.begin();it!=age.end(); it++)
   {   pair <string,int> ages = *it;
       cout << ages.first << ":" << ages.second << endl;
   }

   for(map<string,int>::iterator it = age.begin();it!=age.end(); it++)
   {
       cout << it ->first << ":" << it-> second << endl;
   }


}
