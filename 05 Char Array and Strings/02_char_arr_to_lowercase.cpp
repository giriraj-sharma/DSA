#include <iostream>
using namespace std;

// TC: O(n)
// SC: O(1)
int main() {
    char str[100];
    cin.getline(str, 100);

    for (int i = 0; str[i] != '\0'; i++) {

        // Check if uppercase letter
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }

    cout << str << endl;

    return 0;
}