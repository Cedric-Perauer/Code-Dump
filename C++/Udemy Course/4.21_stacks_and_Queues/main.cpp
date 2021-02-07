#include <iostream>
#include <stack>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Test {
 private:
     string name;
  public:
      Test(string name) : name(name)
      {

      }

      ~Test() {
      //cout << "Object destroyed"<< endl;
      }

      void print()  {
      cout << name << endl;
      }
};
//FIFO
int main()
{   queue<Test> Teststack;
    Teststack.push(Test("Mary"));
    Teststack.push(Test("James"));
    Teststack.push(Test("Velia"));
    char a[20];
    int b=1;

    while(b==1)
        {
        cout << "input name you want to add : " << endl;
        scanf("%s",a);
        Teststack.push(Test(a));
        cout << "Do you want to add a name ? " << endl;
         cout << "input 1 if yes : " << endl;
         scanf("%i",&b);


    }
    /* wrong syntax
    Test &test1 = Teststack.top();
    Teststack.pop();
    test1.print();
    */








while(Teststack.size() > 0) {
    Test &test2 = Teststack.front();
    test2.print();
    Teststack.pop();


}


return 0;
}
