#include <iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
int main() {
    char str[100];
    cin.getline(str, 100);

    // Find length manually
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int start = 0, end = len - 1;

    // Two-pointer approach
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }

    cout << str << endl;

    return 0;
}