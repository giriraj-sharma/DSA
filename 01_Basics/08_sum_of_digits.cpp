#include <iostream>
using namespace std;

// TC: O(d) where d = number of digits
// SC: O(1)
int sumOfDigits(int n) {

    int sum = 0;

    while (n > 0) {
        sum += n % 10;  // add last digit
        n /= 10;       // remove last digit
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << sumOfDigits(n) << endl;

    return 0;
}