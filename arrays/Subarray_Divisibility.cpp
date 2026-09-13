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
/*iven an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
Input
The first input line has an integer n: the size of the array.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le a_i \le 10^9

Example
Input:
5
3 1 2 7 4

Output:
1*/
void solve() 
{
    ll n ; 
    cin >> n ;
    vector < ll > pre(n + 1) ;
    vector < ll > v(n + 1) ;
    pre[0] = 0 ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
        pre[i] = pre[i - 1] + v[i] ;
    }
    vector < ll > freq(n, 0) ;
    ll ans = 0 ;
    ll sum = 0 ;
    for(ll i = 0 ; i <= n ; i++)
    {
        sum = (pre[i] % n + n) % n ;
        if(freq[sum] > 0)
        {
            ans += freq[sum] ;
        }
        freq[sum]++ ;
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
    
  