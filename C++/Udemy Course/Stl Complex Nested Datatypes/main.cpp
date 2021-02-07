#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/**************************************************
*
* Note, some compilers are OK with angle brackets
* used in connection with template types
* being next to each other with no spaces, like
* this: map<string, vector<int>> scores;
* Others require spaces, like this:
* map<string, vector<int> > scores;
* It's safer to put in spaces.
*
**************************************************/

int main() {

	map<string, vector<int> > scores;

	scores["Mike"].push_back(10);
	scores["Mike"].push_back(20);
	scores["Vicky"].push_back(15);

	for(map<string, vector<int> >::iterator it = scores.begin(); it!= scores.end(); it++)
	{   pair <string,vector<int> > ages = *it;
		string name = ages.first;
		vector<int> scoreList = ages.second;

		cout << name << ": " << flush;

		for(int i = 0; i < scoreList.size(); i++)
		{
			cout << scoreList[i] << " " << flush;
		}

		cout << endl;
	}
	return 0;
}
