#include <iostream>

int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearchRecursive(arr, left, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearchRecursive(arr, mid + 1, right, x);
    }

    // Element is not present in array
    return -1;
}

int binarySearchIterative(int arr[], int size, int x) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // Element is not present in array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int resultRecursive = binarySearchRecursive(arr, 0, size - 1, x);
    int resultIterative = binarySearchIterative(arr, size, x);

    if (resultRecursive != -1)
        std::cout << "Element is present at index (recursive): " << resultRecursive << std::endl;
    else
        std::cout << "Element is not present in array (recursive)" << std::endl;

    if (resultIterative != -1)
        std::cout << "Element is present at index (iterative): " << resultIterative << std::endl;
    else
        std::cout << "Element is not present in array (iterative)" << std::endl;

    return 0;
}