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
Your task is to process q queries of the form: who is employee x's boss k levels higher up in the hierarchy?
Input
The first input line has two integers n and q: the number of employees and queries. The employees are numbered 1,2,\dots,n, and employee 1 is the general director.
The next line has n-1 integers e_2,e_3,\dots,e_n: for each employee 2,3,\dots,n their boss.
Finally, there are q lines describing the queries. Each line has two integers x and k: who is employee x's boss k levels higher up?
Output
Print the answer for each query. If such a boss does not exist, print -1.
Constraints

1 \le n,q \le 2 \cdot 10^5
1 \le e_i \le i-1
1 \le x \le n
1 \le k \le n

Example
Input:
5 3
1 1 3 3
4 1
4 2
4 3

Output:
3
1
-1*/


void solve() 
{
    ll n , q ;
    cin >> n >> q ;
    vector < vector < ll > > up(n+1 , vector < ll > (25 , 0)) ;
    up[1][0] = 0 ;
    for(ll i = 2 ; i <= n ; i++)
    {
        ll x ;
        cin >> x ;
        up[i][0] = x ;
    }
    for(ll i = 1 ; i <= 20 ; i++)
    {
        for (ll node = 1 ; node <= n ; node++)
        {
            up[node][i] = up[up[node][i-1]][i-1] ;
        }
    }
    while(q--)
    {
        ll x , k ;
        cin >> x >> k ;
        for(ll i = 0 ; i <= 20 ; i++)
        {
            if(k & (1 << i))
            {
                x = up[x][i] ;
                
            }
            if(x == 0) break ;

        }
        if(x == 0) cout << -1 << endl ;
        else cout << x << endl ;
    }
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  