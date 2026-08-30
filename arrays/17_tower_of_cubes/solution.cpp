// Problem: Tower of Cubes
// Pattern: patience-sorting-style greedy — multiset of tower tops, place
// each cube on the tightest-fitting tower (smallest top strictly > cube)
// Time: O(n log n)  Space: O(n)

#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    multiset<int> tops;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        auto it = tops.upper_bound(c);
        // this takes O ( log n ) time
        if (it != tops.end()) {
            tops.erase(it);
            // this takes O ( log n ) time
        }
        tops.insert(c);
        // this takes O ( log n ) time
    }

    cout << tops.size() << '\n';
    return 0;
}
