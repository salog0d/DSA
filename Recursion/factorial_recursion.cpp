#include <iostream>
using namespace std;

/* 
Function to calculate the factorial of a number using recursion.
Factorial Definition:
    n! = n × (n-1) × (n-2) × ... × 1
    Special Case: 0! = 1
*/

// Function to compute the factorial of a number
int factorial(int n) {
    // Base case: Factorial of 0 is defined as 1
    if (n == 0)
        return 1;

    // Recursive case: Multiply n by the factorial of (n-1)
    return factorial(n - 1) * n;
}

int main() {
    int r; // Variable to store the result of the factorial computation

    // Call the 'factorial' function to calculate 10! and store the result in 'r'
    r = factorial(10);

    // Output the result to the console
    cout << r << endl;

    return 0; // Indicate successful program termination
}
