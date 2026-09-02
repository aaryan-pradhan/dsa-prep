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

Given n ranges, your task is to count for each range how many other ranges it contains and how many other ranges contain it.
Range [a,b] contains range [c,d] if a \le c and d \le b.
Input
The first input line has an integer n: the number of ranges.
After this, there are n lines that describe the ranges. Each line has two integers x and y: the range is [x,y].
You may assume that no range appears more than once in the input.
Output
First print a line that describes for each range (in the input order) how many other ranges it contains.
Then print a line that describes for each range (in the input order) how many other ranges contain it.
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
2 0 0 0
0 1 0 1*/
void solve() 
{
    ll n ; 
    cin >> n ; 
    vector < pair < pll , ll >> v(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        ll x , y ; 
        cin >> x >> y ;
        v[i] = {{x, y}, i} ;
    }
    sort(v.begin(), v.end(), [](pair<pll, ll> a , pair<pll, ll> b)
    {
        if(a.fr.fr == b.fr.fr)
        {
            return a.fr.sc > b.fr.sc ;
            // if the starting points are equal, we want to sort by the ending point in descending order. This is because if two ranges start at the same point, the one that ends later will contain the one that ends earlier. By sorting in this way, we can easily count how many ranges each range contains and how many ranges contain it.
        }
        return a.fr.fr < b.fr.fr ;
        // otherwise, we sort by the starting point in ascending order. This is because we want to process the ranges in the order of their starting points, so that we can keep track of the ranges that are currently active and count how many ranges each range contains and how many ranges contain it.
    });
    vector <ll> ans1(n, 0) ;
    vector <ll> ans2(n, 0) ;
    // 
    for (ll i = 0 ; i < n ; i++)
    {


    }

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  