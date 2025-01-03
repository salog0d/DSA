#include <iostream>
using namespace std;

class triDiagonalMatrix{
private:
    int n;
    int *A;
public:
    triDiagonalMatrix(int n){
        this->n = n;
        A = new int[3*n-2];
    }
    ~triDiagonalMatrix(){
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void triDiagonalMatrix::set(int i, int j, int x){
    if(i-j == 1){
        A[i-2] = x;
    }else if(i-j == 0){
        A[n+i-2] = x;
    }else if(i-j == -1){
        A[2*n+i-2] = x;
    }
}

int triDiagonalMatrix::get(int i, int j){
    if(i-j == 1){
        return A[i-2];
    }else if(i-j == 0){
        return A[n+i-2];
    }else if(i-j == -1){
        return A[2*n+i-2];
    }else{
        return 0;
    }
}

void triDiagonalMatrix::display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i-j == 1){
                cout << A[i-2] << " ";
            }else if(i-j == 0){
                cout << A[n+i-2] << " ";
            }else if(i-j == -1){
                cout << A[2*n+i-2] << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main(){
    triDiagonalMatrix tm(4);
    tm.set(1, 1, 1);
    tm.set(1, 2, 2);
    tm.set(1, 3, 3);
    tm.set(2, 1, 4);
    tm.set(2, 2, 5);
    tm.set(2, 3, 6);
    tm.set(3, 2, 7);
    tm.set(3, 3, 8);
    tm.set(3, 4, 9);
    tm.set(4, 3, 10);
    tm.set(4, 4, 11);
    tm.display();
}

