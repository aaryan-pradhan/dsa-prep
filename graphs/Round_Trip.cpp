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
/*Time limit: 1.00 s
Memory limit: 512 MB

Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3*/

ll n , m ;
vector<vector<ll>> g ;
vector<ll> vis ;
vector<ll> par ;

void dfs(ll node , ll parent)
{
    vis[node] = 1 ;
    par[node] = parent ;
    for(auto child : g[node])
    {
        if(child == parent)
        {
            continue ; 
        }
        if(vis[child] == 0 )
        {
            dfs(child, node) ;
        }
        else if( vis[child] == 1 )
        {
            ll temp = node ; 
            vector <ll> ans ;
            while (temp != child)
            {
                ans.push_back(temp) ;
                temp = par[temp] ;
            }
            ans.push_back(temp) ; 
            ans.push_back(node) ;
            reverse(ans.begin(), ans.end()) ;
            cout << ans.size() << endl ;
            for (auto& x : ans)
            {
                cout << x << " " ;
            }
            cout << endl ; 
            exit(0) ;
        }
        else 
        {
            continue ; 
        }

    }
    vis[node] = 2 ;

}
void solve() 
{
    cin >> n >> m ;
    g.resize(n + 1) ;
    vis.resize(n + 1, 0) ;
    par.resize(n + 1, 0) ;
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b ;
        cin >> a >> b ;
        g[a].push_back(b) ;
        g[b].push_back(a) ;
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            dfs(i, 0) ;
                
        }
    }
    cout << "IMPOSSIBLE" << endl ;
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  