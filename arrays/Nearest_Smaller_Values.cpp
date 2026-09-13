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
/*Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9

Example
Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7*/
void solve() 
{
    ll n ;
    cin >> n ;
    vector < ll > v(n + 1) ;
    for (ll i = 1 ; i <= n ; i++)
    {
        cin >> v[i] ;
    }
    stack < ll > s ; 
    for (ll i = 1 ; i <= n ; i++)
    {
        while(!s.empty() && v[s.top()] >= v[i])
        {
            s.pop() ; 
        }
        if(s.empty())
        {
            cout << 0 << " " ;
        }
        else
        {
            cout << s.top() << " " ;
        }
        s.push(i) ; 
        

    }


    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  