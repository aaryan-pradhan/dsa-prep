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
/*Given n ranges, your task is to determine for each range if it contains some other range and if some other range contains it.
Range [a,b] contains range [c,d] if a \le c and d \le b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) if it contains some other range (1) or not (0).
Then print a line that describes for each range (in the input order) if some other range contains it (1) or not (0).
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x < y \le 10^9

Example
Input:
4
1 6
2 4
4 8
3 6

Output:
1 0 0 0
0 1 0 1*/
void solve() 
{
    ll n ; 
    cin >> n ;
    vector < pair < pll , ll > > v(n) ;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> v[i].fr.fr >> v[i].fr.sc ;
        v[i].sc = i ;
    }
    sort(v.begin() , v.end() , [&](pair < pll , ll > a , pair < pll , ll > b)
    {
        if(a.fr.fr != b.fr.fr) return a.fr.fr < b.fr.fr ;
        return a.fr.sc > b.fr.sc ;
    });
    ll maxr = -1 ;
    vector < ll > ans1(n) ;
    for(ll i = 0 ; i < n ; i++)
    {
        ll curr = v[i].fr.sc ;
        ll curridx = v[i].sc ;
        if(curr <= maxr) ans1[curridx] = 1 ;
        maxr = max(maxr , curr) ;
    }
    vector < ll > ans2(n) ;
    ll minr = INF ; 
    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        ll curr = v[i].fr.sc ;
        ll curridx = v[i].sc ;
        if(curr >= minr) ans2[curridx] = 1 ;
        minr = min(minr , curr) ;
    }

    for(ll i = 0 ; i < n ; i++) cout << ans2[i] << " " ;
    cout << endl ;
    for(ll i = 0 ; i < n ; i++) cout << ans1[i] << " " ;
    cout << endl ;  



    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  