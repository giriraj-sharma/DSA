#include <iostream>
using namespace std;

// TC: O(d) where d = number of digits
// SC: O(1)
bool isArmstrong(int n) {

    int original = n;
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit * digit; // for 3-digit Armstrong numbers
        n /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cin >> n;

    if (isArmstrong(n))
        cout << "Armstrong" << endl;
    else
        cout << "Not Armstrong" << endl;

    return 0;
}