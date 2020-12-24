#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int index = 0;
    for (int x: arr) {
        if (x != 0) {
            arr[index] = x;
            index++;
        }
    }
    for (int i=index; i<n; i++) {
        arr[i] = 0;
    } 

    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}