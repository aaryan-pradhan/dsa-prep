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
#define MAXN 1000005
ll madd(ll a , ll b)
{
    return (a + b) % MOD ;
}
ll msub(ll a , ll b)
{
    return (a - b + MOD) % MOD ;
}
ll mmul(ll a , ll b)
{
    return (a * b) % MOD ;
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
ll fact[MAXN] , invfact[MAXN] ;
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
    string s ; 
    cin >> s ;
    ll n = s.size() ;
    vector < ll > b(26 , 0) ;
    for(ll i = 0 ; i < n ; i++)
    {
        b[s[i] - 'a']++ ;
    }
    ll ans = 1 ; 
    for(ll i = 0 ; i < 26 ; i++)
    {
        ans = mmul(ans , invfact[b[i]]) ;
    }
    ans = mmul(ans , fact[n]) ;
    cout << ans << endl ;

    

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill() ;
    solve() ; 
}
    
  