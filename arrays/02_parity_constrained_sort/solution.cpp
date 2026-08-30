// Problem: Parity-Constrained Sort (Boys/Girls Line)
// Pattern: split by parity, sort each group independently, re-merge on a
//          second pass keyed on the same parity check (no stored indices)
// Time: O(N log N) per test case  Space: O(N)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> evens, odds;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) evens.push_back(a[i]);
            else odds.push_back(a[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());

        int ei = 0, oi = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) a[i] = evens[ei++];
            else a[i] = odds[oi++];
        }

        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}
