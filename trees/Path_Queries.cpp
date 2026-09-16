// orz
#include <bits/stdc++.h>
#include "algodebug.h"
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

You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,\ldots,n, and node 1 is the root. Each node has a value.
Your task is to process following types of queries:

change the value of node s to x
calculate the sum of values on the path from the root to node s

Input
The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,\ldots,n.
The next line has n integers v_1,v_2,\ldots,v_n: the value of each node.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
Finally, there are q lines describing the queries. Each query is either of the form "1 s x" or "2 s".
Output
Print the answer to each query of type 2.
Constraints

1 \le n, q \le 2 \cdot 10^5
1 \le a,b, s \le n
1 \le v_i, x \le 10^9

Example
Input:
5 3
4 2 5 2 1
1 2
1 3
3 4
3 5
2 4
1 3 2
2 4

Output:
11
8*/
ll n , q ;
vector < vector < ll > > g;
vector < ll > tin ;
vector < ll > tout ;
vector < ll > val ;
vector < ll > s ; 
vector < stnode > st ; 
ll timer = 1 ; 
void dfs(ll node , ll parent)
{
    tin[node] = timer ; 
    s[timer] = val[node] ;
    timer++ ;
    for (auto child : g[node])
    {
        if (child != parent)
        {
            dfs(child , node) ; 
        }
    }
    tout[node] = timer - 1 ; 
}
ll encode(ll node)
{
    return tin[node] ; 
}
pll encode_tree(ll node)
{
    return {tin[node] , tout[node]} ; 
}
struct stnode{
    ll sum ; 
    stnode()
    {
        sum= 0 ; 
    }

};
stnode merge(stnode a , stnode b)
{
    stnode res ;
    res.sum = a.sum + b.sum ;
    return res ;
}
void update(ll id , ll l , ll r , ll pos , ll val)
{
    if(pos < l || pos > r)
    {
        return ; 
    }
    else if(l == r && l == pos)
    {
        st[id].sum = val ;
        return ; 
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        update(2 * id , l , mid , pos , val) ; 
        update(2 * id + 1 , mid + 1 , r , pos , val) ;
        st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
    }
    
}
void query
void solve() 
{
    
    cin >> n >> q ;
    val.resize(n+1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> val[i] ;
    }
    for(ll i = 1 ; i < n ; i++)
    {
        ll x , y ; 
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    tin.resize(n+1) ;
    tout.resize(n+1) ;
    st.resize(4 * n + 5) ;
    dfs(1 , 0) ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  