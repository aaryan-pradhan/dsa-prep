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
/*Given an array of n integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le x,a_i \le 10^9

Example
Input:
5 7
2 -1 3 5 -2

Output:
2*/
void solve() 
{
    ll n ; 
    cin >> n ;
    ll x ;
    cin >> x ;
    vector < ll > pre(n + 1) ;
    vector < ll > v(n + 1) ;
    pre[0] = 0 ;
    for(ll i = 1 ; i <= n ; i++)
    {
       cin >> v[i] ;
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        pre[i] = pre[i - 1] + v[i] ;
    }
    map < ll , ll > freq ; 
    ll ans = 0 ;
    for(ll i = 0 ; i <= n ; i++)
    {

        if(freq.find(pre[i] - x) != freq.end())
        {
            ans += freq[pre[i] - x] ;
        }
        freq[pre[i]]++ ;

    }
    cout << ans << endl ;

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  