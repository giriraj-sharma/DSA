#include <iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0, end = n - 1;

    // Two-pointer approach
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // Print reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}