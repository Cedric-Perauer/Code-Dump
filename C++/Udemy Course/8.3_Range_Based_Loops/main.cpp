#include <iostream>
#include <vector>
using namespace std;
template <class a>

auto number(a numbers) -> decltype(numbers) {
  for(auto num:numbers)
     {
         cout << num << endl;
     }
}

int main()
{   vector<string> numbers;
    numbers.push_back("Brisa");
    numbers.push_back("Celine");
    numbers.push_back("Tom");
    numbers.push_back("Angel");

    number(numbers);

    return 0;
}
