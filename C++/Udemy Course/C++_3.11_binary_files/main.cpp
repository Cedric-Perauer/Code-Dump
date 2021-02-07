#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push,1)

struct Person {
char name[50];
int age;
double height;

};
#pragma pack(pop)




int main()
{
    Person dude = {"Cedric",220,1.7};


    string filename = "test.bin";

    ofstream outputfile;

    outputfile.open(filename.c_str(),ios::binary );


    if(outputfile.is_open())
    {
        outputfile.write(reinterpret_cast <char*>(&dude),sizeof(dude));
        outputfile.close();
    }

    else

    {
       cout << "Could not open the file:" + filename << endl;
    }
    Person someoneelse ={};

    ifstream inputfile;

    inputfile.open(filename.c_str(),ios::binary );


       if(inputfile.is_open())
    {
        inputfile.read(reinterpret_cast <char*>(&someoneelse),sizeof(Person));
        inputfile.close();

    }

     else

    {
       cout << "Could not read the file:" + filename << endl;

    }
    cout << someoneelse.name << "," << someoneelse.age << "," << someoneelse.height<< endl;

    return 0;
}
