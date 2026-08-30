// Problem: Ferris Wheel
// Link: CSES 1090
// Pattern: sort, two-pointer from both ends — pair lightest with heaviest
// when they fit together, else heaviest rides alone
// Time: O(n log n)  Space: O(1) extra
//
// n children, gondola holds 1 or 2, total weight per gondola <= x. Minimum
// gondolas needed.
//
// Example:
//     7 2 3 9, x=10 -> 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    long long x;
    cin >> n >> x;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());

    int i = 0, j = n - 1, count = 0;
    while (i <= j) {
        if (p[i] + p[j] <= x) i++;
        j--;
        count++;
    }

    cout << count << '\n';
    return 0;
}

// Recall Trail
// - Sort, i at lightest unmatched, j at heaviest unmatched.
// - If p[i] + p[j] <= x: pair them, both consumed (i++). Either way j
//   always decrements (the current heaviest is always resolved this step —
//   either paired or sent alone) and count++ always fires once per step.
// - i == j (one child left) still works correctly: the self-pair check
//   trivially succeeds or the child just goes alone either way, exactly one
//   gondola charged, loop then ends (i > j).
