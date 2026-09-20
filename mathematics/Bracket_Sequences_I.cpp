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
/*Your task is to calculate the number of valid bracket sequences of length n. For example, when n=6, there are 5 sequences:

()()()
()(())
(())()
((()))
(()())

Input
The only input line has an integer n.
Output
Print the number of sequences modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
6

Output:
5*/
#define N 2000005
ll madd(ll a, ll b) { return (a%MOD + b%MOD) % MOD; }
ll mmul(ll a, ll b) { return (a%MOD * b%MOD) % MOD; }
ll mpow(ll a, ll b) 
{
    ll res = 1;
    while(b) 
    {
        if(b&1) res = mmul(res, a);
        a = mmul(a, a);
        b >>= 1;
    }
    return res;
}
ll minv(ll a) { return mpow(a, MOD-2); }
ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }
ll fact[N], invfact[N];
void fill()
{
    fact[0] = 1;
    for(ll i=1; i<N; i++) fact[i] = mmul(fact[i-1], i);
    invfact[N-1] = minv(fact[N-1]);
    for(ll i=N-2; i>=0; i--) invfact[i] = mmul(invfact[i+1], i+1);
}

ll ncr(ll n, ll r) 
{
    if(r>n || r<0) return 0;
    return mmul(fact[n], mmul(invfact[r], invfact[n-r]));
}
void solve() 
{
    ll n ; 
    cin >> n ;
    if(n%2)
    {
        cout << 0 << endl ;
        return ; 
    }
    ll m = n/2 ;
    ll ans = mdiv(ncr(n, m), (m+1)) ;
    cout << ans << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill();
    solve() ; 
}
    
  