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

using namespace std;
/*There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.
What is the maximum possible score for the first player when both players play optimally?
Input
The first input line contains an integer n: the size of the list.
The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
Output
Print the maximum possible score for the first player.
Constraints

1 \le n \le 5000
-10^9 \le x_i \le 10^9

Example
Input:
4
4 5 1 3

Output:
8*/
// ll rec(ll l , ll r , ll turn)
// {
//     // this returns the maximum possible score for the first player when both players play optimally and the current list is from l to r and turn is 0 if it is the first player's turn and 1 if it is the second player's turn
//     if ( l > r ) return 0 ;
//     if ( dp[l][r] != -1 ) return dp[l][r] ;
//     ll ans = 0 ; 
//     if ( turn == 0 ) 
//     {
//         ans = max(rec(l + 1 , r , 1) + x[l] , rec(l , r - 1 , 1) + x[r]) ;
//     }
//     else
//     {
//         ans = min(rec(l + 1 , r , 0) , rec(l , r - 1 , 0)) ;
//     }
//     return dp[l][r] = ans ;
// }

void solve() 
{
    ll n ; 
    cin >> n ;
    vector < ll > x(n) ;
    for ( ll i = 0 ; i < n ; i++) cin >> x[i] ;
    vector < vector<ll>> dp(n , vector<ll>(n , 0)) ;
    for ( ll l = n - 1 ; l >= 0 ; l--)
    {
        for ( ll r = 0 ; r < n  ; r++)
        {
            if ( l > r )
            {
                dp[l][r] = 0 ;
                continue ;
            }
            if ( l == r )
            {
                ll turn =  (n - (r - l +1)) % 2 ;
                if ( turn == 0 ) dp[l][r] = x[l] ;
                else dp[l][r] = 0 ;
                continue ;
            }
            ll turn =  (n - (r - l +1)) % 2 ; 

            if ( turn == 0 ) 
            {
                ll ans = -INF ; 
                if ( r - 1 >= 0)
                {
                    ans = max(ans , dp[l][r - 1] + x[r]) ;
                }
                if ( l + 1 < n )
                {
                    ans = max(ans , dp[l + 1][r] + x[l]) ;
                }
                dp[l][r] = ans  ; 
            }
            else
            {
                ll ans = INF ;
                if ( r - 1 >= 0)
                {
                    ans = min(ans , dp[l][r - 1]) ;
                }
                if ( l + 1 < n )
                {
                    ans = min(ans , dp[l + 1][r]) ;
                }
                dp[l][r] = ans  ;
            }   
        }
    }
    cout << dp[0][n - 1] << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  