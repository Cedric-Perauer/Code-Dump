#include <iostream>

using namespace std;

template <class a, class b>

auto add(a value1, b value2) -> decltype(value1 + value2)  {
return value1+ value2;
}

int get() {
return 100;
}

auto test2() -> decltype(get())
{
    return get();
}
int main()
{
    auto value = 7;
    auto text = "Hi";
    cout << add(4,5) << endl;
    return 0;
}
