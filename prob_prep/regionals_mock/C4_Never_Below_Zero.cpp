// Problem: C4. Never Below Zero (QuantFest 2026 Mock Regionals, Test 1)
// Link: ../QuantFest_2026_Mock_Regionals.md
// Count the orderings of n up-steps (+1) and m down-steps (−1) whose running sum never goes below 0. Output mod 998244353.
//
// Input: q, then q lines each with n m (1 ≤ q ≤ 10⁵, 0 ≤ n, m ≤ 10⁶).
//
// | Input | Output |
// |---|---|
// | 4 / 2 1 / 3 3 / 5 2 / 3 4 | 2 5 14 0 |
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
    return (a%MOD1 + b%MOD1) % MOD1;
}
ll msub(ll a , ll b)
{
    return (a%MOD1 - b%MOD1 + MOD1) % MOD1;
}
ll mmul(ll a , ll b)
{
    return (a%MOD1 * b%MOD1) % MOD1;
}
ll mpow(ll a , ll b)
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
ll minv(ll a)
{
    return mpow(a, MOD1-2);
}
ll mdiv(ll a , ll b)
{
    return mmul(a, minv(b));
}
ll fact[1000001];
ll invfact[1000001];
void precompute()
{
    fact[0] = 1;
    for(ll i = 1; i <= 1000000; i++)
    {
        fact[i] = mmul(fact[i-1], i);
    }
    invfact[1000000] = minv(fact[1000000]);
    for(ll i = 999999; i >= 0; i--)
    {
        invfact[i] = mmul(invfact[i+1], i+1);
    }
}
ll nCr(ll n, ll r)
{
    if(r > n || r < 0) return 0;
    return mmul(fact[n], mmul(invfact[r], invfact[n-r]));
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    if(n < m) 
    {
        cout << 0 << endl;
        return;
    }
    ll ans = mmul(nCr(n+m, n), mdiv(n-m+1, n+1));
    cout << ans << endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    ll t ; 
    cin >> t;
    while(t--)
    {
        solve() ; 
    }

}
