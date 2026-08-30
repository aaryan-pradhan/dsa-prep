// Problem: Distinct Values
// Pattern: sort, count runs of equal adjacent values
// Time: O(n log n)  Space: O(n)
//
// unordered_set with the default hash is vulnerable to CSES's anti-hash
// test (collisions force O(n) per op) -> TLE. Sort is immune to that.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    int distinct = n > 0 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (x[i] != x[i - 1]) distinct++;
    }

    cout << distinct << '\n';
    return 0;
}
