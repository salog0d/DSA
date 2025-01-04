#include <iostream>
using namespace std;

// Array class definition
class Array {
private:
    int *A;   // Pointer to dynamically allocate array elements
    int size; // Maximum size of the array
    int length; // Current number of elements in the array
    void swap(int *x, int *y); // Utility to swap two elements

public:
    // Constructors
    Array() { // Default constructor
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) { // Parameterized constructor
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() { // Destructor to release allocated memory
        delete[] A;
    }

    // Core methods
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    int isSorted();
    void Rearrange();
    Array* Merge(Array arr2);
    Array* Union(Array arr2);
    Array* Diff(Array arr2);
    Array* Inter(Array arr2);
};

// --- Method Explanations and Implementations ---

// **Display Method**
// Purpose: Prints all elements of the array.
// Complexity: O(n), where n is the number of elements in the array.
void Array::Display() {
    cout << "\nElements are: ";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

// **Append Method**
// Purpose: Adds an element at the end of the array if there is space.
// Complexity: O(1).
void Array::Append(int x) {
    if (length < size)
        A[length++] = x;
}

// **Insert Method**
// Purpose: Inserts an element at a specified index, shifting elements as needed.
// Complexity: O(n) in the worst case, where n is the number of elements.
void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

// **Delete Method**
// Purpose: Removes an element at a specified index and shifts elements to fill the gap.
// Complexity: O(n) in the worst case.
int Array::Delete(int index) {
    if (index >= 0 && index < length) {
        int x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    return -1; // Invalid index
}

// **LinearSearch Method**
// Purpose: Searches for an element using a linear scan.
// Complexity: O(n) in the worst case.
int Array::LinearSearch(int key) {
    for (int i = 0; i < length; i++) {
        if (A[i] == key) {
            swap(&A[i], &A[0]); // Improves efficiency of subsequent searches
            return i;
        }
    }
    return -1; // Not found
}

// **BinarySearch Method**
// Purpose: Searches for an element in a sorted array using the binary search algorithm.
// Complexity: O(log n), where n is the number of elements.
int Array::BinarySearch(int key) {
    int l = 0, h = length - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1; // Not found
}

// **Get Method**
// Purpose: Returns the element at a specified index.
// Complexity: O(1).
int Array::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1; // Invalid index
}

// **Set Method**
// Purpose: Updates the value at a specified index.
// Complexity: O(1).
void Array::Set(int index, int x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

// **Max Method**
// Purpose: Finds the maximum value in the array.
// Complexity: O(n).
int Array::Max() {
    int max = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

// **Min Method**
// Purpose: Finds the minimum value in the array.
// Complexity: O(n).
int Array::Min() {
    int min = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

// **Sum Method**
// Purpose: Computes the sum of all elements in the array.
// Complexity: O(n).
int Array::Sum() {
    int s = 0;
    for (int i = 0; i < length; i++)
        s += A[i];
    return s;
}

// **Avg Method**
// Purpose: Computes the average of all elements in the array.
// Complexity: O(n), as it uses the `Sum` method.
float Array::Avg() {
    return (float)Sum() / length;
}

// **Reverse Method**
// Purpose: Reverses the array by creating an auxiliary array.
// Complexity: O(n).
void Array::Reverse() {
    int *B = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (int i = 0; i < length; i++)
        A[i] = B[i];
    delete[] B;
}

// **Reverse2 Method**
// Purpose: Reverses the array in-place by swapping elements.
// Complexity: O(n/2) = O(n).
void Array::Reverse2() {
    for (int i = 0, j = length - 1; i < j; i++, j--)
        swap(&A[i], &A[j]);
}

// **InsertSort Method**
// Purpose: Inserts an element into its correct position in a sorted array.
// Complexity: O(n) in the worst case.
void Array::InsertSort(int x) {
    if (length == size)
        return;
    int i = length - 1;
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

// **isSorted Method**
// Purpose: Checks if the array is sorted.
// Complexity: O(n).
int Array::isSorted() {
    for (int i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1])
            return 0;
    }
    return 1;
}

// **Rearrange Method**
// Purpose: Rearranges the array such that all negative elements come before non-negative elements.
// Complexity: O(n).
void Array::Rearrange() {
    int i = 0, j = length - 1;
    while (i < j) {
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}

// **Merge Method**
// Purpose: Merges two sorted arrays into one sorted array.
// Complexity: O(n + m), where n and m are the lengths of the two arrays.
Array* Array::Merge(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    while (i < length)
        arr3->A[k++] = A[i++];
    while (j < arr2.length)
        arr3->A[k++] = arr2.A[j++];
    arr3->length = k;
    return arr3;
}

// **Union Method**
// Purpose: Finds the union of two sorted arrays.
// Complexity: O(n + m).
Array* Array::Union(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    while (i < length)
        arr3->A[k++] = A[i++];
    while (j < arr2.length)
        arr3->A[k++] = arr2.A[j++];
    arr3->length = k;
    return arr3;
}

// **Inter Method**
// Purpose: Finds the intersection of two sorted arrays.
// Complexity: O(n + m).
Array* Array::Inter(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

// **Diff Method**
// Purpose: Finds the difference of two sorted arrays (elements in the first array but not in the second).
// Complexity: O(n + m).
Array* Array::Diff(Array arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    while (i < length)
        arr3->A[k++] = A[i++];
    arr3->length = k;
    return arr3;
}

// --- Main Function ---
int main() {
    Array arr1(10);
    arr1.Append(10);
    arr1.Append(20);
    arr1.Append(30);
    arr1.Display();

    arr1.Insert(1, 15);
    arr1.Display();

    cout << "Deleted: " << arr1.Delete(2) << endl;
    arr1.Display();

    cout << "Linear Search for 15: " << arr1.LinearSearch(15) << endl;
    arr1.Display();

    cout << "Max: " << arr1.Max() << ", Min: " << arr1.Min() << endl;
    cout << "Sum: " << arr1.Sum() << ", Average: " << arr1.Avg() << endl;

    arr1.Reverse2();
    arr1.Display();

    return 0;
}