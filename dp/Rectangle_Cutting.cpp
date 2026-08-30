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

/*Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
Input
The only input line has two integers a and b.
Output
Print one integer: the minimum number of moves.
Constraints

1 \le a,b \le 500

Example
Input:
3 5

Output:
3*/


// ll rec(ll a , ll b )
// {
//     // this returns the number of moves to cut an a x b rectangle into squares
//     if ( a == b ) return 0 ;
//     if( a < b ) swap(a , b) ;
//     if ( dp[a][b] != -1 ) return dp[a][b] ;
//     ll ans = INF ;
//     // 
//     for ( ll i = 1 ; i < a ; i++ ) ans = min(ans , 1 + rec(i , b) + rec(a - i , b)) ;
//     return ans ;
//     // this has a time complexity of O(a^2 * b + a * b^2) which is too slow for the given constraints 
// }
void solve() 
{
    ll a , b ; 
    cin >> a >> b ; 
    vector <vector<ll>> dp(a + 1 , vector<ll>(b + 1 , -1)) ; 
    
    for(ll i = 0 ; i <= a ; i++)
    {
        for (ll j = 0 ; j <= b ; j++)
        {
            if ( i == j )
            {
                dp[i][j] = 0 ;
                continue ; 
            }
            ll ans = INF ; 
            for ( ll k = 1 ; k < i ; k++ ) ans = min(ans , 1 + dp[k][j] + dp[i - k][j]) ;
            for ( ll k = 1 ; k < j ; k++ ) ans = min(ans , 1 + dp[i][k] + dp[i][j - k]) ;
            dp[i][j] = ans ;
        }
    }
    cout << dp[a][b] << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  