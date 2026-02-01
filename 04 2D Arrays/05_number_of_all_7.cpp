#include <iostream>
using namespace std;

// TC: O(n * m)
// SC: O(1)
int main() {
    int n = 2, m = 3;

    int arr[2][3] = {
        {4, 7, 8},
        {8, 8, 7}
    };

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 7)
                count++;
        }
    }

    cout << count << endl;

    return 0;
}