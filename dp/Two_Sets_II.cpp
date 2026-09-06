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

Your task is to count the number of ways numbers 1,2,\ldots,n can be divided into two sets of equal sum.
For example, if n=7, there are four solutions:

\{1,3,4,6\} and \{2,5,7\}
\{1,2,5,6\} and \{3,4,7\}
\{1,2,4,7\} and \{3,5,6\}
\{1,6,7\} and \{2,3,4,5\}

Input
The only input line contains an integer n.
Output
Print the answer modulo 10^9+7.
Constraints

1 \le n \le 500

Example
Input:
7

Output:
4*/
ll madd(ll a, ll b) 
{
    return (a + b) % MOD;
}
ll mmul(ll a, ll b) 
{
    return (a * b) % MOD;
}
ll mpow(ll a , ll b)
{
    ll res = 1 ; 
    while(b)
    {
        if(b & 1) res = mmul(res , a ) ;
        a = mmul(a , a ) ;
        b >>= 1 ; 
    }
    return res ;
}
ll minv(ll a)
{
    return mpow(a , MOD - 2 ) ;
}
ll mdiv(ll a , ll b)
{
    return mmul(a , minv(b) ) ;
}


// ll rec(ll i , ll sum )
// {
//     // this returns the nnumber of ways to pick elements form 1 .. i such that it sums to sum
//     if (sum == 0) return 1 ;
//     if (i == 0) return 0 ;
//     ll ans = 0 ; 
//     ll take = rec(i - 1 , sum - i ) ;
//     ll nottake = rec(i - 1 , sum ) ;
//     ans = madd(take , nottake ) ;
//     return ans ; 
// }
    

void solve() 
{
    ll n ; 
    cin >> n ;
    ll sum = n * (n + 1) / 2 ;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return ;
    }
    ll ts = sum / 2 ;
    vector <vector<ll>> dp(n + 1 , vector<ll>(ts + 1 , 0 )) ;
    for(ll i = 0 ; i <= n ; i++)
    {
        for(ll sum = 0 ; sum <= ts ; sum++)
        {
            if(sum == 0) dp[i][sum] = 1 ;
            else if (i == 0) dp[i][sum] = 0 ;
            else 
            {
                ll take = 0 , nottake = 0 ; 
                if (sum - i >= 0) take = dp[i - 1][sum - i] ;
                nottake = dp[i - 1][sum] ;
                dp[i][sum] = madd(take , nottake ) ;
            }
        }
    }
    ll ans = mdiv(dp[n][ts] , 2 ) ;

    cout << ans << endl ;
    


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  