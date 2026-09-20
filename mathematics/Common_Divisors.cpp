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
/*You are given an array of n positive integers. Your task is to find two integers such that their greatest common divisor is as large as possible.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the maximum greatest common divisor.
Constraints

2 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^6

Example
Input:
5
3 14 15 7 9

Output:
7*/
void solve() 
{
    ll n ; 
    cin >> n ;
    vector<ll> a(n) ;
    ll mx = 0 ;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> a[i] ; 
        mx = max(mx , a[i]) ;
    }
    vector < ll > freq(mx + 1 , 0) ;
    for(ll i = 0 ; i < n ; i++)
    {
        freq[a[i]]++ ;
    }
    for(ll i = mx  ; i >= 1 ; i--)
    {
        ll cnt = 0 ; 
        for(ll j = i ; j <= mx ; j += i)
        {
            cnt += freq[j] ;
        }
        if(cnt > 1)
        {
            cout << i << endl;
            return ;
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
    
  