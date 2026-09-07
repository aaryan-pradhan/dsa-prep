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
/*Let \sigma(n) denote the sum of divisors of an integer n. For example, \sigma(12)=1+2+3+4+6+12=28.
Your task is to calculate the sum \sum_{i=1}^n \sigma(i) modulo 10^9+7.
Input
The only input line has an integer n.
Output
Print \sum_{i=1}^n \sigma(i) modulo 10^9+7.
Constraints

1 \le n \le 10^{12}

Example
Input:
5

Output:
21*/
ll madd(ll a , ll b)
{
    return (a % MOD + b % MOD) % MOD ; 
}
ll mmul(ll a , ll b)
{
    return ((a%MOD)*(b%MOD)) % MOD ; 
}
ll mpow(ll a , ll b)
{
    ll res = 1 ; 
    while(b)
    {
        if(b & 1) res = mmul(res , a) ; 
        a = mmul(a , a) ; 
        b >>= 1 ; 
    }
    return res ; 
}
ll mdiv(ll a , ll b)
{
    return mmul(a , mpow(b , MOD - 2)) ; 
}
ll msub(ll a , ll b)
{
    return (a%MOD - b%MOD + MOD) % MOD ;
}
ll mcorr(ll a)
{
    return (a % MOD + MOD) % MOD ;
}
void solve() 
{
   
    ll n ; 
    cin >> n ;
    ll ans = 0 ; 
    ll l = 1 ; 
    while(l <= n)
    {
        ll v = n / l ;
        ll r = n / v ;
        ll cnt = madd(msub(r , l), 1) ;
        ll sum = mdiv(mmul(cnt , madd(l , r)) , 2) ; 
        ans = madd(ans , mmul(sum , v)) ;
        l = r + 1 ;
    }
    cout << mcorr(ans) << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  