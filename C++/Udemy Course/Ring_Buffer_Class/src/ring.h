/*
 * ring.h
 *
 *  Created on: Feb 4, 2019
 *      Author: Cedric
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template<class T>
class ring{
private:
	int mem_pos;   //for the position in the buffer
	T *mem_values; //pointer to array T
	int mem_size;  //for the size of the buffer
public:
	class iterator;

public:

ring(int size): mem_size(size), mem_values(NULL), mem_pos(0) { //constructor
	mem_values = new T[size];
}

~ring() {
	delete [] mem_values;

}

int size() {
	return mem_size;
}

void add(T value) {
	mem_values[mem_pos++] = value;  //adds value to buffer, increments mem_pos by 1 after




	if(mem_pos==mem_size)
	{ mem_pos = 0;

    }
}

T &get(int pos) {
	return mem_values[pos];
}
};





#endif /* RING_H_ */
