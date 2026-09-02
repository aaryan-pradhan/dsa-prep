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
/*You have to complete n courses. There are m requirements of the form "course a has to be completed before course b". Your task is to find an order in which you can complete the courses.
Input
The first input line has two integers n and m: the number of courses and requirements. The courses are numbered 1,2,\dots,n.
After this, there are m lines describing the requirements. Each line has two integers a and b: course a has to be completed before course b.
Output
Print an order in which you can complete the courses. You can print any valid order that includes all the courses.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
3 1
4 5

Output:
3 4 1 5 2*/

void solve() 
{
    ll n , m ;
    cin >> n >> m ; 
    vector < vector <ll>> g(n + 1) ;
    vector < ll > vis(n + 1, 0) ;
    vector < ll > indeg(n + 1, 0) ;
    for (ll i = 0 ; i < m ; i++)
    {
        ll a , b ; 
        cin >> a >> b ;
        g[a].push_back(b) ;
        indeg[b]++ ;
    }
    queue <ll> q ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i) ;
        }
    }
    vector <ll > topo ;
    while(!q.empty())
    {
        ll node = q.front() ;
        q.pop() ;
        topo.push_back(node) ;
        for(auto child : g[node])
        {
            indeg[child]-- ;
            if(indeg[child] == 0)
            {
                q.push(child) ;
            }
        }
    }
    if(topo.size() != n)
    {
        cout << "IMPOSSIBLE" << endl ;
        return ; 
    }
    else 
    {
        for(auto x : topo)
        {
            cout << x << " " ;
        }
        cout << endl ;
    }
    



    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  