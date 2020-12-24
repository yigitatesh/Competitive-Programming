/*  Max subarray:
    maximum contiguous sum in an array.
*/
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //kadane's algorithm
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
        //max_sum = max(max_sum, sum);
        if (sum > max_sum) {
            max_sum = sum;
        }
        //sum = max(sum, 0);
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << max_sum << endl;

    return 0;
}