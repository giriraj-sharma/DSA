#include <iostream>
using namespace std;

// TC: O(d) where d = number of bits
// SC: O(1)
int binaryToDecimal(long long binary) {

    int decimal = 0;
    int base = 1;   // 2^0

    while (binary > 0) {
        int lastBit = binary % 10;
        decimal += lastBit * base;
        base *= 2;
        binary /= 10;
    }

    return decimal;
}

int main() {
    long long binary;
    cin >> binary;

    cout << binaryToDecimal(binary) << endl;

    return 0;
}