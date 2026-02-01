#include <iostream>
using namespace std;

// TC: O(m)   (m = number of columns)
// SC: O(1)
int main() {

    int nums[3][3] = {
        {1, 4, 9},
        {11, 4, 3},
        {2, 2, 3}
    };

    int m = 3;          // number of columns
    int row = 1;        // second row (0-based index)

    int sum = 0;

    for (int j = 0; j < m; j++) {
        sum += nums[row][j];
    }

    cout << sum << endl;

    return 0;
}