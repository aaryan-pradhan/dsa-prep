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
#define pn cout << "IMPOSSIBLE" << endl
#define pll pair<ll,ll>

using namespace std;
/*Time limit: 1.00 s
Memory limit: 512 MB

There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.
Input
The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,\dots,n.
Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.
Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.
Output
Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2




*/
ll n , m ;
vector<vector<ll>> g ;
vector<ll> vis ;
void dfs(ll node , ll col)
{
    vis[node] = col ;
    for(auto child : g[node])
    {
        if(!vis[child])
        {
            dfs(child, 3 - col) ;
        }
        else if(vis[child] == col)
        {
            pn ; 
            exit(0) ;
        }


    }
}
void solve() 
{
    cin >> n >> m ;
    g.resize(n + 1) ;
    vis.resize(n + 1, 0) ;
    for(ll i = 0 ; i < m ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;

    }
    for(ll i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            dfs(i, 1) ;
        }
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        cout << vis[i] << " " ;
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
    
  