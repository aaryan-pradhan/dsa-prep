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

You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. You may go through a tunnel several times.
Your task is to walk from room 1 to room n. What is the maximum score you can get?
Input
The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,\dots,n.
Then, there are m lines describing the tunnels. Each line has three integers a, b and x: the tunnel starts at room a, ends at room b, and it increases your score by x. All tunnels are one-way tunnels.
You can assume that it is possible to get from room 1 to room n.
Output
Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print -1.
Constraints

1 \le n \le 2500
1 \le m \le 5000
1 \le a,b \le n
-10^9 \le x \le 10^9

Example
Input:
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Output:
5*/




void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector < vector <pll>> g(n + 1) ;
    vector< vector < ll >> rg(n + 1) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ; 
        g[a].push_back({-c, b}) ;
        rg[b].push_back(a) ;
    }
    vector < ll > vis(n + 1, 0) ;
    queue < ll > q ;
    q.push(n) ;
    vis[n] = 1 ;
    while(!q.empty())
    {
        ll node = q.front() ;
        q.pop() ;
        for(auto child : rg[node])
        {
            if(!vis[child])
            {
                vis[child] = 1 ;
                q.push(child) ;
            }
        }
    }
    vector <ll> dist(n + 1, INF) ;
    dist[1] = 0 ;
    for (ll i = 1 ; i <= n ; i++)
    {
        for (ll node = 1 ; node <= n ; node++)
        {
            if(dist[node] == INF)
            {
                continue ;
            }
            for (auto& x : g[node])
            {
                ll child = x.sc ;
                ll w = x.fr ;
                if(dist[child] > dist[node] + w && vis[child])
                {
                    dist[child] = dist[node] + w ;
                }
            }
        }
    }
    for (ll node = 1 ; node <= n ; node++)
    {
        if(dist[node] == INF)
        {
            continue ;
        }
        for (auto x : g[node])
        {
            ll child = x.sc ;
            ll w = x.fr ;
            if(dist[child] > dist[node] + w && vis[child])
            {
                cout << -1 << endl ;
                return ; 
            }
            
        }
    }
    cout << -dist[n] << endl ;

    


    

    
    

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
  