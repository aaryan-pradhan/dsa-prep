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
// dsu
struct UnionFind{
    ll n , *parent , *rank , max_size ;
    UnionFind()
    {
        n = 0 ;
        parent = NULL ;
        rank = NULL ;
        max_size = 0 ;
    }
    UnionFind(ll a )
    {
        n = a ; 
        parent = new ll [ a + 1] ; 
        rank = new ll [ a + 1] ;
        for(ll i = 1 ; i <= a ; i++)
        {
            parent[i] = i ;
            rank[i] = 1 ;
        }
        max_size = 1 ;
    }
    ll find(ll a)
    {
        if(parent[a] == a)
        {
            return a ;
        }
        else
        {
            return parent[a] = find(parent[a]) ;
        }
    }
    void merge(ll x , ll y)
    {
        x = find(x) ;
        y = find(y) ;
        if( x == y)
        {
            return ;
        }
        if(rank[x] < rank[y])
        {
            swap(x,y) ;
        }
        parent[y] = x ;
        rank[x] += rank[y] ;
        max_size = max(max_size , rank[x]) ;
    }
    ll maxsize_()
    {
        return max_size ;
    }
}
void solve() 
{
    ll n , q ; 
    cin >> n >> q ;
    UnionFind dsu(n) ;
    for(ll i = 0 ; i < q ; i++)
    {

    }
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  