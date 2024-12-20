#include <iostream>
using namespace std;

/*
This code demonstrates an example of *nested recursion*, 
where the function calls itself as an argument to another recursive call.
- If `n > 100`, the function returns `n - 10`.
- Otherwise, the function calls itself twice with `n + 11` as the argument.
*/

// Function to compute the result using nested recursion
int fun(int n) {
    if (n > 100) { // Base case: If n is greater than 100, return n - 10
        return n - 10;
    } else {
        // Recursive case: Call the function with the result of another recursive call
        return fun(fun(n + 11));
    }
}

int main() {
    int r; // Variable to store the result of the function call

    // Call the recursive function with an initial value of 95
    r = fun(95);

    // Output the result to the console
    cout << r << endl;

    return 0; // Indicate successful program termination
}
