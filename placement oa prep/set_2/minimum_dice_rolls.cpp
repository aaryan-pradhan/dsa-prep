/*
 * DSA Question — Set 2: Minimum Dice Rolls to Reach the End
 *
 * Description:
 * You are given an array A of non-negative integers of size N. You start at index 0 and need to reach an index
 * greater than or equal to N.
 * A special die is available. You can choose any number from 1 to 6 whenever you roll the die.
 * At any index, there are two possible actions:
 * • Roll the die: choose any value from 1 to 6 and jump forward by that many positions. This counts as one dice roll.
 * • Use the value at the current index: jump forward by exactly A[i] positions. This action does not require a dice roll.
 * 
 * The objective is to reach an index >= N using the minimum possible number of dice rolls.
 *
 * Example:
 * N = 10
 * A = [0, 0, 0, 0, 0, 1, 1, 1, 1]
 * Output: 1
 */

// orz
#include <bits/stdc++.h>

using namespace std;
#define INF 1e18 
#define ll long long
#define endl "\n"

void solve() {
    ll n ; 
    cin >> n ; 
    vector < ll > a(n) ; 
    vector < ll > dp(n+1, 0 ) ; 
    for(ll i = 0 ; i < n ; i++) cin >> a[i] ; 
    for(ll l = n ; l >= 0 ; l--)
    {
        if( l == n )
        {
            dp[n] = 0 ; 
            continue ; 
        }

        ll ans = INF ; 
        for(ll i = 1 ; i <= 6 ; i++)
        {
            if( l + i <= n)
            {
                ans = min ( 1 + dp[l+i], ans ) ; 
            }
            else 
            {
                ans = min ( 1LL , ans ) ; 
            }
        }
        if(a[l])
        {
            if(l +a[l] <= n)
            {
                ans = min ( ans , dp[l + a[l]]) ;

            }
            else 
            {
                ans = min ( 0LL , ans ) ; 
            }
        }
            
        dp[l] = ans ; 
    }
    cout << dp[0] << endl ; 



}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

