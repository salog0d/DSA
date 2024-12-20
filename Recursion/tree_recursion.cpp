#include <iostream>
using namespace std;

/*
This program demonstrates **tree recursion**, where the function calls itself multiple times.
- For each call to `fun(n)`, the function recursively calls itself twice with `n-1`.
- This results in a tree-like structure of recursive calls.

Key Idea:
- The function prints `n` during the descending phase and then branches into two recursive calls for `n-1`.
- Each recursive branch repeats this process until the base case is reached.
*/

// Function demonstrating tree recursion
void fun(int n) {
    if (n > 0) { // Base case: Stops recursion when n <= 0
        cout << n << endl; // Print the current value of n
        fun(n - 1); // First recursive call with n-1
        fun(n - 1); // Second recursive call with n-1
    }
}

int main() {
    int n = 3; // Initialize the starting value

    // Call the recursive function
    fun(n);

    return 0; // Indicate successful program termination
}
