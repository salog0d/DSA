#include <iostream>
using namespace std;

// Function to calculate e^x using the Taylor series up to n terms
double e(int x , int n){
    // Static variables to store intermediate results
    // 'p' is used to store the power of x (x^n)
    // 'f' is used to store the factorial of n (n!)
    static double p = 1, f = 1;
    double r; // Variable to store the result of the recursive call

    // Base case: if n == 0, return the first term of the series, which is 1
    if(n == 0)
        return 1;

    // Recursive call to calculate the series sum for (n-1) terms
    r = e(x, n - 1);

    // Update 'p' and 'f' for the current term
    p = p * x;    // Compute x^n
    f = f * n;    // Compute n!

    // Return the sum of the series up to (n-1) terms and the nth term (p/f)
    return r + p / f;
}

double e2(int x , int n){
    double s=1;
    int i;
    double num = 1;
    double den = 1;

    for(i=1;i<=n;i++){
        nunm*=x;
        den*=i;
        s*=num/den;
    }
    
    return s;
}

int main(){
    // Calculate e^3 using 10 terms of the Taylor series and print the result
    cout << e(3, 10) << endl;

    return 0; // Indicate successful program termination
}
