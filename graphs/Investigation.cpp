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
/*You are going to travel from Syrjälä to Lehmälä by plane. You would like to find answers to the following questions:

what is the minimum price of such a route?
how many minimum-price routes are there? (modulo 10^9+7)
what is the minimum number of flights in a minimum-price route?
what is the maximum number of flights in a minimum-price route?

Input
The first input line contains two integers n and m: the number of cities and the number of flights. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. Each line has three integers a, b, and c: there is a flight from city a to city b with price c. All flights are one-way flights.
You may assume that there is a route from Syrjälä to Lehmälä.
Output
Print four integers according to the problem statement.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3

Output:
5 2 1 2*/
ll madd(ll a , ll b)
{
    return (a%MOD + b%MOD)%MOD ; 
}
// ll n , m ; 
// vector<vector<pll>> g ;
// vector<ll> vis ; 
// vector<ll> dist ; 
// ll djisketra(ll src)
// {

//     priority_queue<pll , vector<pll> , greater<pll>> pq ;
//     pq.push({0 , src}) ;
//     while(!pq.empty())
//     {
//         auto [d , node] = pq.top() ;
//         pq.pop() ;
//         if(vis[node])
//         {
//             continue ; 
//         }
//         if(node == n)
//         {
//             return d ; 
//         }
//         vis[node] = 1 ;
//         for(auto [wt , child] : g[node])
//         {
//             if(!vis[child])
//             {
//                 pq.push({d + wt , child}) ;
//             }
//         }
//     }
//     return 0 ; 
// }

void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector<vector<pll>> g(n+1) ;
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ;
        g[a].push_back({c , b}) ;
    }
    // cout << djisketra(1) << " " ;
    vector<ll> dist(n+1 , INF) ;
    vector<ll> ways(n+1 , 0) ;
    vector<ll> min_flights(n+1 , INF) ;
    vector<ll> max_flights(n+1 , 0) ;
    vector<ll> vis(n+1 , 0) ;
    priority_queue<pll , vector<pll> , greater<pll>> q ;
    q.push({0 , 1}) ;
    ways[1] = 1 ;
    min_flights[1] = 0 ;
    max_flights[1] = 0 ;
    dist[1] = 0 ;
    while(!q.empty())
    {
        auto [d , node] = q.top() ;
        q.pop() ;
        if(vis[node])
        {
            continue ; 
        }
        vis[node] = 1 ;
        for(auto [wt , child] : g[node])
        {
            if(d + wt > dist[child])
            {
                continue ; 
            }
            else if(d + wt == dist[child])
            {
                dist[child] = d + wt ;
                ways[child] = madd(ways[child] , ways[node]) ; 
                min_flights[child] = min(min_flights[child] , min_flights[node] + 1) ; 
                max_flights[child] = max(max_flights[child] , max_flights[node] + 1) ; 
            }
            else if( d + wt < dist[child])
            {
                dist[child] = d + wt ; 
                ways[child] = ways[node] ; 
                min_flights[child] = min_flights[node] + 1 ; 
                max_flights[child] = max_flights[node] + 1 ; 
                q.push({dist[child] , child}) ;
            }
        }

    }
    cout << dist[n] << " " << ways[n] << " " << min_flights[n] << " " << max_flights[n] << endl ;
    




    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  