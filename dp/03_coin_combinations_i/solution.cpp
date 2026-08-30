// Problem: Coin Combinations I
// Link: https://cses.fi/problemset/task/1635
// Pattern: 1D bottom-up DP, order-matters counting over unbounded coin set
// Time: O(n*x)  Space: O(x)

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

    vector<vector<ll>> dp(2, vector<ll>(x + 1, 0));
    dp[0] = 1;
    for (int sum = 1; sum <= x; sum++) {
        for (int c : coins) {
            if (sum - c >= 0) dp[sum] = madd(dp[sum], dp[sum - c]);
        }
    }

    cout << dp[x] << '\n';
    return 0;
}
