#include <iostream>
using namespace std;

// Class for Lower Triangular Matrix
class LowerTriangular {
private:
    int *A; // Array to store non-zero elements of the lower triangular matrix
    int n;  // Dimension of the matrix

public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~LowerTriangular() {
        delete[] A;
    }
    void Set(int i, int j, int x) {
        if (i >= j) {
            A[i * (i - 1) / 2 + j - 1] = x;
        }
    }
    int Get(int i, int j) {
        if (i >= j) {
            return A[i * (i - 1) / 2 + j - 1];
        }
        return 0;
    }
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << (i >= j ? Get(i, j) : 0) << " ";
            }
            cout << endl;
        }
    }
};

// Class for Upper Triangular Matrix
class UpperTriangular {
private:
    int *A; // Array to store non-zero elements of the upper triangular matrix
    int n;  // Dimension of the matrix

public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    ~UpperTriangular() {
        delete[] A;
    }
    void Set(int i, int j, int x) {
        if (i <= j) {
            A[j * (j - 1) / 2 + i - 1] = x;
        }
    }
    int Get(int i, int j) {
        if (i <= j) {
            return A[j * (j - 1) / 2 + i - 1];
        }
        return 0;
    }
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << (i <= j ? Get(i, j) : 0) << " ";
            }
            cout << endl;
        }
    }
};

// Class for Diagonal Matrix
class DiagonalMatrix {
private:
    int *A; // Array to store diagonal elements
    int n;  // Dimension of the matrix

public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }
    ~DiagonalMatrix() {
        delete[] A;
    }
    void Set(int i, int j, int x) {
        if (i == j) {
            A[i - 1] = x;
        }
    }
    int Get(int i, int j) {
        if (i == j) {
            return A[i - 1];
        }
        return 0;
    }
    void Display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << (i == j ? Get(i, j) : 0) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Lower Triangular Matrix
    cout << "Lower Triangular Matrix:" << endl;
    LowerTriangular lm(4);
    lm.Set(1, 1, 1);
    lm.Set(2, 1, 2);
    lm.Set(2, 2, 3);
    lm.Set(3, 1, 4);
    lm.Set(3, 2, 5);
    lm.Set(3, 3, 6);
    lm.Set(4, 1, 7);
    lm.Set(4, 2, 8);
    lm.Set(4, 3, 9);
    lm.Set(4, 4, 10);
    lm.Display();

    // Upper Triangular Matrix
    cout << "\nUpper Triangular Matrix:" << endl;
    UpperTriangular um(4);
    um.Set(1, 1, 1);
    um.Set(1, 2, 2);
    um.Set(1, 3, 3);
    um.Set(1, 4, 4);
    um.Set(2, 2, 5);
    um.Set(2, 3, 6);
    um.Set(2, 4, 7);
    um.Set(3, 3, 8);
    um.Set(3, 4, 9);
    um.Set(4, 4, 10);
    um.Display();

    // Diagonal Matrix
    cout << "\nDiagonal Matrix:" << endl;
    DiagonalMatrix dm(4);
    dm.Set(1, 1, 1);
    dm.Set(2, 2, 2);
    dm.Set(3, 3, 3);
    dm.Set(4, 4, 4);
    dm.Display();

    return 0;
}

/*
Output:
Lower Triangular Matrix:
1 0 0 0 
2 3 0 0 
4 5 6 0 
7 8 9 10 

Upper Triangular Matrix:
1 2 3 4 
0 5 6 7 
0 0 8 9 
0 0 0 10 

Diagonal Matrix:
1 0 0 0 
0 2 0 0 
0 0 3 0 
0 0 0 4 
*/
