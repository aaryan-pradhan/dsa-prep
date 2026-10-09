/*
 * D. Treelabeling (Codeforces)
 * Time limit: 2 seconds, Memory limit: 256 megabytes
 *
 * Eikooc and Sushi play a game on a tree with n nodes. 
 * They take turns moving a token to an adjacent, unvisited node u from the current node v 
 * such that u ⊕ v <= min(u, v). The player unable to make a move loses.
 * Both players play optimally. Eikooc places the token first.
 * Eikooc relabels the tree with a permutation p of length n before the game begins.
 * She wants to maximize the number of starting nodes that guarantee her a win.
 * 
 * Find any relabeling that maximizes the number of winning starting nodes for Eikooc.
 */
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
vector < vector < ll > > graph;

void dfs(ll n , ll p , ll c , vector < ll > &col)
{
    col[n] = c ;
    for(auto ch : graph[n])
    {
        if(ch != p)
        {
            dfs(ch , n , 3 - c , col) ;
        }
    }
}

// assign node to colour c 

void solve() 
{
    ll n ;
    cin >> n ;
    graph.assign(n + 1 , vector < ll > ()) ;
    for(ll i = 1 ; i < n ; i++)
    {
        ll u , v ;
        cin >> u >> v ;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }
    vector < ll > col(n + 1 , 0) ;
    dfs(1 , 0 , 1 , col) ;
    vector < ll > c1 , c2 ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(col[i] == 1)
        {
            c1.push_back(i) ;
        }
        else
        {
            c2.push_back(i) ;
        }
    }
    if(c1.size() > c2.size())
    {
        swap(c1 , c2) ;
    }
    ll S = c1.size() ;

    
    
    vector < ll > p(n + 1 , 0) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        ll posmsb = log2(i) ;

        if ((S >> posmsb) & 1)
        {
            p[c1.back()] = i ;
            c1.pop_back() ;
        }
        else
        {

            p[c2.back()] = i ;
            c2.pop_back() ;
        }
        
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        cout << p[i] << " " ;
    }
    cout << endl ;
    

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;
    while(t--)
    {
        solve() ; 
    }
}
    
  