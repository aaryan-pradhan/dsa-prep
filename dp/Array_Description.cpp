// Problem: Array Description
// Link: https://cses.fi/problemset/task/1746
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
/*You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
Input
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array. Value 0 denotes an unknown value.
Output
Print one integer: the number of arrays modulo 10^9+7.
Constraints

1 \le n \le 10^5
1 \le m \le 100
0 \le x_i \le m

Example
Input:
3 5
2 0 2

Output:
3

Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.*/

ll madd(ll a , ll b)
{
    return (a + b) % MOD ;
}
ll mmul(ll a , ll b)
{
    return (a * b) % MOD ;
}
ll msub(ll a , ll b)
{
    return (a - b + MOD) % MOD ;
}
ll mpow(ll a , ll b)
{
    ll res = 1 ;
    while (b > 0)
    {
        if (b & 1) res = mmul(res , a) ;
        a = mmul(a , a) ;
        b >>= 1 ;
    }
    return res ;
}
ll minv(ll a)
{
    return mpow(a , MOD - 2) ;
}
ll mdiv(ll a , ll b)
{
    return mmul(a , minv(b)) ;
}
ll mcorr(ll a)
{
    return (a % MOD + MOD) % MOD ;
}

void solve()
{
    ll n , m ;
    cin >> n >> m ;
    ll arr[n] ;
    for(ll i = 0 ; i < n ; i++) cin >> arr[i] ;
    ll dp[2][m + 1] ;
    for( ll i = n ; i >= 0 ; i--)
    {
        for(ll prev = 1 ; prev <= m ; prev++)
        {
            if ( i == n )
            {
                dp[(i & 1)][prev] = 1 ;
                continue ;
            }
            ll ans = 0 ;
            if ( arr[i] != 0 )
            {
                if ( abs(arr[i] - prev) <= 1 ) ans = dp[(i + 1) & 1][arr[i]] ;
                else ans = 0 ;
            }
            else
            {
                for(ll j = prev - 1 ; j <= prev + 1 ; j++)
                {
                    if ( j >= 1 && j <= m ) ans = madd(ans , dp[(i + 1) & 1][j]) ;
                }
            }
            dp[(i & 1)][prev] = ans ;
        }
    }
    if ( arr[0] != 0 )
    {
        cout << dp[0][arr[0]] << endl ;
    }
    else
    {
        ll ans = 0 ;
        for(ll j = 1 ; j <= m ; j++)
        {
            ans = madd(ans , dp[1][j]) ;
        }
        cout << ans << endl ;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve() ;
}

// Recall Trail
// Pattern: 1D bottom-up DP, counting valid fillings under an adjacency
// constraint (|adjacent values| <= 1)
// Approach: dp[i][prev] = number of ways to fill positions i..n-1 given
// position i-1 was `prev`, processed right-to-left (rolling 2-row array
// on i parity). Fixed positions constrain to one prev value; unknown
// positions (arr[i] == 0) sum over prev-1, prev, prev+1. Final answer
// sums/looks up dp[0][*] depending on whether position 0 is fixed.
