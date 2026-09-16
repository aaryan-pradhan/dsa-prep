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

You are given a rooted tree consisting of n nodes. The nodes are numbered 1,2,\ldots,n, and node 1 is the root. Each node has a value.
Your task is to process following types of queries:

change the value of node s to x
calculate the sum of values in the subtree of node s

Input
The first input line contains two integers n and q: the number of nodes and queries. The nodes are numbered 1,2,\ldots,n.
The next line has n integers v_1,v_2,\ldots,v_n: the value of each node.
Then there are n-1 lines describing the edges. Each line contans two integers a and b: there is an edge between nodes a and b.
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
2 3
1 5 3
2 3

Output:
8
10*/
ll n , q ;
vector < vector < ll > > g;
vector < ll > tin ;
vector < ll > tout ; 
vector < ll > val ;
vector < ll > s ; 
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

struct node{
    ll sum ;
    node()
    {
        sum = 0 ; 
    }
}; 
vector < node > st ; 
node merge(node a, node b)
{
    node res ; 
    res.sum = a.sum + b.sum ; 
    return res ; 
}
void build(ll id, ll l , ll r)
// build both inclusive only
{
    if(l == r)
    {
        st[id].sum = s[l] ; 
        return ; 
    }
    ll mid = l + (r - l) / 2 ;
    build(2 * id , l , mid) ;
    build(2 * id + 1 , mid + 1 , r) ;
    st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
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

node query( ll id , ll l , ll r , ll lq , ll rq)
{
    if(rq < l)
    {
        return node() ; 
    }
    else if(lq > r)
    {
        return node() ; 
    }
    else if(lq <= l && r <= rq)
    {
        return st[id] ; 
    }
    else 
    {
        ll mid = l + (r - l) / 2 ;
        node left = query(2 * id , l , mid , lq , rq) ; 
        node right = query(2 * id + 1 , mid + 1 , r , lq , rq) ;
        return merge(left , right) ;
    }
}
ll encode( ll node)
{
    return tin[node] ; 
}
pll encode_tree(ll node)
{
    return {tin[node] , tout[node]} ; 
}
void solve() 
{
    cin >> n >> q ;
    val.resize(n+1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> val[i] ;
    }
    tin.resize(n+1) ;
    tout.resize(n+1) ;
    g.resize(n+1) ;
    for(ll i = 1 ; i < n ; i++)
    {
        ll x , y ; 
        cin >> x >> y ; 
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }
    s.resize(n+1) ;
    dfs(1 , 0) ;
    st.resize(4 * n + 5) ;
    build(1 , 1 , n) ;
    while(q--)
    {
        ll type ; 
        cin >> type ; 
        if(type == 1)
        {
            ll s , x ; 
            cin >> s >> x ; 
            update(1 , 1 , n , encode(s) , x) ;
        }
        else
        {
            ll s ; 
            cin >> s ; 
            pll enc = encode_tree(s) ;
            node ans = query(1 , 1 , n , enc.fr , enc.sc) ;
            cout << ans.sum << endl ;
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
    
  