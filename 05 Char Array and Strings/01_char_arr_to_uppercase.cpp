#include <iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
int main() {
    char str[100];
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {

        // Check if lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }

    cout << str << endl;

    return 0;
}