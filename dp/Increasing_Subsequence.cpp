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

You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.
A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements.
Input
The first line contains an integer n: the size of the array.
After this there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print the length of the longest increasing subsequence.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
8
7 3 5 3 6 2 9 8

Output:
4*/
// ll rec(ll i , ll prev)
// {
//     // this returns the length of the longest increasing subsequence from index i to n - 1 with previous element as prev
//     if(i == n) return 0 ;
//     if(dp[i][p] != -1) return dp[i][prev] ;
//     ll ans = rec(i + 1 , prev ) ;
//     if(a[i] > prev)
//     {
//         ans = max(ans , 1 + rec(i + 1 , a[i] ) ) ;
//     }
//     return dp[i][prev] = ans ;
//     // but this would take O(n^2) time and O(n^2) space which is not feasible for n = 2 * 10^5
// }

void solve() 
{
    
   ll n ; 
   cin >> n ; 
   vector <ll> a(n) ;
   for(ll i = 0 ; i < n ; i++)
   {
        cin >> a[i] ;
   }
   vector <ll> dp ;
   // dp [k] is smallest value that can be the last element of an increasing subsequence of length k + 1
   for(ll i = 0 ; i < n ; i++)
   {
        auto it = lower_bound(dp.begin() , dp.end() , a[i] ) ;
        // this returns the first element in dp which is greater than or equal to a[i]
        // if there is no such element then it returns dp.end()
        // if there is such an element that is greater than or equal to a[i] then we can replace that element with a[i] to get a better increasing subsequence
        if(it == dp.end())
        {
            dp.push_back(a[i]) ;
        }
        else 
        {
            *it = a[i] ;
        }

   }
   cout << dp.size() << endl ;
    // LIS IN NlogN time complexity
    




}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  