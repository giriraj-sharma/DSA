#include <iostream>
using namespace std;

// TC: O(1)
// SC: O(1)
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b && a >= c)
        cout << a << endl;
    else if (b >= a && b >= c)
        cout << b << endl;
    else
        cout << c << endl;

    return 0;
}