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
/*A game has n planets, connected by m teleporters. Two planets a and b belong to the same kingdom exactly when there is a route both from a to b and from b to a. Your task is to determine for each planet its kingdom.
Input
The first input line has two integers n and m: the number of planets and teleporters. The planets are numbered 1,2,\dots,n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: you can travel from planet a to planet b through a teleporter.
Output
First print an integer k: the number of kingdoms. After this, print for each planet a kingdom label between 1 and k. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 6
1 2
2 3
3 1
3 4
4 5
5 4

Output:
2
1 1 1 2 2*/
ll n , m ;
vector < vector < ll > >  g ; 
vector < vector < ll > > rg ;
vector < ll > vis ;
vector < ll > order ;

void dfsg(ll node)
{
    vis[node] = 1 ; 
    for(auto child : g[node])
    {
        if(!vis[child])
        {
            dfsg(child) ; 
        }
    }
    order.push_back(node) ;
}
void dfsrg(ll node, ll col)
{
    vis[node] = col ; 
    for(auto child : rg[node])
    {
        if(!vis[child])
        {
            dfsrg(child, col) ; 
        }
    }
}
void solve() 
{

   cin >> n >> m ;
   g.resize(n+1) ;
   rg.resize(n+1) ;
   vis.assign(n+1 , 0) ;
   for(ll i = 0 ; i < m ; i++)
   {
        ll a , b ;
        cin >> a >> b ;
        g[a].push_back(b) ; 
        rg[b].push_back(a) ; 
   }
   for(ll i = 1 ; i <= n ; i++)
   {
        if(!vis[i])
        {
            dfsg(i) ; 
        }
   }
   vis.assign(n+1 , 0) ;
   ll col = 0 ; 
   while(!order.empty())
   {
        ll node = order.back() ;
        order.pop_back() ;
        if(!vis[node])
        {
            col++ ; 
            dfsrg(node , col) ; 
        }
   }
   cout << col << endl ;
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
    
  