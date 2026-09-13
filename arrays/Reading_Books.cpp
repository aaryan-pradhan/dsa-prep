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
/*There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.
They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?
Input
The first input line has an integer n: the number of books.
The second line has n integers t_1,t_2,\dots,t_n: the time required to read each book.
Output
Print one integer: the minimum total time.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le t_i \le 10^9

Example
Input:
3
2 8 3

Output:
16*/
void solve() 
{
    ll n ; 
    cin >> n ; 
    ll s = 0 , m = 0 ;
    for (ll i = 0 ; i < n ; i++)
    {
        ll x ; 
        cin >> x ; 
        s += x ; 
        m = max(m , x) ; 
    }
    cout << max(s , 2 * m) << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  