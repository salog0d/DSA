#include <iostream>
using namespace std;

int fact(int n) {
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return -1; // Indicate an error
    }
    if (n <= 1)
        return 1;
    return fact(n - 1) * n;
}

int comb(int n, int r) {
    if (n < 0 || r < 0) {
        cout << "n and r must be non-negative." << endl;
        return -1; // Indicate an error
    }
    if (r > n) {
        cout << "r cannot be greater than n." << endl;
        return -1; // Indicate an error
    }
    int t1 = fact(n);
    int t2 = fact(r);
    int t3 = fact(n - r);
    if (t1 == -1 || t2 == -1 || t3 == -1) {
        cout << "Error in factorial calculation." << endl;
        return -1; // Indicate an error
    }
    return t1 / (t2 * t3);
}

int main() {
    int n = 8;
    int r = 1;
    int combinacion = comb(n, r);
    if (combinacion != -1)
        cout << "C(" << n << ", " << r << ") = " << combinacion << endl;
    return 0;
}
