#include <iostream>

using namespace std;

void mightGoWrong()
{
    bool error1 = false;
    bool error2 = false;


    if(error1) {
        throw "Something went wrong";
    }

    if(error2) {
        throw string("Something else went wrong");
    }


}

void usesmightgowrong(){
    mightGoWrong();
}

int main()
{
    try  { usesmightgowrong();

    }
    catch(int e)
    {
         cout << "Error Code:" << e << endl;
    }
    catch(char const *e)
    {
         cout << "Error Message Code:" << e << endl;
    }

    catch(string &e)
    {
         cout << "Error Code Number 3:" << e << endl;
    }

cout << "Still running"<< endl;
    return 0;
}
