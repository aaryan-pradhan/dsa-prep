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

There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.
For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].
Input
The only input line has two integers n and m.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n,m \le 10^6

Example
Input:
3 2

Output:
6*/
const ll MAXN = 2000005 ;
ll fact[MAXN] , invfact[MAXN] ;
ll mcorr(ll a)
{
    return (a % MOD + MOD) % MOD ;
}
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
void fill()
{
    fact[0] = 1 ;
    for(ll i = 1 ; i < MAXN ; i++)
    {
        fact[i] = mmul(fact[i - 1] , i) ;
    }
    invfact[MAXN - 1] = minv(fact[MAXN - 1]) ;
    for(ll i = MAXN - 2 ; i >= 0 ; i--)
    {
        invfact[i] = mmul(invfact[i + 1] , (i + 1)) ;
    }
}
ll ncr(ll n , ll r)
{
    if(r > n || r < 0)
    {
        return 0 ;
    }
    return mmul(fact[n] , mmul(invfact[r] , invfact[n - r])) ;
}
void solve() 
{

    ll n , m ; 
    cin >> n >> m ;
    ll st = m ; 
    ll br = n - 1 ;
    ll tot = st + br ;
    cout << ncr(tot , br) << endl ;
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill() ;
    solve() ; 
}
    
  