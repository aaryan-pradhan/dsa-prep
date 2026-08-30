// Problem: Coin Combinations I
// Link: https://cses.fi/problemset/task/1635
// Pattern: 1D bottom-up DP, order-matters counting over unbounded coin set
// Time: O(n*x)  Space: O(x)
//
// Count the distinct ordered ways to produce sum `x` from `n` reusable coin
// values (order matters - 2+2+5, 2+5+2, 5+2+2 count separately). Answer
// modulo 10^9+7.
//
// Constraints: 1 <= n <= 100, 1 <= x <= 10^6, 1 <= c_i <= 10^6

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll madd(ll a, ll b) { ll s = a + b; return s >= MOD ? s - MOD : s; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int sum = 1; sum <= x; sum++) {
        for (int c : coins) {
            if (sum - c >= 0) dp[sum] = madd(dp[sum], dp[sum - c]);
        }
    }

    cout << dp[x] << '\n';
    return 0;
}

// Recall Trail
// Approach: merge of Dice Combinations (order matters -> sum over choices)
// and Minimizing Coins (arbitrary reusable coin set, no index dimension
// needed). dp[sum] = sum over coins c of dp[sum-c].
// Decision points:
// - Base case dp[0] = 1 (not 0) - same gotcha as dice combinations: with
//   dp[0]=0, dp[c] for a lone coin value c would wrongly compute to 0
//   instead of 1.
// - Guard sum - c >= 0 before accumulating.
// - dp[sum] = madd(dp[sum], dp[sum-c]) per coin, accumulated across all
//   coins in the inner loop.
// Contrast with Minimizing Coins: same "loop over all coins per sum"
// shape, but that one takes min(...)+1 (unbounded reuse, order doesn't
// matter, minimizing), this one takes sum via madd (order matters,
// counting all ways). See patterns.md for both variants side by side.
