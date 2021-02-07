#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector< vector <int> > grid(4,vector<int>(5,7));
  //  grid[1].push_back(8);
   for(int row=0; row <grid.size();row++)
       // for(vector<int>::iterator i = grid.begin(); i != grid.end();i++)
    {
        for(int col=0; col <grid[row].size();col++)    // "access vector of grid[row]"
        {
            cout << grid[row][col] << flush;
        }

      cout  << endl;
    }
    return 0;
}

