//============================================================================
// Name        : Ring_Buffer_Class.cpp
// Author      : Cedric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ring.h"
#include <vector>
using namespace std;

int main() {
	ring<string> textring(3); // Ring with 3 elements
	textring.add("first element");
	textring.add("second element");
	textring.add("third element");
	textring.add("fourth element"); //when added first element is pushed out

	for(int i = 0 ; i < textring.size(); i++)
	{  cout << textring.get(i) << endl;

	}

	return 0;
}
