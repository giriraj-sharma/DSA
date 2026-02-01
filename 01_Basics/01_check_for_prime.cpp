#include <iostream>
using namespace std;

// TC: O(√n)
// SC: O(1)
bool isPrime(int n) {

    // Numbers <= 1 are not prime
    if (n <= 1)
        return false;

    // Check divisibility up to √n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}