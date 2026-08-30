// Problem: Dice Combinations
// Link: https://cses.fi/problemset/task/1633
// Pattern: 1D bottom-up DP, sum over fixed-size window of prior states
// Time: O(n)  Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll madd(ll a, ll b) { ll s = a + b; return s >= MOD ? s - MOD : s; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= 6; k++) {
            if (i - k >= 0) dp[i] = madd(dp[i], dp[i - k]);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
