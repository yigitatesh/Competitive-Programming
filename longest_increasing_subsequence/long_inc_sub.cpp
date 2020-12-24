/*  given an array.
    find the length of the longest increasing subsequence
    do not have to be contiguous.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //longest increasing subsequence array
    int lis[n];
    for (int i=0; i<n; i++) {
        lis[i] = 1; //length 1
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    
    cout << lis[n-1] << endl;

    return 0;
}