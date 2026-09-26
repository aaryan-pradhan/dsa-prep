// Problem: C1. Up to k Rolls (QuantFest 2026 Mock Regionals, Test 1)
// Link: ../QuantFest_2026_Mock_Regionals.md
// You roll a fair m-sided die (faces 1..m). After each roll you may keep the number (you are paid that many dollars and the game ends) or throw it away and roll again. You may roll at most k times; the k-th roll must be kept.
//
// Output the expected payout under optimal play.
//
// Input: m k (1 ≤ m, k ≤ 10⁶). Output: one real number.
//
// | Input | Output |
// |---|---|
// | 6 1 | 3.500000 |
// | 6 2 | 4.250000 |
// | 6 3 | 4.666667 |
// | 10 3 | 7.450000 |
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
#define ld double

using namespace std;
// ll rec(ll i )
// {
//     // this function returns the expected value of the game if i have already rolled i - 1 times
//     // i am on the ith turn 
//     // thereforei have k-i turns left
//     // now i have to decide whether to keep the number or to roll again 
//     // what is the way to decide whether to keep the number or to roll again
//     if(i == k)
//     {
//         // if i am on the last turn then i would have to keep the number that i rolled
//         // so the expected value is the average of all possible outcomes
//         return (m + 1) / 2;
//     }
//     else
//     {
//         // if i am not on the kth turn then i have to decide whether to keep the number or to roll again 
//         // if i keep the number then i will get the number that i rolled 
//         // if i roll again then i will get the expected value of the next turn 
//         // therefore i will keep the number if the number that i rolled is greater than or equal to the expected value of the next turn 
//         // otherwise i will roll again 
//         ll expected_value_of_next_turn = rec(i + 1);
//         ll expected_value_of_current_turn = (m + 1) / 2;
//         return max(expected_value_of_current_turn, expected_value_of_next_turn);
//     }
// }
void solve()
{
    ll m , k ; 
    cin >> m >> k ;
    vector <ld> dp(k + 1, 0);
    for(ll i = k; i >= 1; i--)
    {
        if(i == k)
        {
            dp[i] = (m + 1) / 2.0;
            continue;
        }
        else
        {
            ld sol = 0.0 ; 
            // first place where the max switches
            ld exp = dp[i + 1];
            ll fst = ceil(exp);
            // 1 to fst - 1 we will roll again
            sol += (fst - 1) * dp[i + 1];
            // fst to m we will keep the number
            sol += (m - fst + 1) * (fst + m) / 2.0;
            sol /= m;
            dp[i] = sol;
            

        }
    }
    cout << fixed << setprecision(6) << dp[1] << endl;  
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}
