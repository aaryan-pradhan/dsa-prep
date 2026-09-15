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
/*A company has n employees, who form a tree hierarchy where each employee has a boss, except for the general director.
Your task is to process q queries of the form: who is the lowest common boss of employees a and b in the hierarchy?
Input
The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,\dots,n, and employee 1 is the general director.
The next line has n-1 integers e_2,e_3,\dots,e_n: for each employee 2,3,\dots,n their boss.
Finally, there are q lines describing the queries. Each line has two integers a and b: who is the lowest common boss of employees a and b?
Output
Print the answer for each query.
Constraints

1 \le n,q \le 2 \cdot 10^5
1 \le e_i \le i-1
1 \le a,b \le n

Example
Input:
5 3
1 1 3 3
4 5
2 5
1 4

Output:
3
1
1*/
vector < vector < ll > > g; 
vector < ll > d ; 
vector < vector < ll > > up ;
void dfs(ll node , ll parent, ll depth)
{
    d[node] = depth ; 
    for (auto child : g[node])
    {
        if (child != parent)
        {
            dfs(child , node , depth + 1) ; 
        }
    }
}
void solve() 
{
    ll n , q ; 
    cin >> n >> q ;
    g.resize(n+1) ;
    d.resize(n+1) ;
    up.resize(n+1 , vector < ll > (20 , 0)) ;

    for (ll i = 2 ; i <= n ; i++)
    {
        ll x ;
        cin >> x ;
        g[x].push_back(i) ;
        g[i].push_back(x) ;
        up[i][0] = x ;
    }
    dfs(1 , 0 , 0) ;

    // binary lifting
    for(ll sa = 1 ; sa < 20 ; sa++)
    {
        for(ll node = 1 ; node <= n ; node++)
        {
            up[node][sa] = up[up[node][sa-1]][sa-1] ;
        }
    }

    while(q--)
    {
        ll a , b ; 
        cin >> a >> b ; 
        if (d[a] < d[b]) swap(a , b) ; 
        // a is deeper than b
        // lift a to the same depth as b
        ll diff = d[a] - d[b] ;
        for(ll sa = 0 ; sa < 20 ; sa++)
        {
            if (diff & (1 << sa))
            {
                a = up[a][sa] ;
            }
        }
        for(ll sa = 19 ; sa >= 0 ; sa--)
        {
            // if the ancestor 2^sa edges away towards root for a and 2^sa edges away towards root for b are different, then we can lift both a and b to their respective ancestors
            if (up[a][sa] != up[b][sa])
            {
                a = up[a][sa] ;
                b = up[b][sa] ;
            }
            // if the ancestore 2^sa edges away from a and 2^sa edges away from b are the same, then we cannot lift both a and b to their respective ancestors, because they will be the same, so we continue to the next sa which is smaller that is we have overshot our target 
            else
            {
                continue ; 
            }
        }
        // now a and b are at the same depth and their ancestors 2^sa edges away towards root are the same, so we can lift both a and b to their respective ancestors which are the same, so we can return either a or b as the answer
        if(a == b)
        {
            cout << a << endl ; 
        }
        // if a and b are not the same, then we can return their parent as the answer
        // why is the parent of a and b the lowest common boss of a and b? because we have lifted both a and b to their respective ancestors which are the same, so their parent is the lowest common boss of a and b
        else if(up[a][0] == up[b][0])
        {
            a = up[a][0] ;
            cout << a << endl ;
        }
        else 
        {
             cout << "Pranjal is Gay" << endl ;
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
    
  