// Problem: Frog Minimum Jumps (multi-query)
// Pattern: monotonic-reach BFS collapsed into a single sweep — "Jump Game II"
//          boundary/farthest technique
// Time: O(N + Q)  Space: O(N)
//
// N stones, 1-indexed. Frog starts at stone 1. Stone i has a Jump Power
// p[i] — from stone i the frog can jump forward to any stone in
// [i+1, i+p[i]]. Given Q queries, each a target stone, output the minimum
// number of jumps from stone 1 to reach it (0 if the target is stone 1).
//
// Example:
//     N=5, power=[1,2,4,5,3]
//         query 3 -> 2   (1 -> 2 -> 3)
//         query 1 -> 0
//         query 5 -> 3   (1 -> 2 -> 4 -> 5)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> power(n + 1);
    for (int i = 1; i <= n; i++) cin >> power[i];

    // dp[i] = min jumps from stone 1 to stone i
    vector<int> dp(n + 1, 0);
    int jumps = 0, curEnd = 1, farthest = 1;

    for (int i = 1; i <= n; i++) {
        if (i > curEnd) {
            jumps++;
            curEnd = farthest;
        }
        dp[i] = jumps;
        farthest = max(farthest, i + power[i]);
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }

    return 0;
}

// Recall Trail
// - Q queries against arbitrary targets means precompute dp[i] = min jumps
//   to reach every stone once, up front, then answer each query O(1). Don't
//   re-search per query.
// - dp[i] is not dp[i-1..i-power[i]] — that uses stone i's own power
//   to look backward, but what actually lets you reach i is some earlier
//   stone j's power (j + power[j] >= i). The lookback set isn't fixed by
//   i's own power.
// - Naive backward scan (check all j<i for each i) or naive forward BFS
//   (loop i+1..i+power[i] and enqueue per node) are both O(N^2) worst case
//   — e.g. every stone has power[i]=N, so each node's neighbor-scan alone
//   is O(N).
// - Since jumps only move forward and ranges only extend, BFS collapses into
//   a single left-to-right sweep — no queue, no visited array. Visitation
//   order is index order, so there's nothing to requeue.
// - Two tracked values, framed as two moving "waves":
//   - curEnd — edge of everything reachable in the *current* jump count.
//   - farthest — edge being built for the *next* jump count, as a
//     byproduct of scanning stones in the current wave.
//   When the scan index i steps past curEnd, that's proof one more jump
//   was needed to arrive here: commit jumps++, curEnd = farthest. Then
//   record dp[i] = jumps, and let stone i contribute to farthest via
//   i + power[i] (it can only extend the *next* boundary, not the current
//   one).
// - Init curEnd = farthest = 1, jumps = 0, loop i = 1..n inclusive — no
//   special-casing stone 1: 1 > curEnd(1) is false, so dp[1] naturally
//   comes out 0.
// - Generalizes: any time reachability only grows in one direction and each
//   step costs uniformly, BFS-by-queue can be replaced by this
//   boundary-sweep.
