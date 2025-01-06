#include <iostream>
using namespace std;

// Function to calculate e^x using Horner's Rule for the Taylor series
double e(int x, int n) {
    static double s = 1; // Static variable to store the result

    // Base case: if n == 0, return the result
    if (n == 0)
        return s;

    // Recursive call to calculate the series sum for (n-1) terms
    s = 1 + x * s / n;

    return e(x, n - 1);
}

int main() {
    // Calculate e^3 using 10 terms of the Taylor series and print the result
    cout << e(3, 10) << endl;

    return 0; // Indicate successful program termination
}

