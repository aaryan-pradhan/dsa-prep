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
Your task is to determine for each node the sum of the distances from the node to all other nodes.
Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print n integers: for each node 1,2,\ldots,n, the sum of the distances.
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
6 9 5 8 8*/
ll n ; 
vector < vector < ll > > g ;
vector < ll > indp ;
vector < ll > outdp ;
vector < ll > sts ;
void dfsin(ll node, ll par)
{
    indp[node] = 0 ;
    sts[node] = 1 ;

    // indp[node] = sum of distances from node to all its descendants
    for(auto child : g[node])
    {
        if(child != par)
        {
            dfsin(child , node) ;
            indp[node] += (indp[child] + sts[child]) ;
            sts[node] += sts[child] ;
        }
    } 
}
void dfsout(ll node, ll par, ll outval)
{
    // outdp[node] = sum of distances from node to all the other nodes in the tree that are not in the subtree rooted at node
    outdp[node] = outval ;
    // here outval is the sum of distances from node to all the other nodes in the tree that are not in the subtree rooted at node
    for(auto child : g[node])
    {
        if(child != par)
        {
            ll use = outval + ( n - sts[node] ) ; 
            use += (indp[node] - (indp[child] + sts[child])) + (sts[node] - sts[child]) ;
            dfsout(child , node , use) ;
        }
    }
}
void solve() 
{

    cin >> n ;
    g.resize(n+1) ;
    indp.resize(n+1) ;
    outdp.resize(n+1) ;
    sts.resize(n+1) ;
    for(ll i = 1 ; i <= n-1 ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    dfsin(1 , 0) ;
    dfsout(1 , 0 , 0) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cout << indp[i] + outdp[i] << " " ;
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
    
  