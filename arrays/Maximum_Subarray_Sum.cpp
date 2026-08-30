// Problem: Maximum Subarray Sum
// Link: CSES 1643
// Pattern: Kadane's — running best-ending-here, extend or restart at each element
// Time: O(n)  Space: O(1)
//
// Max sum of a contiguous nonempty subarray.
//
// Example:
//     -1 3 -2 5 3 -5 2 2 -> 9   (subarray [3, -2, 5, 3])

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    long long cur = x[0], best = x[0];
    for (int i = 1; i < n; i++) {
        cur = max(x[i], cur + x[i]);
        best = max(best, cur);
    }

    cout << best << '\n';
    return 0;
}

// Recall Trail
// - At each element decide: extend the running sum, or abandon it and start
//   fresh here — cur = max(x[i], cur + x[i]).
// - Track best separately from cur (best = max(best, cur)) since the
//   optimal subarray doesn't have to end at the last index scanned.
// - Init both cur and best to x[0], not 0 — subarray must be
//   nonempty, so an all-negative array must still return its least-negative
//   single element, not 0.
