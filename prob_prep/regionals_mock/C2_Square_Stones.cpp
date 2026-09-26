// Problem: C2. Square Stones (QuantFest 2026 Mock Regionals, Test 1)
// Link: ../QuantFest_2026_Mock_Regionals.md
// A pile has n stones. Alice and Bob alternate, Alice first. A move removes a positive perfect square number of stones (1, 4, 9, …), no more than the pile holds. The player who cannot move loses.
//
// Input: t, then t lines each with n (1 ≤ t ≤ 10⁵, 1 ≤ n ≤ 10⁵). Output: the winner for each n.
//
// | Input | Output |
// |---|---|
// | 5 / 1 / 2 / 3 / 4 / 5 | Alice Bob Alice Alice Bob |
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
                     
// ll rec(ll i)
// {
//     // this function returns the winner of the game if there are i stones left in the pile
//     // if i is a perfect square then the player whose turn it is can take all the stones and win the game
//     // if i is not a perfect square then the player whose turn it is can take a perfect square number of stones and leave the opponent with a perfect square number of stones and win the game
//     // therefore if i is a perfect square then the player whose turn
//     if(i == 0)
//     {
//         // if there are no stones left then the player whose turn it is loses the game
//         return 0;
//     }
//     else
//     {
//         if(dp[i] != -1) return dp[i];           // cache check
//         // if there are stones left then the player whose turn it is can take a perfect square number of stones and leave the opponent with a perfect square number of stones and win the game
//         for(ll j = 1; j * j <= i; j++)
//         {
//             if(rec(i - j * j) == 0)
//             {
//                 return dp[i] = 1;               // save and return
//             }
//         }
//         return dp[i] = 0;                       // save and return
//     }
// }
bool dp[1000010];  
void solve()
{
    ll n ; 
    cin >> n ; 
    if(dp[n] == 1)
    {
        cout << "Alice" << endl ; 
    }
    else
    {
        cout << "Bob" << endl ; 
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(ll i = 0 ; i <= 100000 ; i++)
    {
        if(i == 0)
        {
            dp[i] = 0;
            continue;
        }
        bool ans = 0 ;
        // this state would be a winning state if there is a perfect square number of stones tha can be taken to leave the opponent in a losing state
        for(ll j = 1 ; j * j <= i ; j++)
        {
            if(dp[i - j * j] == 0)
            {
                ans = 1;
                break;
            }
        }
        dp[i] = ans;
    }

    ll t ; 
    cin >> t ;
    while(t--)
    {
        solve() ; 
    }
}
