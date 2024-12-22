#include <iostream>
using namespace std;

int main() {
    // Declare a 2D array with 3 rows and 4 columns
    //Method 1
    int array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    /*
    //Method 2
    int *A[3];// Array of pointers to integer arrays
    A[0] = new int[4];// Dynamically allocate memory for each row
    A[1] = new int[4];// Dynamically allocate memory for each row
    A[2] = new int[4];// Dynamically allocate memory for each row
    
    //Method 3
    int **A;
    A=new int*[3];// Dynamically allocate memory for the array of pointers
    A[0] = new int[4];// Dynamically allocate memory for each row
    A[1] = new int[4];// Dynamically allocate memory for each row
    A[2] = new int[4];// Dynamically allocate memory for each row

    */

    //Variables declared with new are in the heap memory

    // Accessing elements in the 2D array
    cout << "Element at [0][0]: " << array[0][0] << endl;
    cout << "Element at [2][3]: " << array[2][3] << endl;

    // Print the 2D array
    //Time complexity: O(n^2)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
           cout << array[i][j] << " ";
        }
       cout << endl;
    }

    /*
    // Free the memory allocated for the array of pointers
    delete[] A[0];
    delete[] A[1];
    delete[] A[2];
    delete[] A;
    */

    return 0;
}

