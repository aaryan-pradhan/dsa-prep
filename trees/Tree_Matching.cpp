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
A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?
Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print one integer: the maximum number of pairs.
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
2

*/
vector < vector < ll > > g ;
vector < vector < ll > > dp ;

void dfs(ll node, ll par)
{
    // dp[node][0] = maximum matching in the subtree rooted at node when node is not matched
    // dp[node][1] = maximum matching in the subtree rooted at node when node is matched with one of its children
    dp[node][0] = 0 ;
    dp[node][1] = 0 ;
    
    for(auto child : g[node])
    {
        if(child != par)
        {
            dfs(child , node) ;
            // this should fill up node's children's dp values first, then we can calculate node's dp values based on its children's dp values
            dp[node][0] += max(dp[child][0] , dp[child][1]) ;
        }
    }
    // now we have dp[node][0] filled, we can calculate dp[node][1] by considering matching node with one of its children

    for(auto child : g[node])
    {
        if(child != par)
        {
            // if we match node with child, then we cannot take dp[child][1] (because child is matched), but we can take dp[child][0] (because child is not matched)
            // and for all other children, we can take the maximum of dp[other_child][0] and dp[other_child][1]
            ll matched_with_child = 1 + dp[child][0] ; // 1 for the edge between node and child
            // now add the maximum matching from all other children
            ll other_children_matching = dp[node][0] - max(dp[child][0] , dp[child][1]) ; // subtract the contribution of this child from dp[node][0]
            dp[node][1] = max(dp[node][1] , matched_with_child + other_children_matching) ;
        }
    }
}

void solve() 
{
    ll n ;
    cin >> n ;
    g.resize(n+1) ;
    dp.resize(n+1 , vector < ll > (2 , 0)) ;
    for(ll i = 1 ; i < n ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    dfs(1 , 0) ;
    cout << max(dp[1][0] , dp[1][1]) << endl ; 
    
    


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  