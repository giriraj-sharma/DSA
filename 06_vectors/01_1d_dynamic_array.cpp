#include <iostream>
using namespace std;

// TC: O(n) for input/output
// SC: O(n)
int main() {
    int n;
    cin >> n;

    // Create dynamic array
    int* arr = new int[n];

    // Input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Output
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Free memory
    delete[] arr;
    arr = nullptr;

    return 0;
}