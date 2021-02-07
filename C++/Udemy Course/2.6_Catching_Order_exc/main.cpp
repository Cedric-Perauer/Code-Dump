#include <iostream>
#include <exception>

using namespace std;


void goeswrong(){
bool error1detected= true;
bool error2detected= false;

   if(error1detected){
    throw bad_alloc();
   }
   if(error2detected)
   {
        throw exception();
   }


}
// Order : catch subclass before parent class !!!
int main()
{  try{
    goeswrong();
    }
    catch(exception &e)
    {
         cout <<"Catching bad_alloc "<< e.what() << endl;
    }
    catch(bad_alloc &e)
    {    cout <<"Catching exception "<< e.what() << endl;

    }

    return 0;
}
