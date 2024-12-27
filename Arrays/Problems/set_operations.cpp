#include <iostream>
using namespase std;

//Check if sorted
bool sorted(int array[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

// Union not sorted
void union_unsorted(int A[], int lenA, int B[], int lenB, int C[], int &lenC) {
    int i = 0, j = 0;
    lenC = 0;

    // Copy all elements of A to C
    for (i = 0; i < lenA; i++) {
        bool found = false;
        for (j = 0; j < lenC; j++) {
            if (A[i] == C[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            C[lenC++] = A[i];
        }
    }

    // Copy elements of B to C if they are not already in C
    for (i = 0; i < lenB; i++) {
        bool found = false;
        for (j = 0; j < lenC; j++) {
            if (B[i] == C[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            C[lenC++] = B[i];
        }
    }
}

//Union sorted

void union_sorted(int A[], int lenA, int B[], int lenB, int C[], int &lenC) {
    int i = 0, j = 0;
    lenC = 0;

    
}


//Diference
