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
/*There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.
What is the maximum amount of money you can earn?
Input
The first input line contains an integer n: the number of projects.
After this, there are n lines. Each such line has three integers a_i, b_i, and p_i: the starting day, the ending day, and the reward.
Output
Print one integer: the maximum amount of money you can earn.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a_i \le b_i \le 10^9
1 \le p_i \le 10^9

Example
Input:
4
2 4 4
3 6 6
6 8 2
5 7 3

Output:
7*/
// ll rec(ll i )
// {
//     // this returns the maximum amount of money that can be earned from project i to n - 1 if you have already completed all projects before i
//     if(i == n) return 0 ;
//     if(dp[i] != -1) return dp[i] ;
//     ll ans = rec(i + 1 ) ;
//     ll ans = max(ans , p[i] + rec(next[i] ) ) ;
//     // here next[i] is the index of the next project that can be attended after project i; that is the first project whose starting day is greater than the ending day of project i
//     return dp[i] = ans ;
// }
void solve() 
{
    ll n ; 
    cin >> n ;
    vector <pair<pll,ll>> p(n) ;
    for(ll i = 0 ; i < n ; i++)
    {
        ll s , e , m ; 
        cin >> s >> e >> m ;
        p[i] = {{s , e} , m } ;
    }
    sort(p.begin() , p.end() , [&](const pair<pll,ll> &a , const pair<pll,ll> &b)
    {
        ll as = a.fr.fr , ae = a.fr.sc , am = a.sc ;
        ll bs = b.fr.fr , be = b.fr.sc , bm = b.sc ;
        if(as == bs) return ae < be ;
        return as < bs ;
    }) ;
    vector <ll> next(n + 1 , n ) ;
    for(ll i = n ; i >= 0 ; i--)
    {
        if(i == n)
        {
            next[i] = n ;
            continue ;
        }
        ll s = p[i].fr.fr , e = p[i].fr.sc , m = p[i].sc ;
        ll lo = i + 1 , hi = n - 1  , ans = n ;
        while(lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2 ;
            ll ms = p[mid].fr.fr , me = p[mid].fr.sc , mm = p[mid].sc ;
            if(ms > e)
            {
                ans = mid ; 
                hi = mid - 1 ;
            }
            else 
            {
                lo = mid + 1 ;
            }
        }
        next[i] = ans ;
        
    }
    vector <ll> dp(n + 1 , 0 ) ;
    for(ll i = n ; i >= 0 ; i--)
    {
        if(i == n)
        {
            dp[i] = 0 ;
            continue ;
        }
        ll ans = dp[i + 1] ;
        ans = max(ans , p[i].sc + dp[next[i]] ) ;
        dp[i] = ans ;
    }
    cout << dp[0] << endl ;


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  