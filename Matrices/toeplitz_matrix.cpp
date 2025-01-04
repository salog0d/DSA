#include <iostream>
using namespace std;

class toepMatrix{
private:
    int n;
    int *A;
public:
    toepMatrix(int n){
        this->n = n;
        A = new int[2*n-1];
    }
    ~toepMatrix(){
        delete[] A;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

void toepMatrix::set(int i, int j, int x){
    if(i<=j){
        A[j-i] = x;
    }else{
        A[n+i-j-1] = x;
    }
}

int toepMatrix::get(int i, int j){
    if(i<=j){
        return A[j-i];
    }else{
        return A[n+i-j-1];
    }
}

void toepMatrix::display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i<=j){
                cout << A[j-i] << " ";
            }else{
                cout << A[n+i-j-1] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    toepMatrix tm(4);
    tm.set(1, 1, 1);
    tm.set(1, 2, 2);
    tm.set(1, 3, 3);
    tm.set(1, 4, 4);
    tm.set(2, 1, 5);
    tm.set(3, 1, 6);
    tm.set(4, 1, 7);
    tm.set(4, 2, 8);
    tm.set(4, 3, 9);
    tm.display();
    return 0;
}

