// Problem: Frog Minimum Jumps (multi-query)
// Pattern: monotonic-reach BFS collapsed into a single sweep — "Jump Game II"
//          boundary/farthest technique
// Time: O(N + Q)  Space: O(N)

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
