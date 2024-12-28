#include <iostream>
using namespace std;

int missingElement(int A[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i];
    }
    int total = (n+1)*(n+2)/2;
    return total - sum;
}

int missingEllement2(int A[], int n){
    int diff = A[0];
    for(int i=0; i<n; i++){
        if(A[i] -i != diff){
            return i+diff;
        }
        }
    }

int multipleMissing(int A[], int n){
    int diff = A[0];
    int missing [];
    for(int i=0; i<length; i++){ //length of A
        if(A[i]-i != diff){
            missing[n++]= A[i];
        }
    }
    for(int i=0; i<length; i++){//length of B
        cout<<'the missing elements are' << B[i]<< endl;

}

//Make another solution by yourself