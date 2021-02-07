#include <iostream>
#include <map>
using namespace std;

int main()
{   multimap <int,string> lookup;

    lookup.insert(make_pair(20,"Ben"));
    lookup.insert(make_pair(30,"Lara"));
    lookup.insert(make_pair(40,"Xi"));
    lookup.insert(make_pair(40,"Sam"));

    for(multimap<int,string>::iterator it= lookup.begin();it!=lookup.end();it++)
    { pair<int,string> ages = *it;
      cout << ages.first << ":" << ages.second << endl;

    }
    cout << endl;

    for(multimap<int,string>::iterator it= lookup.find(10);it!=lookup.end();it++)  //just useful for finding one element
    { pair<int,string> ages = *it;
      cout << ages.first << ":" << ages.second << endl;

    }
    cout << endl;

     pair<multimap<int,string>::iterator,multimap<int,string>::iterator> its= lookup.equal_range(40);

    for(multimap<int,string>::iterator it= its.first;it!=its.second;it++)
    {
        pair<int,string> ages = *it;
      cout << ages.first << ":" << ages.second << endl;

    }



    return 0;
}
