// Problem: C3. Ruin, Modulo (QuantFest 2026 Mock Regionals, Test 1)
// Link: ../QuantFest_2026_Mock_Regionals.md
// A gambler holds s dollars. Each round they win $1 with probability p = a/b and lose $1 otherwise, and play stops at $0 or $N. Output the probability of reaching $N, as P·Q⁻¹ mod 998244353.
//
// Input: a b s N (1 ≤ a < b ≤ 10⁹, 0 ≤ s ≤ N ≤ 10¹⁸). It is guaranteed the answer's denominator is not divisible by 998244353.
//
// | Input | Output |
// |---|---|
// | 1 2 1 2 | 499122177 |
// | 2 3 1 2 | 665496236 |
// | 2 3 2 5 | 96604293 |
#include <bits/stdc++.h>
#define ll unsigned long long
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
// answer is 1 - (q/p) raise to i / ( 1 - (q/p) raise to N
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
void solve()
{
    ll n , a, b, s;
    cin >> a >> b >> s >> n;
    if(s == 0) { cout << 0 << endl; return; }
    if(s == n) { cout << 1 << endl; return; }
    ll p = mdiv(a, b);
    ll q = msub(1, p);
    ll r = mdiv(q, p);
    ll rN = mpow(r, n);
    ll rS = mpow(r, s);
    ll ans = mdiv(msub(1, rS), msub(1, rN));
    cout << ans << endl;
    // similiary expected value of the number of rounds is s * (N - s) / (b - a)

    

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
