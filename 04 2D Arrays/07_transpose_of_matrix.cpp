#include <iostream>
using namespace std;

// TC: O(n * m)
// SC: O(1) extra (printing directly)
int main() {
    int n = 3, m = 3;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Transpose: rows become columns
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}