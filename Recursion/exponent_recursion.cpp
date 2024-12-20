#include <iostream>
using namespace std;

/* 
Function to calculate the result of raising a number 'n' to the power of 'm'.
The function uses recursion to achieve this. 
Key Concept: An exponent indicates the number of times a number is multiplied by itself.
*/

// Function to compute n^m recursively
int exponente(int m, int n){
    // Base case: Any number raised to the power of 0 is 1
    if(m == 0)
        return 1;

    // Recursive step: Multiply n by the result of n^(m-1)
    return exponente(m - 1, n) * n;
}

int main(){
    int n; // Variable to store the result of the exponentiation

    // Call the 'exponente' function to calculate 4^3 and store the result in 'n'
    n = exponente(3, 4); // Here, 4 is raised to the power of 3 (4^3)

    // Output the result to the console
    cout << n << endl;

    return 0; // Indicate successful program termination
}
