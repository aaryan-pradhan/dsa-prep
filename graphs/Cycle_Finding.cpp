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
/*You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
Input
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,\ldots,n.
After this, the input has m lines describing the edges. Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.
Output
If the graph contains a negative cycle, print first "YES", and then the nodes in the cycle in their correct order. If there are several negative cycles, you can print any of them. If there are no negative cycles, print "NO".
Constraints

1 \le n \le 2500
1 \le m \le 5000
1 \le a,b \le n
-10^9 \le c \le 10^9

Example
Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output:
YES
1 2 4 1*/

void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector < vector <pll>> g(n + 1) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ;
        g[a].push_back({c , b}) ;
    }
    vector <ll> dist(n + 1, 0) ;
    vector <ll> par(n + 1, -1) ;
    ll x = 0 ;  
    for (ll i = 1 ; i <= n ; i++)
    {
        x = 0 ; 
        for(ll node = 1 ; node <= n ; node++)
        {
            for (auto& edge : g[node])
            {
                ll child = edge.sc ;
                ll wt = edge.fr ;
                if(dist[node] + wt < dist[child])
                {
                    dist[child] = dist[node] + wt ;
                    par[child] = node ;
                    x = child ; 
                }
            }
        }
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        if(x == 0)
        {
            break ;
        }
        x = par[x] ;
    }
    if(x == 0)
    {
        pn ; 
    }
    else 
    {
        py ; 
        vector <ll> ans ;
        ll temp = x ; 
        while(temp != x || ans.size() == 0)
        {
            ans.push_back(temp) ;
            temp = par[temp] ;
        }
        ans.push_back(x) ;
        reverse(ans.begin(), ans.end()) ;
        for (auto& x : ans)
        {
            cout << x << " " ;
        }
        cout << endl ; 
    }

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  