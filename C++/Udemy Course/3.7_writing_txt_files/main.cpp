#include <iostream>
#include <fstream>
#include <string>

using namespace std;

  /*  int main() {

         ofstream outFile;

        fstream outfile;

        string outputFileName = "text.txt";


         outfile.open(outputFileName.c_str(), ios::out);       //c_str to make it run

        if(outfile.is_open()) {
            outfile << "Hello there" << endl;
            outfile << 123 << endl;
            outfile.close();
        }
        else {
            cout << "Could not create file: " << outputFileName << endl;
        }

        return 0;
    }
*/
int main() {

	string inFileName = "test.txt";

	ifstream inFile;

	inFile.open(inFileName.c_str());

	if (inFile.is_open()) {

		string line;

		while (inFile) {
			getline(inFile, line);
			cout << line << endl;
		}

		inFile.close();
	} else {
		cout << "Cannot open file: " << inFileName << endl;
	}

	return 0;
}
