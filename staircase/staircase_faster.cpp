/*  There is n steps.
    You can either climb 1 or 2 steps.
    How many distinct ways are there to climb to the top ?
    hint: like fibonacci series
*/
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n+1];
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (n > 0) {
        dp[0] = 1;
        dp[1] = 1;
    }

    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n] << endl;

    return 0;
}