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

Your task is to find a minimum-price flight route from Syrjälä to Metsälä. You have one discount coupon, using which you can halve the price of any single flight during the route. However, you can only use the coupon once.
When you use the discount coupon for a flight whose price is x, its price becomes \lfloor x/2 \rfloor (it is rounded down to an integer).
Input
The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Metsälä.
After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.
You can assume that it is always possible to get from Syrjälä to Metsälä.
Output
Print one integer: the price of the cheapest route from Syrjälä to Metsälä.
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
3 4
1 2 3
2 3 1
1 3 7
2 1 5

Output:
2*/
ll encode(ll a , ll b)
{
    return a * 2 + b ; 
}
void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    ll N = n * 2 + 1 ;
    vector < vector <pll>> g(N+1) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ;
        g[encode(a, 0)].push_back({c , encode(b, 0)}) ;
        g[encode(a, 0)].push_back({c / 2 , encode(b, 1)}) ;
        g[encode(a, 1)].push_back({c , encode(b, 1)}) ;
    }
    vector <ll> vis(N + 1, 0) ;
    vector <ll> dist(N + 1, INF) ;
    dist[encode(1, 0)] = 0 ;
    priority_queue <pll, vector<pll>, greater<pll>> pq ;
    pq.push({0, encode(1, 0)}) ;

    while(!pq.empty())
    {
        ll node = pq.top().sc ;
        ll d = pq.top().fr ;
        pq.pop() ;
        if(vis[node])
        {
            continue ;
        }
        vis[node] = 1 ;
        for (auto x : g[node])
        {
            ll child = x.sc ;
            ll w = x.fr ;
            if(dist[child] > dist[node] + w)
            {
                dist[child] = dist[node] + w ;
                pq.push({dist[child], child}) ;
            }
        }
    }

    cout << dist[encode(n, 1)] << endl ;

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  