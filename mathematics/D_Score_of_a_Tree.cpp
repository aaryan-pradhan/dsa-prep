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
ll n ; 
vector < vector < ll > > g ; 
vector < ll > d ;
vector < ll > md ; 
void dfs(ll node , ll parent , ll depth)
{
    d[node] = depth ; 
    md[node] = depth ; 
    for(auto child : g[node])
    {
        if(child == parent) continue ; 
        dfs(child , node , depth + 1);
        md[node] = max(md[node] , md[child]);
    }
}

void solve() 
{
    cin >> n ;
    g.resize(n+1);
    for(ll i = 0 ; i < n-1 ; i++)
    {
        ll u , v ; 
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d.resize(n+1);
    md.resize(n+1);
    dfs(1 , 0 , 0);
    ll ans = 0 ; 
    for(ll i = 1 ; i <= n ; i++)
    {
        ll res = mpow(2 , n - 1) ; 
        ll sol = mmul(res , (md[i] - d[i] + 1));
        ans = madd(ans , sol);
    }
    cout << ans << endl ;


    






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
        solve() ; 
    }
}
    
  