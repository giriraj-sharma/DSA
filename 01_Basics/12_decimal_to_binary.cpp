#include <iostream>
using namespace std;

// TC: O(log n)
// SC: O(1)
long long decimalToBinary(int n) {

    long long binary = 0;
    int place = 1;

    while (n > 0) {
        int rem = n % 2;
        binary += rem * place;
        place *= 10;
        n /= 2;
    }

    return binary;
}

int main() {
    int n;
    cin >> n;

    cout << decimalToBinary(n) << endl;

    return 0;
}