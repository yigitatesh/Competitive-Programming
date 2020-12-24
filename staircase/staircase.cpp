/*  There is n steps.
    You can either climb 1 or 2 steps.
    How many distinct ways are there to climb to the top ?
*/
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long fact_arr[n+1];
    fact_arr[0] = 1;
    for (int i=1; i<=n; i++) {
        fact_arr[i] = fact_arr[i-1] * i;
    }

    long long result = 0;
    int one_step = n, two_step = 0;
    while (one_step>=0) {
        result += fact_arr[one_step + two_step] / (fact_arr[one_step] * fact_arr[two_step]);
        one_step -= 2;
        two_step++;
    }
    
    cout << result << endl;

    return 0;
}