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
/*Given two arrays of integers, find their longest common subsequence.
A subsequence is a sequence of array elements from left to right that can contain gaps. A common subsequence is a subsequence that appears in both arrays.
Input
The first line has two integers n and m: the sizes of the arrays.
The second line has n integers a_1,a_2,\dots,a_n: the contents of the first array.
The third line has m integers b_1,b_2,\dots,b_m: the contents of the second array.
Output
First print the length of the longest common subsequence.
After that, print an example of such a sequence. If there are several solutions, you can print any of them.
Constraints

1 \le n,m \le 1000
1 \le a_i, b_i \le 10^9

Example
Input:
8 6
3 1 3 2 7 4 8 2
6 5 1 2 3 4

Output:
3
1 2 4*/
// ll rec(ll i , ll j )
// {
//     // this returns the length of the longest common subsequence of the first i elements of a and the first j elements of b
//     if ( i == 0 || j == 0 ) return 0 ; 
//     if ( dp[i][j] != -1 ) return dp[i][j] ; 
//     ll ans = 0 ; 
//     if ( a[i - 1] == b[j - 1] ) ans = 1 + rec(i - 1 , j - 1 ) ; 
//     else ans = max(rec(i - 1 , j) , rec(i , j - 1)) ; 
//     return dp[i][j] = ans ; 
// }
void print(ll i , ll j , ll a[] , ll b[] , vector <vector<ll>> &dp)
{
    if ( i == 0 || j == 0 ) return ; 
    if ( a[i - 1] == b[j - 1] ) 
    {
        print(i - 1 , j - 1 , a , b , dp) ; 
        cout << a[i - 1] << " " ; 
    }
    else
    {
        if ( dp[i - 1][j] > dp[i][j - 1] ) print(i - 1 , j , a , b , dp) ; 
        else print(i , j - 1 , a , b , dp) ; 
    }
}

void solve() 
{
    ll n , m ; 
    cin >> n >> m ; 
    ll a[n] , b[m] ; 
    for ( ll i = 0 ; i < n ; i++) cin >> a[i] ; 
    for ( ll i = 0 ; i < m ; i++) cin >> b[i] ; 
    vector <vector<ll>> dp(n+1 , vector<ll>(m + 1 , 0)) ; 
    for ( ll i = 0 ; i <= n ; i++)
    {
        for ( ll j = 0 ; j <= m ; j++)
        {
            if ( i == 0 || j == 0 ) 
            {
                dp[i][j] = 0 ; 
                continue ; 
            }
            if ( a[i - 1] == b[j - 1] ) dp[i][j] = 1 + dp[i - 1][j - 1] ; 
            else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]) ; 
        }
    }
    cout << dp[n][m] << endl ;

    print(n , m , a , b , dp) ;
    

    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  