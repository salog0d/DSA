#include <iostream>
using namespace std;

int sum(int A[] , int n){
    int s,i;
    s=0;//1
    for(int i=0 ; i<n ; i++){ // n+1
        s=s+A[i];// 1
    }
    return s;
}

/* Time complexity of O(n2)*/

void swap(x,y){
    int t;
    t=x;// 1
    x=y// 1
    y=t// 1
}

/* Time complexity of O(1)*/

void add(int n){
    int i,j;
    for(i=0 ; i<n ;i++){// n+1
        for(j=0 ; j<n ; j++){ // n x (n+1) 
            c[i][j] = A[i][j] + B[i][j]; // n x n
        }
    }
}

/* Time complexity of O(n2)*/

int main(){
    int B [] = {1,2,3,4,5,6};
    int c = 5;
    int suma=0;

    suma = sum(B,c);
    cout<<suma<<endl;
}

