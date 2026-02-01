#include <iostream>
using namespace std;

// TC: O(1)
// SC: O(1)
bool isLeapYear(int year) {

    // Leap year rules:
    // 1. Divisible by 400 → Leap year
    // 2. Divisible by 100 → Not a leap year
    // 3. Divisible by 4   → Leap year
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;

    return false;
}

int main() {
    int year;
    cin >> year;

    if (isLeapYear(year))
        cout << "Leap Year" << endl;
    else
        cout << "Not Leap Year" << endl;

    return 0;
}