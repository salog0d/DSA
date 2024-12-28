#include <iostream>
using namespace std;

void multipleMissing(int A[], int length){
    int n=0;
    int diff = A[0];
    int miss[n];
        for(int i=0; i<length; i++){ //length of A
            if(A[i]-i != diff){
                miss[n] = i+diff;
                    n++;
        }
    }

    for(int i=0;i<n;i++){
        cout << "The missing element: " << miss[i]<<endl;
    }
}

int main(){
    int A[5] = {1,2,4,5,7};
    multipleMissing(A, 5);

}