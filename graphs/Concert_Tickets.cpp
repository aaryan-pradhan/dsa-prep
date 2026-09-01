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
/*There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.
Input
The first input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each ticket.
The last line contains m integers t_1,t_2,\ldots,t_m: the maximum price for each customer in the order they arrive.
Output
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print -1.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le h_i, t_i \le 10^9

Example
Input:
5 3
5 3 7 8 5
4 8 3

Output:
3
8
-1*/
void solve() 
{
    ll n , m ; 
    cin >> n >> m ;
    multiset <ll> h ; 
    for (ll i = 0 ; i < n ; i++)
    {
        ll x ; 
        cin >> x ;
        h.insert(x) ;
    }
    for (ll i = 0 ; i < m ; i++)
    {
        ll x ; 
        cin >> x ;
        auto it = h.upper_bound(x) ;
        // what does this do is that it finds the first element in the multiset that is greater than x. If there is no such element, it returns h.end(). If there is such an element, it returns an iterator to that element.
        if(it == h.begin())
        {
            cout << -1 << endl ;
        }
        else 
        {
            it-- ;
            cout << *it << endl ;
            h.erase(it) ;
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
    
  