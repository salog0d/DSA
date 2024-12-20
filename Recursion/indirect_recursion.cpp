#include <iostream>
using namespace std;

/* 
This code demonstrates *mutual recursion*, where two functions call each other.
- `funA`: Prints the current value of `n` and calls `funB` with `n-1` if `n > 0`.
- `funB`: Prints the current value of `n` and calls `funA` with `n/2` if `n > 1`.
The recursion continues until the base conditions are met.
*/

// Function prototype for funB (declared before funA for mutual recursion)
void funB(int n);

// Function funA: Prints the value of `n` and calls funB with `n-1`
void funA(int n) {
    if (n > 0) { // Base condition to stop recursion when n <= 0
        cout << n << endl; // Print the current value of n
        funB(n - 1); // Call funB with the updated value (n-1)
    }
}

// Function funB: Prints the value of `n` and calls funA with `n/2`
void funB(int n) {
    if (n > 1) { // Base condition to stop recursion when n <= 1
        cout << n << endl; // Print the current value of n
        funA(n / 2); // Call funA with the updated value (n/2)
    }
}

int main() {
    int n = 20; // Initialize the starting value of n

    // Start the mutual recursion by calling funA
    funA(n);

    return 0; // Indicate successful program termination
}
