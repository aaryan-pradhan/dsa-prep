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
ll madd(ll a , ll b )
{
    return ( ( a % MOD ) + ( b % MOD ) ) % MOD ; 
}
ll mmul(ll a , ll b )
{
    return ( ( a % MOD ) * ( b % MOD ) ) % MOD ; 
}
vector < vector < ll > > g ; 
vector < ll > d ; 
vector < ll > deg ; 
ll n , c ; 
ll fact[100100]  ;
ll nCr(ll n , ll r )
{
    if( r > n )
    {
        return 0 ; 
    }
    ll ans = fact[n] ; 
    ans = mmul( ans , pow( fact[r] , MOD - 2 ) ) ;
    ans = mmul( ans , pow( fact[n - r] , MOD - 2 ) ) ;
    return ans ; 
}
void dfs(ll node, ll par, ll depth)
{
    d[node] = depth ; 
    for( auto child : g[node] )
    {
        if( child == par )
        {
            continue ; 
        }
        dfs( child , node, depth + 1  ) ; 
    }
    
}
void solve() 
{

    cin >> n >> c ;  
    g.resize( n + 1 ) ;
    deg.resize( n + 1 ) ;
    d.resize( n + 1 ) ;
    for(ll i = 0 ; i < n ; i++ )
    {
        ll x ,  y ; 
        cin >> x >> y ;
        g[x].push_back( y ) ;
        deg[x]++ ;
        deg[y]++ ; 
        
    }
    dfs( 1 , 0 , 0 ) ; 
    vector < ll > leaf ;
    for( ll i = 1 ; i <= n ; i++ )
    {
        if( deg[i] == 1 )
        {
            leaf.push_back( i ) ; 
        }
    }
    for ( auto &x : leaf )
    {
        if( d[x] >= c )
        {
            


            
        }
        
    }





    g.clear() ; 
    deg.clear() ;
    d.clear() ; 
    


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    fact[0] = 1 ;
    for( ll i = 1 ; i < 100100 ; i++ )
    {
        fact[i] = mmul( fact[i - 1] , i ) ;
    }
 
    solve() ; 
}
    
  