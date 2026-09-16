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
/*You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x,a_i \le 10^9

Example
Input:
4 8
2 7 5 1

Output:
2 4*/
void solve() 
{
    ll n , x ; 
    cin >> n >> x ; 
    vector <ll> v(n+1) ;
    map <ll , ll> freq;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
        freq[v[i]] = i ;
    }

    for (ll i = 1 ; i <= n ; i++)
    {
        ll rem = x - v[i] ;
        if(freq[rem] != 0 && freq[rem] != i)
        {
            cout << i << " " << freq[rem] << endl ;
            return ; 
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
    
  