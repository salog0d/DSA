#include <iostream>
using namespace std;

/*
This program demonstrates two types of recursion:
1. **Descending-Only Recursion (Top-Down)**: The function performs actions during the recursive calls.
2. **Ascending-Descending Recursion (Both Phases)**: The function performs actions after the recursive calls during the "return time".

Key Idea:
- Recursion can be more versatile than loops as it inherently supports both ascending (returning) and descending phases.
- This dual nature is particularly useful in problems like the Fibonacci sequence or tree traversal, where both forward and backward steps are needed.
*/

// Descending-only recursion
// Prints numbers from `n` down to 1
void recursive(int n) {
    if (n > 0) { // Base case: Stops when n <= 0
        cout << n << endl; // Print the current value of n
        recursive(n - 1); // Recursive call with n-1
    }
}

// Ascending-descending recursion
// Prints numbers from 1 to `n`
void recursive2(int n) {
    if (n > 0) { // Base case: Stops when n <= 0
        recursive2(n - 1); // Recursive call with n-1 (descending phase)
        cout << n << endl; // Print the current value of n during the return time (ascending phase)
    }
}

/*
Note on Differences Between Loops and Recursion:
- Loops work in a single direction (ascending or descending).
- Recursion inherently supports a return phase, making it more adaptable for problems with dual-phase requirements (e.g., Fibonacci, pyramids, binary trees).
*/

int main() {
    int x = 3; // Initialize the starting value

    // Call recursive2 to demonstrate ascending-descending behavior
    recursive2(x);

    return 0; // Indicate successful program termination
}
