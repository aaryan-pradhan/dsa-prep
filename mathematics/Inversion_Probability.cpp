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
struct Rounded { ld ans; vector<ll> &r; Rounded(ld a, vector<ll> &v) : ans(a), r(v) {} };
ostream& operator<<(ostream& os, const Rounded& x)
{
    const ll P = 1000000007;
    auto pw = [&](ll b, ll e){ ll res = 1; b %= P; while(e){ if(e&1) res = res*b%P; b = b*b%P; e >>= 1; } return res; };
    ll n = x.r.size(), m = 0;
    ld val = 0;
    for(ll i = 0 ; i < n ; i++) for(ll j = i + 1 ; j < n ; j++)
    {
        ll a = x.r[i], b = x.r[j], tot = a * b;
        ll fav = (a <= b) ? a * (a - 1) / 2 : b * (b - 1) / 2 + (a - b) * b;
        val += fav * 1.0L / tot;
        m = (m + fav % P * pw(tot, P - 2)) % P;
    }
    ld v = val * 1e6L;
    ll re = (ll)floorl(v);
    if(m * 2000000 % P == (2 * re + 1) % P) { if(re % 2) re++; }
    else if(v - re > 0.5L) re++;
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