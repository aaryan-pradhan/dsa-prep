/*
IITD Squarepoint OA - SDE

Problem:
There are n nodes in a graph out of which some are infected. Infected node can infect their neighbors and so on... 
We can remove at most 1 infected node such that infected nodes in remaining graph is minimized.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// write a dsu 
struct DSU
{
    vector < ll > par , rank ; 
    DSU(ll n)
    {
        par.assign(n + 1 , 0) ; 
        rank.assign(n + 1 , 0) ; 
        for(ll i = 1 ; i <= n ; i++)
        {
            par[i] = i ; 
            rank[i] = 1 ; 
        }
    }
    ll find(ll x)
    {
        if(par[x] == x)
        {
            return x ; 
        }
        return par[x] = find(par[x]) ; 
    }
    ll merge(ll x , ll y)
    {
        ll px = find(x) ; 
        ll py = find(y) ; 
        if(px == py)
        {
            return 0 ; 
        }
        if(rank[px] < rank[py])
        {
            par[px] = py ; 
            rank[py] += rank[px] ; 
        }
        else
        {
            par[py] = px ; 
            rank[px] += rank[py] ; 
        }
        return 1 ; 
    }

};
void solve() {
    ll n ; 
    cin >> n ;
    vector < ll > infected(n + 1 , 0) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> infected[i] ; 
    }
    DSU dsu(n) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        ll x ; 
        cin >> x ; 
        dsu.merge(i , x) ; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
