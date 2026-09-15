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
/*Given the structure of a company, your task is to calculate for each employee the number of their subordinates.
Input
The first input line has an integer n: the number of employees. The employees are numbered 1,2,\dots,n, and employee 1 is the general director of the company.
After this, there are n-1 integers: for each employee 2,3,\dots,n their direct boss in the company.
Output
Print n integers: for each employee 1,2,\dots,n the number of their subordinates.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
5
1 1 2 3

Output: 4 1 1 0 0*/
vector < vector < ll > > g ;
vector < ll > sts ;
vector < ll > p; 



void dfs(ll node , ll par , ll depth)
{

    sts[node] = 1 ;
    for(auto child : g[node])
    {
        if(child != par)
        {
            dfs(child , node , depth + 1) ;
            sts[node] += sts[child] ;
        }
    } 
}
void solve() 
{
    ll n ;
    cin >> n ;
    g.resize(n+1) ;
    sts.resize(n+1) ;
    p.resize(n+1) ;

    for(ll i = 2 ; i <= n ; i++)
    {
        ll x ;
        cin >> x ;
        g[x].push_back(i) ;
    }
    dfs(1 , 0 , 0) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cout << sts[i] - 1 << " " ;
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
    
  