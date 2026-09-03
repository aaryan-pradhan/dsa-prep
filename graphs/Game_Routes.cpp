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
vector<vector<ll>> g ; 
/*Time limit: 1.00 s
Memory limit: 512 MB

A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?
Input
The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1,2,\dots,n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.
Output
Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 10^9+7.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 5
1 2
2 4
1 3
3 4
1 4

Output:
3*/
// ll rec(ll node)
// {
//     if(node == n)
//     {
//         return 1 ; 
//     }
//     if(dp[node] != -1)
//     {
//         return dp[node] ; 
//     }
//     ll ans = 0 ; 
//     for(auto child : g[node])
//     {
//         ans = madd(ans , rec(child)) ; 
//     }
//     return dp[node] = ans ;
// }
ll madd(ll a , ll b)
{
    return (a%MOD + b%MOD)%MOD ; 
}
void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector<vector<ll>> g(n+1) ;
    vector<ll> indeg(n+1 , 0) ;
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b ;
        cin >> a >> b ;
        g[a].push_back(b) ; 
        indeg[b]++ ;
    }
    queue<ll> q ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i) ; 
        }
    }
    vector <ll> topo ;
    while(!q.empty())
    {
        ll v = q.front() ; 
        q.pop() ; 
        topo.push_back(v) ; 
        for(auto u : g[v])
        {
            indeg[u]-- ; 
            if(indeg[u] == 0)
            {
                q.push(u) ; 
            }
        }
    }
    vector<ll> dp(n+1 , 0) ;
    reverse(topo.begin() , topo.end()) ;
    for(auto node:topo)
    {
        if(node == n)
        {
            dp[node] = 1 ; 
            continue ;
        }
        ll ans = 0 ;
        for(auto child : g[node])
        {
            ans = madd(ans , dp[child]) ;
        }
        dp[node] = ans ;

    }
    cout << dp[1] << endl ;


   







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    