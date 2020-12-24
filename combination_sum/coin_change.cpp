/*  given coins and target.
    min possible number of coins used.
    ex. 1, 2, 5 and target = 11
    5 + 5 + 1 = 11, min number = 3
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    int coins[n];
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }

    //sum with min numbers of coins used
    //sum array
    int dp[t+1]; //min numbers
    dp[0] = 0;
    int temp;
    for (int i=1; i<=t; i++) {
        //find min number of coins in current state
        temp = t; //biggest possible number (it can be inf too)
        for (int x: coins) {
            if (i >= x) {
                temp = min(temp, dp[i-x] + 1);
            }
        }
        dp[i] = temp;
    }

    cout << dp[t] << endl;

    return 0;
}