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
/*You throw a dice n times, and every throw produces an outcome between 1 and 6. What is the probability that the sum of outcomes is between a and b?
Input
The only input line contains three integers n, a and b.
Output
Print the probability rounded to six decimal places (rounding half to even).
Constraints

1 \le n \le 100
1 \le a \le b \le 6n

Example
Input:
2 9 10

Output:
0.194444*/
// ll rec(ll i , ll s)
// {
//     // if we are on the ith through and the sum left is s, then what is the probability of getting a sum of s in the next n-i throws
//     if(s < 0) return 0;
//     if(i == n) return s == 0;
//     if(dp[i][s] != -1) return dp[i][s];
//     ll ans = 0 ; 
//     // at this through we can get any number from 1 to 6, so we can try all of them
//     for(ll j = 1 ; j <= 6 ; j++)
//     {
//         ans += rec(i+1 , s-j);
//     }
//     return dp[i][s] = ans/6;
    
// }
void solve() 
{
    ll n ; 
    cin >> n ;
    ll a , b ;
    cin >> a >> b ;
    ld dp[2][6*n+1];
    for(ll i = n ; i >= 0 ; i--)
    {
        for(ll s = 0 ; s <= 6*n ; s++)
        {
            if( i == n)
            {
                dp[i&1][s] = (s == 0);
                continue ; 
            }
            ld ans = 0 ; 
            for(ll j = 1 ; j <= 6 ; j++)
            {
                if(s-j >= 0)
                {
                    ans += dp[(i+1)&1][s-j];
                }
            }
            dp[i&1][s] = ans/6.0;

        }
    }
    ld ans = 0 ;
    for(ll s = a ; s <= b ; s++)
    {
        ans += dp[0][s];
    }
    cout << fixed << setprecision(6) << ans << endl;



    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  