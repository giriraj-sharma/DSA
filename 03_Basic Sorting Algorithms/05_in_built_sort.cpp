#include <iostream>
#include <algorithm>
using namespace std;

// TC: O(n log n)
// SC: O(1) extra (introsort)
int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // In-built sort (ascending order)
    sort(arr, arr + n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// sort(arr, arr + n, greater<int>());