#include <iostream>

int main() {
    int originalSize = 5;
    int newSize = 10;

    // Allocate original array
    int* array = new int[originalSize];

    // Initialize original array
    for (int i = 0; i < originalSize; ++i) {
        array[i] = i + 1;
    }

    // Allocate new array with larger size
    int* newArray = new int[newSize];

    // Copy elements from original array to new array
    for (int i = 0; i < originalSize; ++i) {
        newArray[i] = array[i];
    }

    // Initialize remaining elements in new array
    for (int i = originalSize; i < newSize; ++i) {
        newArray[i] = 0; // or any default value
    }

    // Deallocate original array
    delete[] array;

    // Update array pointer to new array
    array = newArray;

    // Use the resized array
    for (int i = 0; i < newSize; ++i) {
        std::cout << array[i] << " ";
    }

    // Clean up
    delete[] array;

    return 0;
}
