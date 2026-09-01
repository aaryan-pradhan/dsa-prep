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
#define pn cout << "IMPOSSIBLE" << endl
#define pll pair<ll,ll>

using namespace std;
/*Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5*/
void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector<vector<ll>> g(n + 1) ; 
    for(ll i = 0 ; i < m ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    vector<ll> vis(n + 1, 0) ; 
    vector<ll> par(n + 1, -1) ; 
    queue<ll> q ; 
    q.push(1) ; 
    vis[1] = 1 ;
    while(!q.empty())
    {
        ll node = q.front() ; 
        q.pop() ; 
        
        for(auto child : g[node])
        {
            if(!vis[child])
            {
                vis[child] = 1 ;
                par[child] = node ; 
                q.push(child) ; 

            }
        }
    }
    if(!vis[n])
    {
        pn ; 
        return ;    
    }
    else 
    {
        vector<ll> ans ; 
        ll node = n ; 
        while(node != -1)
        {
            ans.push_back(node) ; 
            node = par[node] ; 
        }
        reverse(ans.begin(), ans.end()) ; 
        cout << ans.size() << endl ; 
        for(auto x : ans)
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
    
  