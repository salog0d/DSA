#include <iostream>
using namespace std;

//merging two arrays

void merge(int A[], int B[], int lenA, int lenB, int C[], int &lenC){
    int i=0, j=0;
    lenC=0;

    while(i<lenA && j<lenB){
        if(A[i]<B[j]){
            C[lenC++]=A[i++];
        }else{
            C[lenC++]=B[j++];
        }
    }
    for(;i<lenA;i++){
        C[lenC++]=A[i];
    }

    for(;j<lenB;j++){
        C[lenC++]=B[j];
    }
}