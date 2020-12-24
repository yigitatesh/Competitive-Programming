/*  given wines with profits.
    you can sell from leftmost or rightmost.
    each year you sell one of them.
    kth year profit of wine is "k * profit".
    find max profit.
*/
#include <iostream>
#include <algorithm>

using namespace std;

//s: start, e: end, y: year
int max_profit(int arr[], int dp[][n], int s, int e, int y) {
    if (dp[s][e] != -1) {
        return dp[s][e];
    }
    if (s == e) {
        return y * arr[s];
    }

    int left = y * arr[s] + max_profit(arr, dp, s+1, e, y+1);
    int right = y * arr[e] + max_profit(arr, dp, s, e-1, y+1);

    dp[s][e] = max(left, right);

    return dp[s][e];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //dynamic programming
    int **dp = new int*[n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dp[i][j] = -1;  //-1 means not calculated yet
        }
    }

    //recursive max profit
    int max_pro = max_profit(arr, dp, 0, n-1, 1);


    return 0;
}