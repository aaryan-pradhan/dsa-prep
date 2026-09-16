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
/*In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you can watch entirely?
Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Example
Input:
3
3 5
4 9
5 8

Output:
2*/
void solve() 
{
    ll n ; 
    cin >> n ;
    vector <pll> v(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> v[i].fr >> v[i].sc ;
    }
    sort(v.begin(), v.end(), [](pll a , pll b)
    {
        return a.sc < b.sc ;
    });
    ll ans = 0 ;
    ll last = 0 ;
    for (ll i = 0 ; i < n ; i++)
    {
        if(v[i].fr >= last)
        {
            ans++ ;
            last = v[i].sc ;
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
    
  