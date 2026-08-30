// Problem: Minimizing Coins
// Link: https://cses.fi/problemset/task/1634
// Pattern: 1D bottom-up DP, unbounded reuse (min over all coin values per sum)
// Time: O(n*x)  Space: O(x)

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for (int left = 1; left <= x; left++) {
        for (int c : coins) {
            if (c <= left && dp[left - c] != INF) {
                dp[left] = min(dp[left], dp[left - c] + 1);
            }
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
    return 0;
}
