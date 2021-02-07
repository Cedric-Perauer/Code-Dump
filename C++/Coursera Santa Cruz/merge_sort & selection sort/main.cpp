#include <stdio.h>
#include <iostream>

using namespace std;

void Merge(int *arr, int l, int m, int r ) {
    int i ,j,k;
    int right_l = r - m;   //length of right array
    int left_l = m - l +1;   //length of left array

    // temp arrays for storage
    int Left[left_l], Right[right_l];
    for(j = 0; j< right_l;j++) {
    Right[j] = arr[m+ 1 + j];
    }
    for(i = 0; i < left_l; i++) {
    Left[i] = arr[l+i];
    }
    // Merge back
    i = 0, j = 0, k = l;

    while(i < left_l && j < right_l) {

        if(Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;

        }
        else {
            arr[k] = Right[j];
            j++;


        }
        k++;

    }

    while(j < right_l) {
        arr[k] = Right[j];
        j++;
        k++;
    }

    while(i < left_l) {
        arr[k] = Left[i];
        i++;
        k++;
    }

}


//int* array_read(char* text_file){

//}

void selection_sort(int *arr, int size_array) {
    int i = 0;
    int minimum;
    int j;
    int count;
    while(i!=size_array) {
        minimum  =1000;
        for(j = i; j < size_array;j++) {
            cout << "array element " << arr[j] << endl;
            if(arr[j] < minimum) {
                minimum = arr[j];
                count = j;
                //cout << "j : " << j << endl;


            }

        }


        arr[count] = arr[i];
        arr[i] = minimum;
        i++;

    }
}

void Mergesort(int *arr, int l, int r) {

    if(l < r) {



        int m = l + (r-l)/2;
        //recursively call merge sort

        Mergesort(arr,l,m);
         Mergesort(arr,m+1,r);
        Merge(arr, l, m, r);


    }


}

int main() {
    int arr[] =  {5,12,453,76,1};
    int size_of_array = sizeof(arr)/sizeof(arr[0]);

    Mergesort(arr,0,size_of_array-1);
 //  selection_sort(arr,size_of_array);
    for(int a = 0;a < size_of_array;a++){
       cout << arr[a] << endl;
    }

    return 0;
}