#include <iostream>
using namespace std;

/*
This program calculates the sum of the first `n` natural numbers using recursion.
Key Idea:
- The sum of the first `n` natural numbers is given by:
  Sum = 1 + 2 + 3 + ... + n
- This can also be represented recursively:
  sum(n) = n + sum(n-1), with the base case sum(0) = 0.
*/

// Function to compute the sum of the first `n` natural numbers
int sum(int n) {
    if (n == 0) { // Base case: Sum of the first 0 numbers is 0
        return 0;
    } else {
        // Recursive case: Add `n` to the sum of numbers up to (n-1)
        return sum(n - 1) + n;
    }
}

int main() {
    int r; // Variable to store the result of the sum

    // Call the `sum` function to compute the sum of the first 15 natural numbers
    r = sum(15);

    // Output the result to the console
    cout << r << endl;

    return 0; // Indicate successful program termination
}
