#include <iostream>
#include <vector>
using namespace std;

// Function to compute the nth Fibonacci number using recursion and memoization
int fibonacci(int n, std::vector<int>& memo) {
    // Base case: return n if it's 0 or 1
    if (n <= 1) {
        return n;
    }
    // If the value has not been computed yet, compute it
    if (memo[n] == -1) {
        // Recursive calls for the two preceding numbers
        memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    }
    // Return the computed value
    return memo[n];
}

int main() {
    int n = 10; // Example: compute the 10th Fibonacci number

    // Initialize a memoization vector with -1 to indicate uncomputed values
    vector<int> memo(n + 1, -1);

    // Compute and display the nth Fibonacci number
    cout << "Fibonacci(" << n << ") = " << fibonacci(n, memo) <<endl;

    return 0;
}
