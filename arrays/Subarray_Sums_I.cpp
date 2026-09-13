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
/*Given an array of n positive integers, your task is to count the number of subarrays having sum x.
Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.
Output
Print one integer: the required number of subarrays.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x,a_i \le 10^9

Example
Input:
5 7
2 4 1 2 7

Output:
3*/
void solve() 
{
    ll n ; 
    cin >> n ;
    ll x ; 
    cin >> x ;
    vector < ll > v(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }
    ll  t = 0 , h = -1 , sum = 0 , ans = 0 ;
    while(t < n)
    {
        while(h + 1 < n && sum + v[h + 1] <= x)
        {
            h++ ;
            sum += v[h] ;
        }
        if(sum == x)
        {
            ans++ ;
        }
        if (  t > h )
        {
            h = t - 1 ;
            t++ ; 
        }
        else
        {
            sum -= v[t] ;
            t++ ;
        }
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
    
  