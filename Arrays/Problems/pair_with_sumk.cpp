#include <iostream>
using namespace std;

#include <iostream>

void findPair(int arr[], int n, int targetSum) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == targetSum) {
                cout << "Pair found at index " << i << " and " << j << std::endl;
                return;
            }
        }
    }
    cout << "Pair not found" << std::endl;
}

int main(){
    int arr[] = { 3, 2, 4, 1, 2, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int sum= 7;
    findPair(arr, length, sum);
    return 0;
}