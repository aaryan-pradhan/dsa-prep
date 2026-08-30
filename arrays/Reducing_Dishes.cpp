// Problem: Reducing Dishes
// Pattern: sort ascending, then pop the smallest from the front while the
//          running total of included elements is negative
// Time: O(N log N)  Space: O(N)
//
// n dishes with satisfaction[i] (can be negative). Chef picks any subset
// (possibly empty/all) and any cooking order; each dish takes 1 time unit.
// If a dish is the k-th one cooked (1-indexed), its like-time coefficient is
// k * satisfaction[i]. Maximize the total sum over the chosen subset+order.
// T test cases.
//
// Example:
//     [-2,-2,0,3,2]    -> 17
//         [-2,0,-2,3]      -> 7
//         [-2,3,-2,0,1,2]  -> 26

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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        long long ans = 0, total = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long)(i + 1) * a[i];
            total += a[i];
        }

        int start = 0;
        while (start < n && total < 0) {
            ans -= total;
            total -= a[start];
            start++;
        }

        cout << ans << '\n';
    }
    return 0;
}

// Recall Trail
// - Once a subset is fixed, ascending-satisfaction order is always optimal —
//   larger values get larger multipliers.
// - Full inclusion isn't always optimal (test case [-2,0,-2,3]: including
//   everything gives 6, dropping one -2 gives 7) — need to decide which
//   prefix (smallest elements) to discard after sorting.
// - Core identity: let s = Σ(i+1)*a[i] be the answer for the current
//   (sorted ascending) array and T = Σa[i] its total. Popping the front
//   (smallest) element gives a new answer s' = s - T — the popped value's
//   magnitude cancels out completely; the decision never depends on *what*
//   is popped, only on the sign of T.
// - So: keep popping the smallest while T < 0 (popping strictly increases
//   the answer then); stop the moment T >= 0 (popping would no longer
//   help). No explicit floor-at-0 clamp needed — if T stays negative all
//   the way to an empty array, the identity naturally drives the answer to
//   0 exactly at that point.
// - Implementation avoids recomputing the weighted sum from scratch per pop:
//   compute the full ans and total once, then walk start forward,
//   each step doing ans -= total; total -= a[start]; start++ while
//   total < 0.
