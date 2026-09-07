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


#define pll pair<ll,ll>

using namespace std;
/*Time limit: 1.00 s
Memory limit: 128 MB

There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.
Output
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Output:
14
*/
struct UnionFind{
    ll n , *parent , *rank , setsz ; 
    UnionFind()
    {
        n = setsz = 0 ; 
        parent = nullptr ; 
        rank = nullptr ; 
    }
    UnionFind(ll a)
    {
        n = setsz = a ; 
        parent = new ll[a+1] ; 
        rank = new ll[a+1] ; 
        for(ll i = 1 ; i <= a ; i++ )
        {
            parent[i] = i ; 
            rank[i] = 1 ;
            // rank is the size of the set that the node belongs to
        }

    }
    ll find(ll x)
    {
        if( x != parent[x] )
        {
            return parent[x] = find(parent[x]) ; 
        }
        else 
        {
            return x ; 
        }
    }
    void merge( ll x , ll y)
    {
        ll parx = find(x) ; 
        ll pary = find(y) ;
        if(parx == pary)
        {
            return ; 
        }
        if(parx != pary)
        {
            if(rank[parx] >= rank[pary])
            {
                parent[pary] = parx ; 
                rank[parx] += rank[pary] ; 
                // this ensures that the smaller set is merged into the larger set, which helps to keep the tree flat and improves the efficiency of future find operations.
            }
            else
            {
                parent[parx] = pary ; 
                rank[pary] += rank[parx] ; 
            }
            setsz-- ; 
        }
    }
    bool connected(ll x , ll y)
    {
        return find(x) == find(y) ; 
    }
    ll size(ll x)
    {
        return rank[find(x)] ; 
    }
    ll sets()
    {
        return setsz ; 
    }

};

void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector < pair < pll , ll > > edges ; 
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b , c ; 
        cin >> a >> b >> c ; 
        edges.push_back({{a , b} , c}) ; 
    }
    sort(edges.begin() , edges.end() , [](pair<pll,ll> a , pair<pll,ll> b)
    {
        return a.second < b.second ; 
    }) ;
    UnionFind uf(n) ;
    ll ans = 0 ; 
    for(auto edge : edges)
    {
        ll a = edge.fr.fr ; 
        ll b = edge.fr.sc ; 
        ll c = edge.sc ; 
        if(!uf.connected(a , b))
        {
            uf.merge(a , b) ; 
            ans += c ; 
        }
    }
    if(uf.sets() > 1)
    {
        cout << "IMPOSSIBLE" << endl ; 
    }
    else
    {
        cout << ans << endl ; 
    }


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  