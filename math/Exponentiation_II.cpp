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
/*Your task is to efficiently calculate values a^{b^c} modulo 10^9+7.
Note that in this task we assume that 0^0=1.
Input
The first input line has an integer n: the number of calculations.
After this, there are n lines, each containing three integers a, b and c.
Output
Print each value a^{b^c} modulo 10^9+7.
Constraints

1 \le n \le 10^5
0 \le a,b,c \le 10^9

Example
Input:
3
3 7 1
15 2 2
3 4 5

Output:
2187
50625
763327764*/
ll mmul(ll a , ll b, ll mod = MOD)
{
    return (a * b) % mod;
}
ll mpow(ll a , ll b, ll mod = MOD)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = mmul(res , a, mod);
        a = mmul(a , a, mod);
        b >>= 1;
    }
    return res;
}

void solve() 
{
    ll a , b , c;
    cin >> a >> b >> c;
    if(a == 0 && b == 0) 
    {
        if(c == 0)
        {
            cout << 0 << endl;
            return;
        }
        else 
        {
            cout << 1 << endl;
            return;
        }
    }
    if(a == 0 && b != 0) 
    {
        cout << 0 << endl;
        return;
    }
    
    
    // a raise to b raise to c mod 10^9 + 7
    // a raise to b raise to c mod 10^9 + 7 = a raise to (b raise to c mod 10^9 + 6) mod 10^9 + 7
    // a raise to p mod m = a raise to (p mod (m - 1)) mod m // fermat's little theorem
    ll x = mpow(b , c, MOD - 1);
    cout << mpow(a , x, MOD) << endl;
    






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t ;
    cin >> t ;
    while(t--)
        solve() ; 
}
    
  