#include <iostream>
#include <string>

using namespace std;

class Test
{
	int id;
	string name;

public:
	Test() : id(0), name("")
	{

	}

	Test(int id, string name) : id(id), name(name)
	{

	}

	Test(const Test& other)
	{
		cout << "Copy constructor running" << endl;
		this->id = other.id;
		this->name = other.name;
	}

	const Test& operator=(const Test &other) {
		cout << "Assignment running" << endl;
		this->id = other.id;
		this->name = other.name;
		return *this;
	}

	void print() const
	{
		cout << id << ": " << name << endl;
	}
	friend ostream &operator<<(ostream &out  ,const Test &other)
	{
	    out << other.id <<":" << other.name;
	    return out;
	}
};

int main() {

	Test test1(10, "Mike");
	cout << test1<< endl;



	return 0;
}
