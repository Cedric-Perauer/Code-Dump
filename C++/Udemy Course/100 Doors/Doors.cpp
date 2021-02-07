//============================================================================
// Name        : Doors_Question.cpp
// Author      : Cedric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;



int main() {
	map<int,string> Doors;
	for(int i=0; i<100;i++) {
		Doors[i] = "Closed";
	}

	for(int i=1; i<101; i++){
		for (int j=0; j<100;j++) {
			if(((j+1)%i ==0)) {
			if( (Doors[j]== "Closed") ) {
				Doors[j] = "Open";

			}

			else if (Doors[j]== "Open"){
               Doors[j] = "Closed";

			}

		}

	}
	}

    for(map<int,string>::iterator it=Doors.begin();it!= Doors.end();it++){
    	pair<int,string> state = *it;
    	cout << " Door number : " << state.first +1 << " " << "State : "<< state.second << endl;

    }



	return 0;
}


	cout << "State of Door is :" << Doors[8]<<  endl;
	return 0;
}
