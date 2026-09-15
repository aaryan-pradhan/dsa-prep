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
Your task is to determine for each node the maximum distance to another node.
Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Output
Print n integers: for each node 1,2,\ldots,n, the maximum distance to another node.
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
2 3 2 3 3*/
ll n ; 
vector < vector < ll > > g ;
vector < ll > indp ; 
vector < ll > outdp ;
void dfsin(ll node, ll par)
{
    indp[node] = 0 ;
    // indp[node] = maximum distance from node to any of its descendants
    for(auto child : g[node])
    {
        if(child != par)
        {
            dfsin(child , node) ;
            indp[node] = max(indp[node] , indp[child] + 1) ;
        }
    } 
}
void dfsout(ll node, ll par, ll outval)
{
    // outdp[node] = maximum distance from node to any of its ancestors
    outdp[node] = outval ;
    // here outval is the maximum distance from node to any of its ancestors
    ll mx1 = -1 , mx2 = -1 ;
    for(auto child : g[node])
    {
        if(child != par)
        {
            if(indp[child] >= mx1)
            {
                mx2 = mx1 ;
                mx1 = indp[child] ;
            }
            else if(indp[child] > mx2)
            {
                mx2 = indp[child] ;
            }
        }
    }
    // now we have the maximum and second maximum distances from node's children to its descendants
    
    for(auto child : g[node])
    {
        if(child != par)
        {
            ll use = mx1 ;
            if(indp[child] == mx1)
            {
                use = mx2 ;
            }
            dfsout(child , node , max(outval + 1 , use + 2)) ;
            
        }
    }

}
void solve() 
{
    cin >> n ;
    g.resize(n+1) ;
    indp.resize(n+1) ;
    outdp.resize(n+1) ;
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
        cout << max(indp[i] , outdp[i]) << " " ;
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
    
  