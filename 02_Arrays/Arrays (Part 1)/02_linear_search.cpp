#include <iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
int linearSearch(int arr[], int n, int key) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   // key found at index i
    }

    return -1;          // key not found
}

int main() {
    int n, key;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    int index = linearSearch(arr, n, key);

    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}