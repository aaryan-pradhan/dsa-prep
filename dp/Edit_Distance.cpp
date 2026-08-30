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
/*Time limit: 1.00 s
Memory limit: 512 MB

The edit distance between two strings is the minimum number of operations required to transform one string into the other.
The allowed operations are:

Add one character to the string.
Remove one character from the string.
Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
Your task is to calculate the edit distance between two strings.
Input
The first input line has a string that contains n characters between A–Z.
The second input line has a string that contains m characters between A–Z.
Output
Print one integer: the edit distance between the strings.
Constraints

1 \le n,m \le 5000

Example
Input:
LOVE
MOVIE

Output:
2*/
// ll rec(ll i , ll j )
// {
//     // this returns the edit distance to make the first i characters of s equal to the first j characters of t
//     if ( i == 0 ) return j ;
//     if ( j == 0 ) return i ;
//     if ( dp[i][j] != -1 ) return dp[i][j] ;
//     ll ans = 0 ; 
//     if ( s[i - 1] == t[j - 1] ) {
//         ans = rec(i - 1 , j - 1 ) ; 
//     }
//     else
//     {
//         ll add = rec(i , j - 1 ) ; 
//         ll remove = rec(i - 1 , j ) ; 
//         ll replace = rec(i - 1 , j - 1 ) ; 
//         ans = min({add , remove , replace}) + 1 ; 
//     }
//     return dp[i][j] = ans ;
// }
void solve() 
{

    string s , t ;
    cin >> s >> t ;
    ll n = s.size() ;
    ll m = t.size() ;
    ll dp[2][m + 1] ;
    for ( ll i = 0 ; i <= n ; i++)
    {
        for ( ll j = 0 ; j <= m ; j++)
        {
            if ( i == 0 ){
                dp[(i&1)][j] = j ;
                continue ;
            } 
            if ( j == 0 )
            {
                dp[(i&1)][j] = i ;
                continue ;
            }
            if ( s[i - 1] == t[j - 1] ) 
            {
                dp[(i & 1)][j] = dp[(i - 1) & 1][(j-1)] ;
            }
            else
            {
                ll add = dp[(i & 1)][j-1] + 1 ; 
                ll remove = dp[(i - 1) & 1][j] + 1 ; 
                ll replace = dp[(i - 1) & 1][(j-1)] + 1 ; 
                dp[(i & 1)][j] = min({add , remove , replace}) ; 
            }
        }
    }
    cout << dp[(n & 1)][m] << endl ;
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  