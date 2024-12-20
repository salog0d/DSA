#include <iostream>
using namespace std;

/*
This program calculates the value of e^x using two different recursive methods:
1. Using the traditional Taylor series with the formula:
   e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!
2. Using a more compact recursive formula: 
   s(n) = 1 + x * s(n-1) / n, where s(0) = 1.

The first method calculates `e^x` using an iterative formula with multiplication for `x` and factorial `n`, 
and the second method uses a recursive approach directly based on the Taylor series expansion.
*/

// First method: Taylor Series with multiplication and factorial
// This method calculates e^x using the formula:
// e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + x^n/n!
double e1(int x, int n) {
    static double p = 1, f = 1; // p = x^n (power), f = n! (factorial)
    double r;

    if (n == 0) // Base case: when n = 0, return 1 (e^x is 1 at n = 0)
        return 1;

    // Recursive call for the Taylor series sum up to (n-1)
    r = e1(x, n - 1);

    // Update the power (p = p * x) and factorial (f = f * n)
    p = p * x;
    f = f * n;

    // Add the current term to the sum and return the result
    return r + p / f;
}

// Second method: Compact recursive Taylor series formula
// This method calculates e^x using the recursive relation:
// s(n) = 1 + x * s(n-1) / n, where s(0) = 1.
double e2(int x, int n) {
    static double s = 1; // s is the accumulator for the result (starts at 1)

    if (n == 0) // Base case: when n = 0, return s which holds the final result
        return s;

    // Update s with the new term for e^x and recursively call e2 for (n-1)
    s = 1 + (x * s) / n;
    return e2(x, n - 1);
}

int main() {
    // Calculate e^4 using the first method with 15 terms
    cout << "Using method 1 (Taylor series with multiplication and factorial): " << e1(4, 15) << endl;

    // Calculate e^2 using the second method with 10 terms
    cout << "Using method 2 (Compact recursive Taylor series): " << e2(2, 10) << endl;

    return 0; // End of the program
}
