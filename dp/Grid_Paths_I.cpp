// Problem: Grid Paths I
// Link: https://cses.fi/problemset/task/1638
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
/*Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
Input
The first input line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
Output
Print the number of paths modulo 10^9+7.
Constraints

1 \le n \le 1000

Example
Input:
4
....
.*..
...*
*...

Output:
3*/
ll madd(ll a , ll b)
{
    return (a + b) % MOD ;
}
void solve()
{
    ll n ;
    cin >> n ;
    vector<string> res(n) ;
    for(ll i = 0 ; i < n ; i++)
    {
        string x ;
        cin >> x ;
        res[i] = x ;
    }
    vector<vector<ll>> dp(n , vector<ll>(n ,  0)) ;
    for(ll i = n-1 ; i >= 0 ; i--)
    {
        for(ll j = n-1 ; j >= 0 ; j--)
        {
            if ( res[i][j] == '*' ) dp[i][j] = 0 ;
            else if ( i == n-1 && j == n-1 ) dp[i][j] = 1 ;
            else
            {
                ll down = 0 , right = 0 ;
                if ( i+1 < n ) down = dp[i+1][j] ;
                if ( j+1 < n ) right = dp[i][j + 1] ;
                dp[i][j] = madd(down , right) ;
            }
        }
    }
    cout << dp[0][0] << endl ;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve() ;
}

// Recall Trail
// Pattern: 2D bottom-up DP, grid path counting with obstacles
// Approach: dp[i][j] = number of paths from (i,j) to the bottom-right
// corner. Filled right-to-left, bottom-to-top: dp[i][j] = 0 if trapped,
// 1 at the destination cell, else dp[i+1][j] + dp[i][j+1] (mod 1e9+7).
