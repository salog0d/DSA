#include <iostream>
using namespace std;

int* findDuplicates(int A[], int length, int &dupCount) {
    int* dup = new int[length]; // Allocate memory for duplicates
    dupCount = 0; // Initialize the count of duplicates

    for (int i = 0; i < length - 1; i++) {
        if (A[i] == A[i + 1]) {
            if (dupCount == 0 || dup[dupCount - 1] != A[i]) { 
                dup[dupCount] = A[i];
                dupCount++;
            }
        }
    }
    return dup; // Return the dynamically allocated array
}

int main() {
    int A[] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 9, 9, 10, 10, 11, 12};
    int lenA = sizeof(A) / sizeof(A[0]);

    int dupCount; // To store the count of duplicates
    int* duplicates = findDuplicates(A, lenA, dupCount);

    cout << "Los duplicados encontrados son: ";
    for (int i = 0; i < dupCount; i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;

    delete[] duplicates; // Free the allocated memory
    return 0;
}
