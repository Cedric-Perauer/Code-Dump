#include <iostream>
#include <map>

using namespace std;

//class person {
//private:
//    string name;
//    int age;
//public:
//
//    person(): name(""),age(0){
//}
//* person(const person &other)
//{   cout << "constructor running" << endl;
//    name = other.name;
//    age = other.age;
//} */
//  person(string name, int age):
//  name(name),age(age) {}
//
//void print() const {
// cout << name << ":" << age << endl;
//}
//
//
//};
//
//
//
//
//int main()
//{    map <int, person> people;
//    people[55]= person("Tom",45);
//    people[29]= person("Sarah",25);
//    people[1]= person("Kid",10);
//
//
//    people.insert(make_pair(4,person("Vicky",23)));
//
//    for(map <int, person>::iterator it= people.begin(); it!=people.end();it++ )
//      {
//        cout << it->first << ":" << flush;
//        it->second.print();
//      }
//
//    return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////

class person {
private:
    string name;
    int age;
public:

    person(): name(""),age(0){
}

  person(string name, int age):
  name(name),age(age) {}

void print() const{
 cout << name << ":" << age << endl;
}
bool operator<(const person &other) const
{
   if(name==other.name) {
    return age< other.age;
   }
   else{
    return name<other.name;
   }
}
};




int main()
{    map < person, int> people;
    people[person("Tom",45)]= 55;
    people[person("Sarah",25)]= 29;
    people[person("Kid",10)]= 12;

    people.insert(make_pair(person("Brisa",21),4));

    for(map <person, int>::iterator it= people.begin(); it!=people.end();it++ )
      {
        cout << it->second <<":" << flush;
        it->first.print();
      }

    return 0;
}

