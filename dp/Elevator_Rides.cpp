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
/*There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides?
Input
The first input line has two integers n and x: the number of people and the maximum allowed weight in the elevator.
The second line has n integers w_1,w_2,\dots,w_n: the weight of each person.
Output
Print one integer: the minimum number of rides.
Constraints

1 \le n \le 20
1 \le x \le 10^9
1 \le w_i \le x

Example
Input:
4 10
4 8 6 1

Output:
2*/
// pll rec(ll mask)
// {
//     // this returns the minimum number of rides needed to take all people in mask and the weight of the last ride ( the last ride is the ride where we take the least wieght so that we can take more people in the last ride later)
//     if(mask == 0) return {1 , 0 } ;
//     if(dp[mask] != -1) return dp[mask] ;
//     pll ans = { n + 1 , 0 } ;
//     for(ll i = 0 ; i < n ; i++)
//     {
//         if(mask & (1 << i))
//         {
//             pll prev = rec(mask ^ (1 << i) ) ;
//             pll cand ;
//             ll rides = prev.fr , weight = prev.sc 
//             if(weight + w[i] <= x)
//             {
//                 cand = { rides , weight + w[i] } ;
//             }
//             else 
//             {
//                 cand = { rides + 1 , w[i] } ;
//             }
//             if(cand.fr < ans.fr || (cand.fr == ans.fr && cand.sc < ans.sc))
//             {
//                 ans = cand ;
//             }

//         }
//         dp[mask] = ans ;

//     }
    
// }
void solve() 
{
    ll n , x ; 
    cin >> n >> x ; 
    vector <ll> w(n) ;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> w[i] ;
    }
    vector < pll > dp(1 << n , {n + 1 , 0 }) ;
    // dp[mask] = {rides , weight} where rides is the minimum number of rides needed to take all people in mask and weight is the weight of the last ride ( the last ride is the ride where we take the least wieght so that we can take more people in the last ride later)
    for(ll mask = 0 ; mask < (1 << n) ; mask++)
    {
        if(mask == 0)
        {
            dp[mask] = {1 , 0 } ;
            continue ;
        }
        pll ans = { n + 1 , 0 } ;
        for(ll i = 0 ; i < n ; i++)
        {
            if(mask & (1 << i))
            {
                pll prev = dp[mask ^ (1 << i) ] ;
                pll cand ;
                ll rides = prev.fr , weight = prev.sc ;
                if(weight + w[i] <= x)
                {
                    cand = { rides , weight + w[i] } ;
                }
                else 
                {
                    cand = { rides + 1 , w[i] } ;
                }
                if(cand.fr < ans.fr || (cand.fr == ans.fr && cand.sc < ans.sc))
                {
                    ans = cand ;
                }
            }
        }
        dp[mask] = ans ;
    }
    cout << dp[(1 << n) - 1].fr << endl ;

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  