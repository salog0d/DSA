#include <iostream>
using namespace std;

int* duplicatesHashing(int A[], int length, int &duplicateCount) {
    int *duplicates = new int[length];
    duplicateCount = 0;
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    int *hash = new int[max + 1];
    for (int i = 0; i < max + 1; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        hash[A[i]]++;
    }

    for (int i = 0; i < max + 1; i++) {
        if (hash[i] > 1) {
            duplicates[duplicateCount++] = i;
        }
    }

    delete[] hash;
    return duplicates;
}

int main(){
    int arr[] = {4, 3, 2, 4, 1, 3, 2, 5,4,4,4,4};
    int length = sizeof(arr) / sizeof(arr[0]);
    int duplicateCount;

    int* result = duplicatesHashing(arr, length, duplicateCount);

    cout << "Duplicate elements: ";
    for (int i = 0; i < duplicateCount; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
    return 0;
}