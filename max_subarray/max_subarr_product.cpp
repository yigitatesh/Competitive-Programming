/*  Max subarray:
    maximum contiguous product in an array.
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

    //modified kadane's algorithm
    //modified because of negative integers
    //forward loop
    int max_product = INT_MIN;
    int product = 1;
    for (int i=0; i<n; i++) {
        product *= arr[i];
        if (product > max_product) {
            max_product = product;
        }
        if (product == 0) {
            product = 1;
        }
    }

    //backward loop
    product = 1;
    for (int i=n-1; i>=0; i--) {
        product *= arr[i];
        if (product > max_product) {
            max_product = product;
        }
        if (product == 0) {
            product = 1;
        }
    }

    cout << max_product << endl;

    return 0;
}