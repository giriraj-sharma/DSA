#include <iostream>
using namespace std;

// TC: O(r * c)
// SC: O(r * c)
int main() {
    int r, c;
    cin >> r >> c;

    // Create array of row pointers
    int** arr = new int*[r];

    // Create columns for each row
    for (int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }

    // Input
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    // Output
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    return 0;
}