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
/*You are given a tree consisting of n nodes.
Your task is to process q queries of the form: what is the distance between nodes a and b?
Input
The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Finally, there are q lines describing the queries. Each line contains two integer a and b: what is the distance between nodes a and b?
Output
Print q integers: the answer to each query.
Constraints

1 \le n, q \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4

Output:
1
3
2*/
ll n , q ; 
vector < vector < ll > > g;
vector < ll > d ;
vector < vector < ll > > up ;
void dfs(ll node , ll parent, ll depth)
{
    d[node] = depth ; 
    up[0][node] = parent ;
    for (auto child : g[node])
    {
        if (child != parent)
        {
            dfs(child , node , depth + 1) ; 
        }
    }
}
void solve() 
{
    cin >> n >> q ;
    g.resize(n+1) ;
    d.resize(n+1) ;
    up.resize(20 , vector < ll > (n + 1, 0)) ;
    for(ll i = 1 ; i < n ; i++)
    {
        ll x , y ; 
        cin >> x >> y ; 
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    dfs(1 , 0 , 0) ;
    for(ll sa = 1 ; sa < 20 ; sa++)
    {
        for(ll node = 1 ; node <= n ; node++)
        {
            up[sa][node] = up[sa-1][up[sa-1][node]] ;
        }
    }
    while(q--)
    {
        ll a , b ;
        cin >> a >> b ;
        if (d[a] < d[b]) swap(a , b) ;
        ll node_a = a , node_b = b ;
        // a is deeper than b
        // lift a to the same depth as b
        ll diff = d[a] - d[b] ;
        for(ll sa = 0 ; sa < 20 ; sa++)
        {
            if (diff & (1 << sa))
            {
                a = up[sa][a] ;
            }
        }
        for(ll sa = 19 ; sa >= 0 ; sa--)
        {
            // if the ancestor 2^sa edges away towards root for a and 2^sa edges away towards root for b are different, then we can lift both a and b to their respective ancestors
            if (up[sa][a] != up[sa][b])
            {
                a = up[sa][a] ;
                b = up[sa][b] ;
            }
            // if the ancestore 2^sa edges away from a and 2^sa edges away from b are the same, then we cannot lift both a and b to their respective ancestors, because they will be the same, so we continue to the next sa which is smaller that is we have overshot our target 
            else
            {
                continue ; 
            }
        }
        // now a and b are at the same depth and their ancestors are the same, so
        if(a != b)
        {
            a = up[0][a] ;
            b = up[0][b] ;
        }
        ll lca = a ;
        cout << d[node_a] + d[node_b] - 2 * d[lca] << endl ;
    }

    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  