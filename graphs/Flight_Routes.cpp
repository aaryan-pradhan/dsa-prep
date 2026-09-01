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
/*Your task is to find the k shortest flight routes from Syrjälä to Metsälä. A route can visit the same city several times.
Note that there can be several routes with the same price and each of them should be considered (see the example).
Input
The first input line has three integers n, m, and k: the number of cities, the number of flights, and the parameter k. The cities are numbered 1,2,\ldots,n. City 1 is Syrjälä, and city n is Metsälä.
After this, the input has m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. All flights are one-way flights.
You may assume that there are at least k distinct routes from Syrjälä to Metsälä.
Output
Print k integers: the prices of the k cheapest routes sorted according to their prices.
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9
1 \le k \le 10

Example
Input:
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1

Output:
4 4 7

Explanation: The cheapest routes are 1 \rightarrow 3 \rightarrow 4 (price 4), 1 \rightarrow 2 \rightarrow 3 \rightarrow 4 (price 4) and 1 \rightarrow 2 \rightarrow 4 (price 7).*/
void solve() 
{
    ll n , m , k ; 
    cin >> n >> m >> k ; 
    vector < vector <pll>> g(n + 1) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ;
        g[a].push_back({c , b}) ;
    }

    vector < ll > vis(n + 1, 0) ;
    priority_queue < pll , vector <pll> , greater<pll>> pq ;

    pq.push({0 , 1}) ;
    vector <ll> ans ;
    while(!pq.empty())
    {
        auto [d , node] = pq.top() ;
        pq.pop() ;
        if(vis[node] == k)
        {
            continue ; 
        }
        vis[node]++ ;
        if(node == n)
        {
            ans.push_back(d) ;
            if(ans.size() == k)
            {
                break ; 
            }
        }
        for (auto& edge : g[node])
        {
            ll child = edge.sc ;
            ll wt = edge.fr ;
            if(vis[child] < k)
            {
                pq.push({d + wt , child}) ;
            }
        }
    }
    for (auto& x : ans)
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
    
  