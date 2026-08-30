// orz
#include <bits/stdc++.h>
#include "algodebug.h"
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
/*Your task is to build a tower whose width is 2 and height is n. You have an unlimited supply of blocks whose width and height are integers.
For example, here are some possible solutions for n=6:

Given n, how many different towers can you build? Mirrored and rotated towers are counted separately if they look different.
Input
The first input line contains an integer t: the number of tests.
After this, there are t lines, and each line contains an integer n: the height of the tower.
Output
For each test, print the number of towers modulo 10^9+7.
Constraints

1 \le t \le 100
1 \le n \le 10^6

Example
Input:
3
2
6
1337

Output:
8
2864
640403945




*/
/* Dynamic Programming approach 
ll rec(ll i, ll flag)
{
    if (i == n) return 1;
    if (dp[i][flag] != -1) return dp[i][flag];
    ll ans = 0;

    for (ll h = 1; i + h <= n; h++)
        ans = madd(ans, rec(i + h, 0));                         // F-move: any height h

    if (flag == 0)
        for (ll s = 1; i + s <= n; s++)
            ans = madd(ans, mmul(mpow(4, s-1), rec(i + s, 1)));  // S-move: any height s, weighted

    return dp[i][flag] = ans;
}
// answer: rec(0, 0)

for (ll i = n; i >= 0; i--)
    for (ll flag = 0; flag < 2; flag++)
    {
        if (i == n) { dp[i][flag] = 1; continue; }
        ll ans = 0;
        for (ll h = 1; i + h <= n; h++) ans = madd(ans, dp[i+h][0]);
        if (flag == 0)
            for (ll s = 1; i + s <= n; s++) ans = madd(ans, mmul(mpow(4, s-1), dp[i+s][1]));
        dp[i][flag] = ans;
    }
now state i , 0 depends on i + 2 .. n 
// so prefix sum can be used to optimize the inner loop for F-move and S-move

*/
void solve() 
{
    ll n ; 
    cin >> n ; 
    ll dp[n + 1][2] ; 
    for ( ll i = n ; i >= 0 ; i--)
    {
        for ( ll flag = 0 ; flag < 2 ; flag++)
        {
            if ( i == n ) 
            {
                dp[i][flag] = 1 ; 
                continue ; 
            }
            ll ans = 0 ; 
            if ( flag == 0 )
            {
                ans = madd(ans , dp[i + 1][0]) ; 
                ans = madd(ans , dp[i + 1][1]) ; 
            }
            else
            {
                ans = madd(ans , dp[i + 1][0]) ; 
            }
            dp[i][flag] = ans ; 
        }
    }

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;


    while(t--)
    {
        solve() ;
    }
}
    
  