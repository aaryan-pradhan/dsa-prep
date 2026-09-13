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
/*Given an array of n integers, your task is to calculate the number of subarrays that have at most k distinct values.
Input
The first input line has two integers n and k.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array.
Output
Print one integer: the number of subarrays.
Constraints

1 \le k \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
5 2
1 2 3 1 1

Output:
10*/
void solve() 
{
    ll n ; 
    cin >> n ;
    ll k ;
    cin >> k ;
    vector < ll > v(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }
    ll t = 0 , h = -1 , ans = 0 ;
    map < ll , ll > freq ;
    while(t < n)
    {
        while( h + 1 < n && (freq.size() < k || (freq.size() == k && freq.find(v[h + 1]) != freq.end())))
        {
            h++ ;
            freq[v[h]]++ ;
        }
        ans += (h - t + 1) ;
        if( t > h)
        {
            t++ ; 
            h = t - 1 ; 
        }
        else 
        {
            freq[v[t]]-- ;
            if(freq[v[t]] == 0)
            {
                freq.erase(v[t]) ;
            }
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
    
  