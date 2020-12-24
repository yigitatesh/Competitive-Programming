/*  given an array and target value,
    count ways to write target as the sum of those numbers
    ex. 1, 2, 3 target = 4
    4 = 1 + 2 + 1, 2 + 1 + 1, 3 + 1 etc.
    sum of sums arr -> [1, 1, 2, 4, 7] -> answer is 7
*/

#include <iostream>

using namespace std;

int main() {
    int t, n; //t:target, n:size of array
    cin >> t >> n;
    int nums[n];
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }

    //sum of previous sums
    int t_arr[t+1];
    t_arr[0] = 1;
    for (int i=1; i<=t; i++) {
        t_arr[i] = 0;
        for (int num: nums) {
            if (i >= num) {
                t_arr[i] += t_arr[i-num];
            }
        }
    }

    cout << t_arr[t] << endl;

    return 0;
}