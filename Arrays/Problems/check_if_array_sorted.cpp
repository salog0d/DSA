#include <iostream>
#include<array> 
using namespace std;

void length(int array[]){
    int length = sizeof(myArray) / sizeof(myArray[0]);
    return length;
}

bool sorted(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void insertElement(int array[], int x){
    int m= length(array[]);
    i= m-1;
    while(array[i]>x){
        array[i+1]=array[i];
        i--;
    }
    A[i+1]=x;
    return array[];
}

int main(){

    int myArray[] = {1, 4, 3, 4, 5};
    int length = sizeof(myArray) / sizeof(myArray[0]);
    bool isSorted = sorted(myArray, length);
    cout<<"The array is sorted: "<< isSorted << endl;

}