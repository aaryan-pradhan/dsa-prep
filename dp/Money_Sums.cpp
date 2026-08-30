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
/*You have n coins with certain values. Your task is to find all money sums you can create using these coins.
Input
The first input line has an integer n: the number of coins.
The next line has n integers x_1,x_2,\dots,x_n: the values of the coins.
Output
First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.
Constraints

1 \le n \le 100
1 \le x_i \le 1000

Example
Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13*/
bool rec( ll i , ll s  )
{
    // // this retuns true if we can make a sum of s from the the coin i to the last coin
    // if ( s == 0 ) return true ;
    // if ( i == n ) return false ;
    // if ( dp[i][s] != -1 ) return dp[i][s] ;
    // bool ans = rec(i + 1 , s) ;
    // if ( s >= coins[i] ) ans = ans || rec(i + 1 , s - coins[i]) ;
    // return dp[i][s] = ans ;
    

    
}
void solve() 
{
    ll n ; 
    cin >> n ;
    vector<ll> x(n) ;
    for ( ll i = 0 ; i < n ; i++) cin >> x[i] ;
    vector <vector<bool>> dp(n + 1 , vector<bool>(100001 , false)) ;
    for ( ll i = n ; i >= 0 ; i--)
    {
        for ( ll s = 0 ; s <= 100000 ; s++)
        {
            if ( s == 0 ) dp[i][s] = true ;
            else if ( i == n ) dp[i][s] = false ;
            else 
            {
                bool ans = dp[i + 1][s] ;
                if ( s >= x[i] ) ans = ans || dp[i + 1][s - x[i]] ;
                dp[i][s] = ans ;
            }
        }
    }
    vector<ll> ans ;
    for ( ll s = 1 ; s <= 100000 ; s++)
    {
        if ( dp[0][s] ) ans.push_back(s) ;
    }
    cout << ans.size() << endl ;
    for ( ll i = 0 ; i < ans.size() ; i++) cout << ans[i] << " " ;
    cout << endl ;
    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  