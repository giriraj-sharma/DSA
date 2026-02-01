#include <iostream>
using namespace std;

// TC: O(1)
// SC: O(1)
char nextChar(char ch) {

    // If character is 'z', wrap around to 'a'
    if (ch == 'z')
        return 'a';

    // Otherwise, return next character
    return ch + 1;
}

int main() {
    char ch;
    cin >> ch;

    cout << nextChar(ch) << endl;

    return 0;
}