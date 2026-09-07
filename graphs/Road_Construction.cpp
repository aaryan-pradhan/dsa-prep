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
/*There are n cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number of components and the size of the largest component.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the new roads. Each line has two integers a and b: a new road is constructed between cities a and b.
You may assume that every road will be constructed between two different cities.
Output
Print m lines: the required information after each day.
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
4 2
3 3
2 3*/
struct UnionFind{
    ll n , *parent , *rank , setsz , maxsz; 
    UnionFind()
    {
        n = setsz = 0 ;
        parent = nullptr ; 
        rank = nullptr ; 
        maxsz = 0 ;
    }
    UnionFind(ll a)
    {
        n = setsz = a ; 
        parent = new ll[a+1] ;
        rank = new ll[a+1] ; 
        for(ll i = 1 ; i <= a ; i++)
        {
            parent[i] = i ; 
            rank[i] = 1 ; 
        }
        maxsz = 1 ;
    }
    ll find(ll x)
    {
        if(parent[x] == x)
        {
            return x ; 
        }
        return parent[x] = find(parent[x]) ; 
    }
    void merge(ll x , ll y)
    {
        x = find(x) ; 
        y = find(y) ; 
        if(x == y)
        {
            return ; 
        }
        if(rank[x] < rank[y])
        {
            swap(x , y) ; 
        }
        // this ensures that the larger set is always the parent of the smaller set, which helps to keep the tree flat and improves the efficiency of the union-find operations.
        parent[y] = x ; 
        rank[x] += rank[y] ; 
        maxsz = max(maxsz , rank[x]) ; 
        setsz-- ; 
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
    ll max_size()
    {
        return maxsz ; 
    }
};
void solve() 
{
    ll n , m ; 
    cin >> n >> m ; 
    UnionFind uf(n) ; 
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b ; 
        cin >> a >> b ; 
        uf.merge(a , b) ; 
        cout << uf.sets() << " " << uf.max_size() << endl ; 
    }
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  