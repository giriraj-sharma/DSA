#include <iostream>
using namespace std;

// TC: O(n^3)  (printing included)
// SC: O(1)
int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Start index of subarray
    for (int i = 0; i < n; i++) {

        // End index of subarray
        for (int j = i; j < n; j++) {

            // Print elements from i to j
            for (int k = i; k <= j; k++) {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}