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
/*There are n cities and m flight connections between them. Your task is to determine the length of the shortest route from Syrjälä to every city.
Input
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\dots,n, and city 1 is Syrjälä.
After that, there are m lines describing the flight connections. Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.
You can assume that it is possible to travel from Syrjälä to all other cities.
Output
Print n integers: the shortest route lengths from Syrjälä to cities 1,2,\dots,n.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
3 4
1 2 6
1 3 2
3 2 3
1 3 4

Output:
0 5 2*/
void solve() 
{
    ll n , m ; 
    cin >> n >> m ; 
    vector < vector <pll>> g(n + 1) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ; 
        g[a].push_back({c, b}) ;
        // daam phir naam
    }
    vector <ll> dist(n + 1, INF) ;
    vector < ll > vis(n + 1, 0) ;
    priority_queue <pll, vector<pll>, greater<pll>> pq ;
    dist[1] = 0 ;
    pq.push({0, 1}) ;
    while(!pq.empty())
    {
        pll x = pq.top() ;
        pq.pop() ;
        ll node = x.sc ;
        ll d = x.fr ;
        if(vis[node])
        {
            continue ;
        }
        vis[node] = 1 ;
        for(auto y : g[node])
        {
            ll child = y.sc ;
            ll w = y.fr ;
            if(dist[child] > dist[node] + w)
            {
                dist[child] = dist[node] + w ;
                pq.push({dist[child], child}) ;
            }


        }

    }
    for (ll i = 1 ; i <= n ; i++)
    {
        cout << dist[i] << " " ;
    }
    






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  