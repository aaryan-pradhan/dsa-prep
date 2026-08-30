// Problem: Removing Digits
// Link: https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define fr first
#define sc second
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define mp make_pair
#define PI acos(-1)
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pll pair<ll,ll>

using namespace std;
/*You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 \le n \le 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.*/

void solve()
{
    ll n ;
    cin >> n ;
    vector<ll> dp(n + 1, INF) ;
    for(ll i = 0 ; i <= n ; i++)
    {
        if ( i == 0 ) dp[i] = 0 ;
        else
        {
            ll temp = i ;
            while (temp > 0)
            {
                ll digit = temp % 10 ;
                if (digit != 0)
                {
                    dp[i] = min(dp[i], dp[i - digit] + 1) ;
                }
                temp /= 10 ;
            }
        }
    }
    cout << dp[n] << endl ;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve() ;
}

// Recall Trail
// Pattern: 1D bottom-up DP, min-steps via digit subtraction
// Approach: dp[i] = min steps to reduce i to 0. For each i, try subtracting
// each nonzero digit of i and take dp[i - digit] + 1, minimized over all
// digits present in i. dp[0] = 0 is the base case.
