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

You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
Input
The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print one integer: the maximum sum in a subarray in the optimal division.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le k \le n
1 \le x_i \le 10^9

Example
Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8. The largest sum is the last sum 8.*/
ll check(ll mid, const vector < ll > &v, const ll &n, const ll &k)
{
    // check if we can divide the array into k such that the maximum sum in a subarray is less than or equal to mid
    ll sum = 0 , cnt = 1 ;
    for(ll i = 0 ; i < n ; i++)
    {
        if(v[i] > mid)
        {
            return false ;
        }
        else 
        {
            if(sum + v[i] > mid)
            {
                cnt++ ;
                sum = v[i] ;
            }
            else
            {
                sum += v[i] ;
            }
        }
        
    }
    if( cnt <= k)
    {
        return true ;
    }
    else
    {
        return false ;
    }
    
}
void solve() 
{
    ll n , k ; 
    cin >> n >> k ; 
    vector < ll > v(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }
    ll l = 1 , r = 1e18 , ans = 0 ;
    while(l <= r)
    {
        ll mid = l + (r - l) / 2 ;
        if(check(mid, v, n, k))
        {
            ans = mid ;
            r = mid - 1 ;
        }
        else
        {
            l = mid + 1 ;
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
    
  