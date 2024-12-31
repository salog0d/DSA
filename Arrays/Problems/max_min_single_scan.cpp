#include <iostream>
using namespace std;

void maxAndMin(int A[], int len){
    int max=A[0];
    int min=A[0];

    for(int i=0;i<len;i++){
        if(A[i]>max){
            max=A[i];
        }
        if(A[i]<min){
            min=A[i];
        }
    }
    cout<<"El valor minimo es: "<<min<<"Mientas que el valor maximo es: "<<max<<endl;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    int len=sizeof(A)/sizeof(A[0]);
    maxAndMin(A,len);
    return 0;
}
