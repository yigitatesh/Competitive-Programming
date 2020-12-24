/*  given n strings  
    group anagrams and print them in same rows.
    ex. abc cba bca adb
    output:
    abc cba bca
    adb
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string strings[n];
    for (int i=0; i<n; i++) {
        cin >> strings[i];
    }

    string temp;
    map<string, vector<string>> m;
    for (string s: strings) {
        temp = s;
        sort(temp.begin(), temp.end());
        m[temp].push_back(s);
    }

    for (auto const& v: m) {
        for (string s: v.second) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}