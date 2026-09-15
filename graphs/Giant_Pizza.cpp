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
ll encode(ll a)
{
    if(a > 0)
    {
        return 2 * a - 1 ;
    }
    else
    {
        return 2 * abs(a) ;
    }
}
void dfs1(ll node , const vector < vector < ll > > &g , vector < bool > &vis , vector < ll > &order)
{
    vis[node] = true ;
    for(auto child : g[node])
    {
        if(!vis[child])
        {
            dfs1(child , g , vis , order) ;
        }
    }
    order.push_back(node) ;
}

void dfs2(ll node, ll col , const vector < vector < ll > > &rg , vector < ll > &colour)
{
    colour[node] = col ; 
    for(auto child : rg[node])
    {
        if(!colour[child])
        {
            dfs2(child , col , rg , colour) ; 
        }
    }
}

void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector < vector < ll > > g(2 * m + 1) ;
    // +1 -> 1
    // -1 -> 2
    // +2 -> 3
    // -2 -> 4
    //...
    // +m -> 2 * m - 1 
    // -m -> 2 * m
    vector < vector < ll > > rg(2 * m + 1) ;

    for(ll i = 0 ; i < n ; i++)
    {
        char t1 ; 
        cin >> t1 ;
        ll p1 ; 
        cin >> p1 ;
        char t2 ;
        cin >> t2 ;
        ll p2 ;
        cin >> p2 ;
        if(t1 == '+')
        {
            p1 = p1 ; 
        }
        else
        {
            p1 = - p1 ;
        }
        if(t2 == '+')
        {
            p2 = p2 ; 
        }
        else
        {
            p2 = - p2 ;
        }
        // x1 or x2 is the same as 
        // not x1 implies x2 and not x2 implies x1
        g[encode(-p1)].push_back(encode(p2)) ;
        g[encode(-p2)].push_back(encode(p1)) ;
        rg[encode(p2)].push_back(encode(-p1)) ;
        rg[encode(p1)].push_back(encode(-p2)) ;
    }
    vector < ll > order ;
    vector < bool > vis(2 * m + 1 , false) ;

    for(ll i = 1 ; i <= 2 * m ; i++)
    {
        if(!vis[i])
        {
            dfs1(i , g , vis , order) ;
        }
    }
    vector < ll > colour(2 * m + 1 , 0) ;
    ll col = 1 ;
    for(ll i = order.size() - 1 ; i >= 0 ; i--)
    {
        ll node = order[i] ;
        if(!colour[node])
        {
            dfs2(node , col , rg , colour) ; 
            col++ ;
        }
    }
    for(ll i = 1 ; i <= m ; i++)
    {
        if(colour[encode(i)] == colour[encode(-i)])
        {
            cout << "IMPOSSIBLE" << endl ;
            return ;
        }
    }
    vector < char > ans ;
    for(ll i = 1 ; i <= m ; i++)
    {
        if(colour[encode(i)] > colour[encode(-i)])
        {
            ans.push_back('+') ;
        }
        else
        {
            ans.push_back('-') ;
        }
    }
    for(auto& x : ans)
    {
        cout << x << " " ;
    }
    
    cout << endl ;

    







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  