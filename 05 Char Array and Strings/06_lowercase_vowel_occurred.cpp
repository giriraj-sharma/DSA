// Count Lowercase Vowels in a String

#include <iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
int main() {
    string s;
    getline(cin, s);

    int count = 0;

    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}