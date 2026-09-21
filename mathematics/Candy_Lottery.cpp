// orz
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
#define ld long double
using namespace std;
/*Time limit: 1.00 s
Memory limit: 512 MB

There are n children, and each of them independently gets a random integer number of candies between 1 and k.
What is the expected maximum number of candies a child gets?
Input
The only input line contains two integers n and k.
Output
Print the expected number rounded to six decimal places (rounding half to even).
Constraints

1 \le n \le 100
1 \le k \le 100

Example
Input:
2 3

Output:
2.444444*/
// ld rec(ll i , ll m)
// {
//     // we are on the ith child and the maximum number of candies we have seen so far is m, then rec retuns the expected maximum number of candies we will see after all n children have gotten their candies
//     if(i == n) return m;
//     if(dp[i][m] != -1) return dp[i][m];
//     ld ans = 0 ;
//     for(ll j = 1 ; j <= k ; j++)
//     {
//         ans += rec(i+1 , max(m , j));
//     }
//     return dp[i][m] = ans/k;
    
    
    
// }
void solve() 
{
    ll n , k ;
    cin >> n >> k ;
    ld dp[2][k+1];
    memset(dp , -1 , sizeof(dp));
    for(ll i = n ; i >= 0 ; i--)
    {
        for(ll m = k ; m >= 0 ; m--)
        {
            if(i == n)
            {
                dp[i&1][m] = m ;
                continue ; 
            }
            ld ans = 0 ;
            for(ll j = 1 ; j <= k ; j++)
            {
                ans += dp[(i+1)&1][max(m , j)];
            }
            dp[i&1][m] = ans/k;
        }
    }
    ld v = dp[0][0] * 1e6L;
    ll r = (ll)floorl(v);
    ld frac = v - r;
    if(fabsl(frac - 0.5L) < 1e-9L) { if(r % 2) r++; }
    else if(frac > 0.5L) r++;
    cout << r / 1000000 << "." << setw(6) << setfill('0') << r % 1000000 << endl;

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  