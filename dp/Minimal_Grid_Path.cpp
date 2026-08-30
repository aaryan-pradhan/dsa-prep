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
/*You are given an n \times n grid whose each square contains a letter.
You should move from the upper-left square to the lower-right square. You can only move right or down.
What is the lexicographically minimal string you can construct?
Input
The first line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n letters between A and Z.
Output
Print the lexicographically minimal string.
Constraints

1 \le n \le 3000

Example
Input:
4
AACA
BABC
ABDA
AACA

Output: You are given an n \times n grid whose each square contains a letter.
You should move from the upper-left square to the lower-right square. You can only move right or down.
What is the lexicographically minimal string you can construct?
Input
The first line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n letters between A and Z.
Output
Print the lexicographically minimal string.
Constraints

1 \le n \le 3000

Example
Input:
4
AACA
BABC
ABDA
AACA

Output: You are given an n \times n grid whose each square contains a letter.
You should move from the upper-left square to the lower-right square. You can only move right or down.
What is the lexicographically minimal string you can construct?
Input
The first line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n letters between A and Z.
Output
Print the lexicographically minimal string.
Constraints

1 \le n \le 3000

Example
Input:
4
AACA
BABC
ABDA
AACA

Output:You are given an n \times n grid whose each square contains a letter.
You should move from the upper-left square to the lower-right square. You can only move right or down.
What is the lexicographically minimal string you can construct?
Input
The first line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n letters between A and Z.
Output
Print the lexicographically minimal string.
Constraints

1 \le n \le 3000

Example
Input:
4
AACA
BABC
ABDA
AACA

Output:You are given an n \times n grid whose each square contains a letter.
You should move from the upper-left square to the lower-right square. You can only move right or down.
What is the lexicographically minimal string you can construct?
Input
The first line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n letters between A and Z.
Output
Print the lexicographically minimal string.
Constraints

1 \le n \le 3000

Example
Input:
4
AACA
BABC
ABDA
AACA

Output:Output: AAABACA
*/

// stirng rec(ll i , ll j )
// {
//     // this returns the lexicographically minimal string that can be constructed from the first i rows and j columns of the grid 
//     // we are constructing the string from the top left corner to the ( i , j ) cell of the grid
//     if ( i == 0 && j == 0 ) return grid[0][0] ;
//     string ans = "" ;
//     if ( i > 0 ) ans = rec(i - 1 , j) + grid[i][j] ;
//     if ( j > 0 ) ans = min(ans , rec(i , j - 1) + grid[i][j]) ;
//     return ans ;

string lexi(string a , string b)
{
    if ( a == "" ) return b ;
    if ( b == "" ) return a ;
    if ( a < b ) return a ;
    return b ;
}


void solve() 
{
    ll n ; 
    cin >> n ;
    vector<string> grid(n) ;
    for ( ll i = 0 ; i < n ; i++) cin >> grid[i] ;
    vector < vector<string>> dp(n , vector<string>(n , "")) ;
    for ( ll i = 0 ; i < n ; i++)
    {
        for ( ll j = 0 ; j < n ; j++)
        {
            if ( i == 0 && j == 0 ) 
            {
                dp[i][j] = grid[0][0] ; 
                continue ; 
            }
            string ans = "" ;
            if ( i > 0 && j > 0 ) 
            {
                ans = lexi (dp[i - 1][j] , dp[i][j - 1]) + grid[i][j] ;
            }
            else if ( i > 0 )
            {
                ans = lexi (ans , dp[i - 1][j] + grid[i][j]) ;
            }
            else
            {
                ans = lexi (ans , dp[i][j - 1] + grid[i][j]) ;
            }
            dp[i][j] = ans ;
        }
    }
    cout << dp[n - 1][n - 1] << endl ;







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  