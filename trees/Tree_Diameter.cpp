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
/*Given a tree with n nodes, find the diameter of the tree.
The diameter of a tree is the number of edges in the longest path between any two nodes in the tree.
Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print one integer: the diameter of the tree.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5
1 2
1 3
3 4
3 5

Output:
3

*/
vector < vector < ll > > g ;
vector < ll > d ;
void dfs(ll node, ll par, ll depth)
{
    d[node] = depth ;
    for(auto child : g[node])
    {
        if(child != par)
        {
            dfs(child , node , depth + 1) ;
        }
    } 
}
void solve() 
{
    ll n ; 
    cin >> n ;
    g.resize(n+1) ;
    d.resize(n+1) ;
    for(ll i = 1 ; i <= n-1 ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    dfs(1 , 0 , 0) ;
    ll mx = 0 ;
    ll node = 1 ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(d[i] > mx)
        {
            mx = d[i] ;
            node = i ;
        }
    }
    dfs(node , 0 , 0) ;
    mx = 0 ;
    for(ll i = 1 ; i <= n ; i++)
    {
        mx = max(mx , d[i]) ;
    }
    cout << mx << endl ;
    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  