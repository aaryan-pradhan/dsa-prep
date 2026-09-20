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
ll madd(ll a , ll b)
{
    return (a%MOD + b%MOD) % MOD ;
}
ll msub(ll a , ll b)
{
    return (a%MOD - b%MOD + MOD) % MOD ;
}
ll mmul(ll a , ll b)
{
    return (a%MOD * b%MOD) % MOD ;
}
ll mpow(ll a , ll b)
{
    ll res = 1 ;
    while(b)
    {
        if(b & 1)
        {
            res = mmul(res , a) ;
        }
        a = mmul(a , a) ;
        b >>= 1 ;
    }
    return res ;
}
ll minv(ll a)
{
    return mpow(a , MOD - 2) ;
}
ll mdiv(ll a , ll b)
{
    return mmul(a , minv(b)) ;
}

/*There are n children at a Christmas party, and each of them has brought a gift. The idea is that everybody will get a gift brought by someone else.
In how many ways can the gifts be distributed?
Input
The only input line has an integer n: the number of children.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
4

Output:
9*/
// ll rec(ll i)
// {
//     // this returns the number of ways i can give gifts to child from 1 to i such that no child gets their own gift.
//     if(i == 1)
//     {
//         return 0 ;
//     }
//     if(i == 2)
//     {
//         return 1 ;
//     }
//     // now give the gift of child i to child j where j < i. Now there are two cases, either child j gives their gift to child i or not. If they do, then we have to find the number of ways to give gifts to children from 1 to i - 2. If they don't, then we have to find the number of ways to give gifts to children from 1 to i - 1. So the answer is rec(i - 1) + (i - 1) * rec(i - 2).
//     return mmul(i - 1 , madd(rec(i - 1) , rec(i - 2))) ;
// }
void solve() 
{
    ll n ; 
    cin >> n ;
    ll dp[n + 1] ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(i == 1)
        {
            dp[i] = 0 ;
            continue ;
        }
        if(i == 2)
        {
            dp[i] = 1 ;
            continue ;
        }
        ll ans = madd(dp[i - 1] , dp[i - 2]) ;
        ans = mmul(ans , i - 1) ;
        dp[i] = ans ;
    }
    
    cout << dp[n] << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  