#include <iostream>
using namespace std;

int main() {
    // Declare a 3D array with dimensions 3x3x3
    int array[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        },
        {
            {19, 20, 21},
            {22, 23, 24},
            {25, 26, 27}
        }
    };

    // Accessing elements in the 3D array
    cout << "Element at [0][0][0]: " << array[0][0][0] << endl;
    cout << "Element at [2][2][2]: " << array[2][2][2] << endl;

    return 0;
}