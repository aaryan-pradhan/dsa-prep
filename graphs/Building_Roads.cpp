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
/*Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3*/
vector<vector<ll>> g ; 
vector<ll> vis ;
ll n , m ;
ll col = 0 ; 
void dfs(ll node)
{
    vis[node] = col ;
    for(auto child : g[node])
    {
        if(!vis[child] )
        {
            dfs(child) ;
        }
    }
}
void solve() 
{
    cin >> n >> m ;
    g.resize(n + 1) ;
    vis.resize(n + 1, 0) ;
    for(ll i = 0 ; i < m ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    } 
    for(ll i = 1 ; i <= n ; i++)
    {
        if(vis[i] == 0)
        {
            col++ ; 
            dfs(i) ;
        }
    }
    cout << col - 1 << endl ;
    vector < vector < ll > > comp(col+1) ; 
    for(ll i = 1 ; i <= n ; i++)
    {
        comp[vis[i]].push_back(i) ;
    }
    for(ll i = 1 ; i < col ; i++)
    {
        cout << comp[i][0] << " " << comp[i+1][0] << endl ;
    }





   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  