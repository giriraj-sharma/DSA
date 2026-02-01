#include <iostream>
using namespace std;

// TC: O(log n)
// SC: O(1)
// Works only on SORTED array
int binarySearch(int arr[], int n, int key) {

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;        // key found
        else if (arr[mid] < key)
            start = mid + 1;   // search right half
        else
            end = mid - 1;     // search left half
    }

    return -1;                 // key not found
}

int main() {
    int n, key;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}