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
#define ld long double
using namespace std;
/*Time limit: 1.00 s
Memory limit: 512 MB

An array has n integers x_1,x_2,\dots,x_n, and each of them has been randomly chosen between 1 and r_i. An inversion is a pair (a,b) where a<b and x_a>x_b.
What is the expected number of inversions in the array?
Input
The first input line contains an integer n: the size of the array.
The second line contains n integers r_1,r_2,\dots,r_n: the range of possible values for each array position.
Output
Print the expected number of inversions rounded to six decimal places (rounding half to even).
Constraints

1 \le n \le 100
1 \le r_i \le 100

Example
Input:
3
5 2 7

Output:
1.057143*/

// ---------- rounding helper: exact half-to-even to 6 decimals ----------
typedef vector<unsigned long long> Big;                 // base 1e9, little endian
const unsigned long long BASE = 1000000000ULL;
Big mulSmall(Big a, unsigned long long k)
{
    unsigned __int128 c = 0;
    for (auto &d : a) { c += (unsigned __int128)d * k; d = (unsigned long long)(c % BASE); c /= BASE; }
    while (c) { a.push_back((unsigned long long)(c % BASE)); c /= BASE; }
    return a;
}
Big addBig(Big a, const Big &b)
{
    if (a.size() < b.size()) a.resize(b.size(), 0);
    unsigned long long c = 0;
    for (size_t i = 0; i < a.size(); i++) { c += a[i] + (i < b.size() ? b[i] : 0); a[i] = c % BASE; c /= BASE; }
    if (c) a.push_back(c);
    return a;
}
int cmpBig(Big a, Big b)
{
    while (a.size() > 1 && a.back() == 0) a.pop_back();
    while (b.size() > 1 && b.back() == 0) b.pop_back();
    if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
    for (int i = (int)a.size() - 1; i >= 0; i--) if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
    return 0;
}
struct Rounded { ld ans; vector<ll> &r; Rounded(ld a, vector<ll> &v) : ans(a), r(v) {} };
ostream& operator<<(ostream& os, const Rounded& x)
{
    ll n = x.r.size();
    auto favOf = [&](ll a, ll b) { return (a <= b) ? a * (a - 1) / 2 : b * (b - 1) / 2 + (a - b) * b; };
    auto vp = [&](ll v, ll p) { ll e = 0; while (v % p == 0) { v /= p; e++; } return e; };
    vector<ll> primes;
    for (ll p = 2; p <= 100; p++) { bool ok = true; for (ll q = 2; q * q <= p; q++) if (p % q == 0) ok = false; if (ok) primes.push_back(p); }

    // L = lcm of all denominators r_i * r_j
    vector<ll> E(primes.size(), 0);
    for (ll i = 0; i < n; i++) for (ll j = i + 1; j < n; j++)
        for (size_t k = 0; k < primes.size(); k++) E[k] = max(E[k], vp(x.r[i] * x.r[j], primes[k]));
    Big L = {1};
    for (size_t k = 0; k < primes.size(); k++) for (ll t = 0; t < E[k]; t++) L = mulSmall(L, primes[k]);

    // exact answer = N / L,  approximate answer in quad precision
    Big N = {0};
    __float128 val = 0;
    for (ll i = 0; i < n; i++) for (ll j = i + 1; j < n; j++)
    {
        ll a = x.r[i], b = x.r[j], tot = a * b, fav = favOf(a, b);
        val += (__float128)fav / tot;
        Big term = {(unsigned long long)fav};
        for (size_t k = 0; k < primes.size(); k++)
            for (ll t = vp(tot, primes[k]); t < E[k]; t++) term = mulSmall(term, primes[k]);
        N = addBig(N, term);
    }

    ll re = (ll)(val * 1000000);
    // compare N * 2e6  with  (2*re + 1) * L   exactly
    int c = cmpBig(mulSmall(N, 2000000), mulSmall(L, 2 * re + 1));
    if (c > 0) re++;                       // above half -> round up
    else if (c == 0 && re % 2) re++;       // exact tie  -> half to even
    return os << re / 1000000 << "." << setw(6) << setfill('0') << re % 1000000 << setfill(' ');
}
// ------------------------------------------------------------------------

ld rec(ll i , ll j, vector<ll> &r)
{
    // if we are on the ith and jth position, then rec returns the probability that x_i > x_j
    // there are r_i * r_j total possibilities, and there are (r_i - 1) + (r_i - 2) + ... + (r_i - r_j) possibilities where x_i > x_j
    ll tot = r[i] * r[j];
    if( r[i] <= r[j])
    {
        // r[i] , (1...r[i]- 1) , (2 , (1...r[i]- 2) , (3 , (1...r[i]- 3) , ... , (r[i] - 1 , 1)
        ll fav = (r[i] - 1) * r[i] / 2;
        return fav * 1.0 / tot;

    }
    else 
    {
        // r[j] , (1...r[j]- 1) , (2 , (1...r[j]- 2) , (3 , (1...r[j]- 3) , ... , (r[j] - 1 , 1) 
        // r[j] - 1 + r[j] - 2 + ... + 1 = (r[j] - 1) * r[j] / 2
        ll fav = (r[j] - 1) * r[j] / 2 ; 
        // (r[j] + 1  , (1...r[j]) , (r[j] + 2 , (1...r[j]) , ... , (r[i] , (1...r[j])
        // r[j] + r[j] + ... + r[j] = (r[i] - r[j]) * r[j]
        fav += (r[i] - r[j]) * r[j];
        return fav * 1.0 / tot;

    }


    
}

void solve() 
{
    ll n ; 
    cin >> n ;
    vector<ll> r(n);
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> r[i];
    }
    ld ans = 0 ; 
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = i + 1 ; j < n ; j++)
        {
            ans += rec(i , j , r);
        }
    }
    cout << fixed << setprecision(6) << Rounded(ans, r) << endl;

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}