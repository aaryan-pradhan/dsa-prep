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
/*There are n apples with known weights. Your task is to divide the apples into two groups so that the difference between the weights of the groups is minimal.
Input
The first input line has an integer n: the number of apples.
The next line has n integers p_1,p_2,\dots,p_n: the weight of each apple.
Output
Print one integer: the minimum difference between the weights of the groups.
Constraints

1 \le n \le 20
1 \le p_i \le 10^9

Example
Input:
5
3 2 7 4 1

Output:
1

Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).*/
ll n ; 
ll ans ; 
vector < ll > v ;
void rec(ll i , ll mask)
{
    if(i == n)
    {
        ll sum1 = 0 , sum2 = 0 ; 
        for(ll j = 0 ; j < n ; j++)
        {
            if(mask & (1 << j))
            {
                sum1 += v[j] ;
            }
            else
            {
                sum2 += v[j] ;
            }
        }
        ans = min(ans , abs(sum1 - sum2)) ;
        return ;
    }
    rec(i + 1 , mask | (1 << i)) ;
    rec(i + 1 , mask) ;
}
void solve() 
{

    cin >> n ;
    for(ll i = 0 ; i < n ; i++)
    {
        ll x ; 
        cin >> x ; 
        v.push_back(x) ;
    }
    ans = INF ;
    rec(0 , 0) ;
    cout << ans << endl ;


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  