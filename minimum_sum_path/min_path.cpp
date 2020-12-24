/*  given a grid find min sum from top-left to bottom-right.
    you can move right or down.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int grid[m][n];
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    //first row prefix sum
    for (int j=1; j<n; j++) {
        grid[0][j] += grid[0][j-1];
    }
    //first col prefix sum
    for (int i=1; i<m; i++) {
        grid[i][0] += grid[i-1][0];
    }
    //choosing min sum path in inner matrix
    for (int i=1; i<m; i++) {
        for (int j=1; j<n; j++) {
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }

    cout << grid[m-1][n-1] << endl;

    return 0;
}