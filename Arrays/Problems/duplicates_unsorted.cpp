#include <iostream>
using namespace std;

int* duplicatesUnsorted(int A[], int length, int &duplicateCount) {
    int *duplicates = new int[length];
    duplicateCount = 0;

    for (int i = 0; i < length; i++) {
        bool isDuplicate = false;
        // Check if A[i] is already marked as a duplicate
        for (int k = 0; k < duplicateCount; k++) {
            if (duplicates[k] == A[i]) {
                isDuplicate = true;
                break;
            }
        }

        // If not already marked, check for duplicates in the rest of the array
        if (!isDuplicate) {
            for (int j = i + 1; j < length; j++) {
                if (A[i] == A[j]) {
                    duplicates[duplicateCount++] = A[i];
                    break;
                }
            }
        }
    }

    return duplicates;
}

int main() {
    int arr[] = {4, 3, 2, 4, 1, 3, 2, 5,4,4,4,4};
    int length = sizeof(arr) / sizeof(arr[0]);
    int duplicateCount;

    int* result = duplicatesUnsorted(arr, length, duplicateCount);

    cout << "Duplicate elements: ";
    for (int i = 0; i < duplicateCount; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    delete[] result;
    return 0;
}
