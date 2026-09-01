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
/*There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
Input
The first input line has three integers n, m and q: the number of cities, roads, and queries.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.
Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.
Output
Print the length of the shortest route for each query. If there is no route, print -1 instead.
Constraints

1 \le n \le 500
1 \le m \le n^2
1 \le q \le 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3*/

void solve() 
{
    ll n , m , q ;
    cin >> n >> m >> q ;
    vector < vector <ll>> g(n + 1, vector<ll>(n + 1, INF)) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ; 
        g[a][b] = min(g[a][b], c) ;
        g[b][a] = min(g[b][a], c) ;
    }
    for (ll i = 1 ; i <= n ; i++)
    {
        g[i][i] = 0 ;
    }
    for (ll k = 1 ; k <= n ; k++)
    {
        for (ll i = 1 ; i <= n ; i++)
        {
            for (ll j = 1 ; j <= n ; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]) ;
            }
        }
    }
    for (ll i = 0 ; i < q ; i++)
    {
        ll a , b ; 
        cin >> a >> b ; 
        if(g[a][b] == INF)
        {
            cout << -1 << endl ;
        }
        else
        {
            cout << g[a][b] << endl ;
        }
    }
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  