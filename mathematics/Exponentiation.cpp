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
ll mmul(ll a , ll b)
{
    return (a * b) % MOD;
}
ll mpow(ll a , ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = mmul(res , a);
        a = mmul(a , a);
        b >>= 1;
    }
    return res;
}
void solve() 
{
    ll a , b;
    cin >> a >> b;
    cout << mpow(a , b) << endl;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t ;
    cin >> t ;
    while(t--)
    {
        solve();
    }
}
    
  