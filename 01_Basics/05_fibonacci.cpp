#include <iostream>
using namespace std;

// TC: O(N)
// SC: O(1)
int main() {
    int N;
    cin >> N;   // Assume N >= 2

    int a = 0, b = 1;

    // Print first two Fibonacci numbers
    cout << a << " " << b << " ";

    // Print remaining N-2 numbers
    for (int i = 3; i <= N; i++) {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }

    return 0;
}