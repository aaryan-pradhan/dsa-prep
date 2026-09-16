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
/*You are given a tree consisting of n nodes, and m paths in the tree.
Your task is to calculate for each node the number of paths containing that node.
Input
The first input line contains integers n and m: the number of nodes and paths. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Finally, there are m lines describing the paths. Each line contains two integers a and b: there is a path between nodes a and b.
Output
Print n integers: for each node 1,2,\ldots,n, the number of paths containing that node.
Constraints

1 \le n, m \le 2 \cdot 10^5
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
3 1 3 1 1*/
vector < vector < ll > > g;
vector < ll > d ;
vector < vector < ll > > up ;
vector < ll > topo ;
vector < ll > cnt ; 
ll n , q ; 
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
    topo.push_back(node) ;
}
void solve() 
{
    cin >> n >> q ; 
    g.resize(n+1) ;
    d.resize(n+1) ;
    up.resize(20 , vector < ll > (n + 1, 0)) ;
    cnt.assign(n + 1, 0) ;
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
            up[sa][node] = up[sa - 1][up[sa - 1][node]] ;
        }
    }
    while(q--)
    {
        ll a , b ;
        cin >> a >> b ;
        if (d[a] < d[b]) swap(a , b) ;
        ll node_a = a , node_b = b ;
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

            if (up[sa][a] != up[sa][b])
            {
                a = up[sa][a] ;
                b = up[sa][b] ;
            }
        }
        if(a != b)
        {
            a = up[0][a] ;
            b = up[0][b] ;
        }
        ll lca = a ;
        ll parent = up[0][lca] ;
        cnt[node_a]++ ;
        cnt[node_b]++ ;
        cnt[lca]-- ;
        if(parent != 0)
        {
            cnt[parent]-- ;
        }


        




    }
    for(auto& node : topo)
    {
        cnt[up[0][node]] += cnt[node] ;
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        cout << cnt[i] << " " ;
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
    
  