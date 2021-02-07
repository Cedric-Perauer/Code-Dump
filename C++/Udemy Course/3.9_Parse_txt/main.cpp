#include <iostream>
#include <fstream>

using namespace std;




int main()
{
    string filename = "stats.txt";
    ifstream input;

    input.open(filename.c_str(),ios::in);

    if(!input.is_open())
    {
        return 1;
    }

    while(input)
    {   string line;
        getline(input,line,':');

        float population;
        input >> population;



        if(!input) {
            break;

        }

        input >> ws; //C++ 11

        cout<< "--" << line << " " << population << endl;
    }

    return 0;
}
