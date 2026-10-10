

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
vector < vector < ll > >  graph ; 
ll n ; 
vector < ll > indp ; 
vector < ll > outdp ;
vector < ll > a ;
void dfsin(ll n , ll p )
{
    indp[n] = ( a[n] == 1 ? 1 : -1 ) ;
    for(auto ch : graph[n])
    {
        if(ch == p) continue ; 
        dfsin(ch, n ) ; 
        indp[n] += max(0LL, indp[ch]) ;
    }

}
// p - > n - > c 
void dfsout( ll n , ll p, ll outval )
{
    outdp[n] = outval ;
    for(auto ch : graph[n])
    {
        if(ch == p) continue ; 
        // what will the new out value be for the children
        // sare baki sab children ( matlab is child ko chdke baki sab children ka contribution ) + parent ka contribution
        ll newout = 0 ; 
        newout += max(0LL, outval) ;
        // baki sab children ka contribution 
        ll cc = indp[n] - max(0LL, indp[ch]) - ( a[n] == 1 ? 1 : -1 ) ;
        newout += (a[n]== 1) ? 1 : -1 ;
        newout += max(0LL, cc) ;
        dfsout(ch, n , newout ) ;


    }
    

}

void solve() {
    cin >> n ; 
    graph.assign(n+1, vector < ll > () ) ;
    indp.assign(n+1, 0 ) ;
    outdp.assign(n+1, 0 ) ;
    a.assign(n+1, 0 ) ;
    for(ll i = 1 ; i <= n ; i++) cin >> a[i] ; 
    for(ll i = 1 ; i < n ; i++)
    {
        ll u , v ; 
        cin >> u >> v ; 
        graph[u].push_back(v) ; 
        graph[v].push_back(u) ; 
    }
    dfsin(1, 0) ;
    dfsout(1, 0, 0 ) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cout << indp[i] + max(0LL, outdp[i]) << " " ; 
    }
    cout << endl ;




}

signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t ; 
    t = 1 ; 
    while(t--)
    {
        solve() ; 
    }

    return 0;
}

