#include <iostream>
using namespace std;

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

    while (i < lenA && j < lenB) {
        if (A[i] < B[j]) {
            C[lenC++] = A[i++];
        } else if (B[j] < A[i]) {
            C[lenC++] = B[j++];
        } else {
            C[lenC++] = A[i++];
            j++;
        }
    }

    for (; i < lenA; i++) {
        C[lenC++] = A[i];
    }

    for (; j < lenB; j++) {
        C[lenC++] = B[j];
    }
}

//Intersection not sorted

void intersection_unsorted(int A[], int lenA, int B[], int lenB, int C[], int &lenC) {
    int i = 0, j = 0;
    lenC = 0;

    for(int i=0; i<lenA; i++) {
        for(int j=0; j<lenB; j++) {
            if(A[i] == B[j]) {
                C[lenC++] = A[i];
                break;
            }
           
        }
    }
}



//Intersection sorted

void intersection_sorted(int A[], int lenA, int B[], int lenB, int C[], int &lenC) {
    int i = 0, j = 0;
    lenC = 0;

    while(i < lenA && j < lenB) {
        if(A[i] < B[j]) {
            i++;
        } else if(B[j] < A[i]) {
            j++;
        } else if(A[i] == B[j]) {
            C[lenC++] = A[i++];
            j++;
        }
    }
}



//Diference

void difference(int A[], int lenA, int B[], int lenB, int C[], int &lenC) {
    int i = 0, j = 0;
    lenC = 0;

    while(i < lenA && j < lenB){
        if(A[i] < B[j]){
            C[lenC++] = A[i++];
        } else if(B[j] < A[i]){
            j++;
        } else {
            i++;
            j++;
        }
    }
}


int main() {
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {3, 4, 5, 6, 7};
    int lenA = sizeof(A) / sizeof(A[0]);
    int lenB = sizeof(B) / sizeof(B[0]);
    int C[lenA + lenB];
    int lenC;

    // Check if arrays are sorted
    cout << "Is A sorted? " << (sorted(A, lenA) ? "Yes" : "No") << endl;
    cout << "Is B sorted? " << (sorted(B, lenB) ? "Yes" : "No") << endl;

    // Union (unsorted)
    union_unsorted(A, lenA, B, lenB, C, lenC);
    cout << "Union (unsorted): ";
    for (int i = 0; i < lenC; i++) cout << C[i] << " ";
    cout << endl;

    // Union (sorted)
    union_sorted(A, lenA, B, lenB, C, lenC);
    cout << "Union (sorted): ";
    for (int i = 0; i < lenC; i++) cout << C[i] << " ";
    cout << endl;

    // Intersection (unsorted)
    intersection_unsorted(A, lenA, B, lenB, C, lenC);
    cout << "Intersection (unsorted): ";
    for (int i = 0; i < lenC; i++) cout << C[i] << " ";
    cout << endl;

    // Intersection (sorted)
    intersection_sorted(A, lenA, B, lenB, C, lenC);
    cout << "Intersection (sorted): ";
    for (int i = 0; i < lenC; i++) cout << C[i] << " ";
    cout << endl;

    // Difference (A - B)
    difference(A, lenA, B, lenB, C, lenC);
    cout << "Difference (A - B): ";
    for (int i = 0; i < lenC; i++) cout << C[i] << " ";
    cout << endl;

    return 0;
}