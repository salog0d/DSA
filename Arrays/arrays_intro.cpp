#include <iostream>
using namespace std;

int main(){

/* Declaring an Array*/
int A[5];
int A2[5] = {1,2,3,4,5};
int A3[5] = {2,4};
int A4[5] = {0};
int A5[] = {2,4,5,8,2};

int * P;
P = new int[5];

for(int i=0; i< sizeof(A2); i++){
    cout<<A2[i]<<endl;
}

 delete [] P;
}