// Problem: Book Shop
// Link: https://cses.fi/problemset/task/1158
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
/*You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
Constraints

1 \le n \le 1000
1 \le x \le 10^5
1 \le h_i, s_i \le 1000

Example
Input:
4 10
4 8 5 3
5 12 8 1

Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.*/


void solve() 
{
    ll n , x ;  
    cin >> n >> x ;
    vector<ll> h(n) , s(n) ;
    for(ll i = 0 ; i < n ; i++) cin >> h[i] ;
    for(ll i = 0 ; i < n ; i++) cin >> s[i] ; 
    vector <vector<ll>> dp(2 , vector<ll>(x + 1 , -1)) ;
    for(ll i = n ; i >= 0 ; i--)
    {
        for(ll left = 0 ; left <= x ; left++)
        {
            if ( i == n )
            {
                if ( left >= 0 ) dp[(i) % 2][left] = 0 ;
                else dp[(i) % 2][left] = -INF ;
            }
            else
            {
                ll ans = dp[(i + 1) % 2][left] ;
                if ( left - h[i] >= 0 ) ans = max(ans , dp[(i + 1) % 2][left - h[i]] + s[i]) ;
                dp[(i) % 2][left] = ans ;
            }
        }
    }
    cout << dp[0][x] << endl ;
}
signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}

// Recall Trail
// Pattern: 0/1 knapsack, bounded by total price, maximize pages
// Approach: dp[left] = max pages buyable with `left` price budget remaining,
// processed right-to-left over books (rolling 2-row array on i parity).
// Each book: either skip it (carry forward dp[i+1][left]) or buy it if
// affordable (dp[i+1][left-h[i]] + s[i]).
