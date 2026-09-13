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
/*A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le t \le 10^9
1 \le k_i \le 10^9

Example
Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.*/
ll check(ll x, vector<ll> &v, ll t) 
{
    // check if we can make atleast t products in x seconds
    ll total = 0 ;
    for (ll i = 0; i < v.size(); i++)
    {
        total += (x / v[i]) ;
        if (total >= t) 
        {
            return true ;
        }
    }
    
    return false;
}
void solve() 
{

    ll n ; 
    cin >> n ;
    ll t ;
    cin >> t ;
    vector<ll> v(n) ;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i] ;
    }
    ll lo = 1, hi = 1e18, ans = -1 ;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2 ;
        if (check(mid, v, t)) 
        {
            ans = mid ;
            hi = mid - 1 ;
        }
        else 
        {
            lo = mid + 1 ;
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
    
  