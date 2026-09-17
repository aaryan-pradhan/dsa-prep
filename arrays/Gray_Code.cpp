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
/*A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
Input
The only input line has an integer n.
Output
Print 2^n lines that describe the Gray code. You can print any valid solution.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
00
01
11
10*/
void solve() 
{
    ll n ; 
    cin >> n ;
    vector < string > v = {"0", "1"} ;
    for(ll i = 2 ; i <= n ; i++)
    {
        vector < string > temp ;
        for(ll j = 0 ; j < v.size() ; j++)
        {
            temp.push_back("0" + v[j]) ;
        }
        for(ll j = v.size() - 1 ; j >= 0 ; j--)
        {
            temp.push_back("1" + v[j]) ;
        }
        v = temp ;

    }
    for(auto& x : v)
    {
        cout << x << endl ;
    }






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  