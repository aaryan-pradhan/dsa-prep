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

Consider a game where two players remove sticks from a heap. The players move alternately, and the player who removes the last stick wins the game.
A set P=\{p_1,p_2,\ldots,p_k\} determines the allowed moves. For example, if P=\{1,3,4\}, a player may remove 1, 3 or 4 sticks.
Your task is find out for each number of sticks 1,2,\dots,n if the first player has a winning or losing position.
Input
The first input line has two integers n and k: the number of sticks and moves.
The next line has k integers p_1,p_2,\dots,p_k that describe the allowed moves. All integers are distinct, and one of them is 1.
Output
Print a string containing n characters: W means a winning position, and L means a losing position.
Constraints

1 \le n \le 10^6
1 \le k \le 100
1 \le p_i \le n

Example
Input:
10 3
1 3 4

Output:
WLWWWWLWL*/
// bool rec(ll left)
// {
//     // if we have left sticks present the rec returns the W if the current plaer playing the game has a winning position or L if the current player has a losing position
//     if(left == 0) return false ;
//     if(dp[left] != -1) return dp[left];
//     ll res = false ;
//     for( auto move : moves)
//     {
//         if(left - move >= 0 ))
//         {
//             if(!res(rec(left - move)))
//             {
//                 res = true ;
//                 break ;
//             }
            
//         }
//     }
//     dp[left] = res ;
//     return res ;
// }
void solve() 
{
    ll n , k ;
    cin >> n >> k ;
    ll moves[k] ; 
    for(ll i = 0 ; i < k ; i++)
    {
        cin >> moves[i] ;
    }
    vector <bool> dp(n+1 , false);
    for(ll left = 0 ; left <= n ; left++)
    {
        if(left == 0)
        {
            dp[left] = false ;
            continue ;
        }
        bool res = false ;
        for( auto& move : moves)
        {
            if(left - move >= 0 )
            {
                if(!dp[left - move])
                {
                    res = true ;
                    break ;
                }
                
            }
        }
        dp[left] = res ;
    }
    for(ll left = 1 ; left <= n ; left++)
    {
        if(dp[left]) cout << "W" ;
        else cout << "L" ;
    }
    cout << endl ;
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  