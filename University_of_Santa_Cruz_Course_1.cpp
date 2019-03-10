#include <vector>
#include <iostream>
using namespace std;

const int N =  40;

inline void sum(int*p, int n, vector<int> d) {
    int i; *p = 0;
    for(i = 0; i < n; ++i) {*p = *p + d[i];}
}

int main()

{    int i,accum = 0;
     vector<int> data;
     for(i = 0; i < N; ++i)  {data.push_back(i);}
     sum(&accum, N, data);
     cout << "sum is :" << accum << endl;
     return 0;

}
