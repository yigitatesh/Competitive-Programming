/* inputs are pairs of x and y coordinates
first input is number of pairs.
find count of straight rectangles
# # #
# # #  -> 3 rectangles
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
    map<pair<int, int>, int> counts; //counts of vertical lines
    //keys of map: pair<y1, y2>
    for (int i=0; i<n; i++) {
        cin >> temp_pair.first >> temp_pair.second;
        points[i] = temp_pair;
    }

    //count vertical lines at same level
    for (auto p: points) {
        for (auto p_2: points) {
            if (p.first == p_2.first && p.second > p_2.second) {
                temp_pair = {p.second, p_2.second};
                counts[temp_pair]++;
            }
        }
    }

    //count rectangles
    int result = 0;
    for (auto const& key_val: counts) {
        result += (key_val.second * (key_val.second - 1)) / 2;
    }

    cout << result;

    return 0;
}