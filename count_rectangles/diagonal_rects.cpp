/* inputs are pairs of x and y coordinates
first input is number of pairs.
find count of diagonal rectangles
# # #
# # # #
# # #  -> 2 diagonal rectangle
input for this points:
10
0 1
0 0
0 2
1 0
1 1
1 2
2 0
2 1
2 2
3 1
*/
#include <iostream>
#include <utility> //pair
#include <map>

using namespace std;

int main() {
    //read input
    int n;
    cin >> n;
    pair<int, int> points[n];
    pair<int, int> temp_pair; //x, y
    for (int i=0; i<n; i++) {
        cin >> temp_pair.first >> temp_pair.second;
        points[i] = temp_pair;
    }

    map<pair<int, int>, int> counts; //counts of diagonal left inclined lines    
    //keys of map: pair<x1 + y1, length of line>
    for (auto p1: points) {
        for (auto p2: points) {
            // if p1 in left of p2 and tangent is 1
            if (p1.first < p2.first && p2.second - p1.second == p2.first - p1.first) {
                temp_pair = {p1.first + p1.second, p2.first - p1.first};
                counts[temp_pair]++;
            }
        }
    }

    //count rectangles
    int result = 0;
    for (auto const& key_val: counts) {
        result += (key_val.second * (key_val.second - 1)) / 2;
    }

    cout << result << endl;

    return 0;
}