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
/*Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 1000
1 \le x,a_i \le 10^9

Example
Input:
8 15
3 2 5 8 1 3 2 3

Output:
2 4 6 7*/
void solve() 
{
    ll n ;
    cin >> n ;
    ll x ; 
    cin >> x ;
    vector < ll > v(n + 1) ;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
    }
    map < ll , array < ll , 2 > > m ;

    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = i + 1 ; j <= n ; j++)
        {
            m[v[i] + v[j]] = {i , j} ;
            // store the sum of every pair of numbers along with their indices
            // if two pairs have the same sum, we can overwrite the previous pair since we only need one pair for each sum
        }
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = i + 1 ; j <= n ; j++)
        {
            ll sum = v[i] + v[j] ;
            ll rem = x - sum ;
            if(m.find(rem) != m.end())
            {
                ll a = m[rem][0] , b = m[rem][1] ;
                if(a != i && a != j && b != i && b != j)
                {
                    cout << i << " " << j << " " << a << " " << b << endl ;
                    return ;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl ;
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  