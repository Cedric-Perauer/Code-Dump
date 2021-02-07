#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <memory>

using namespace std;
long long int Merge(long long int *arr,long long int *temp, long long int l, long long int m, long long int r );
long long int Mergesort( long long int *arr,long long int *temp,  long long int l,  long long int r);

long long int mergeSort(long long int arr[],long long int array_size)
{

    long long int *temp = new long long int[100000];


    return Mergesort(arr, temp, 0, array_size - 1);
}
long long int Mergesort( long long int *arr,long long int *temp,  long long int l,  long long int r) {
    long long int c = 0;
    long long int m;

    if(r > l) {
        m = (r+l)/2;
        //recursively call merge sort
        c = Mergesort(arr,temp,l,m);
        c += Mergesort(arr,temp,m+1,r);
        c +=  Merge(arr,temp, l, m+1, r);
        // cout << "c " << c << endl;
    }
    return c;
}
long long int Merge(long long int arr[], long long int *temp, long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int inv_count = 0;

    i = l; j = m; k = l;
    while ((i < m ) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];


            inv_count = inv_count + (m - i);
        }
    }

   //copy remaining
    while (i < m )
        temp[k++] = arr[i++];


    while (j <= r)
        temp[k++] = arr[j++];

    //copy merged back into original
    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return inv_count;
}



long long int* read_array(string file_name, long long int *a){
    ifstream myfile;
    string line;
    myfile.open(file_name);

    long long int i =0;

    while (myfile.good()) {   //myfile.good() makes sure to check for empty line

        getline(myfile, line);

        if(stoll(line)!=0) {



            a[i] = stoll(line);
            i++;
            //cout << a[i] << endl;

        }

    }
    return a;
}

int main() {
    long long int arr[] = {8,9,0,3};
    int t_start = clock();
    int end;
    cout << mergeSort(arr,4) << endl;
    end = clock();
    for(auto &z : arr) {
        cout << z << endl;
    }
    cout << " run time : " << end-t_start << " milliseconds" << endl;

    return 0;
}
