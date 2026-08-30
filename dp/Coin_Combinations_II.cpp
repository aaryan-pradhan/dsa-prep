// Problem: Coin Combinations II
// Link: https://cses.fi/problemset/task/1636
// Pattern: 1D bottom-up DP, order-doesn't-matter counting over unbounded coin set
// Time: O(n*x)  Space: O(x)

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll madd(ll a, ll b)
{
    ll s = a + b; 
    return s >= MOD ? s - MOD : s;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll  n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) cin >> coins[i];

    vector < vector < ll > > dp ( 2 , vector < ll > ( x + 1 , -1 ) ) ;
    for ( ll i = n ; i >= 0 ; i-- ) 
    {
        for ( ll left = 0 ; left <= x ; left ++ ) 
        {
            if ( left == 0 ) dp [ (i&1) ] [ left ] = 1 ;
            else if ( i == n ) dp [ (i&1) ] [ left ] = 0 ;
            else 
            {
                ll ans = 0 ;
                if ( left - coins [i] >= 0 ) 
                    ans = madd(ans , dp [ (i&1) ] [ left - coins [ i ] ] ) ;
                
                
                ans = madd(ans , dp [ ((i+1)&1) ] [ left ] ) ;
                dp [ (i % 2) ] [ left ] = ans ; 
        }
    } 
    }

    

    cout << dp[0][x] << '\n';
    return 0;
}

// Recall Trail
// Approach: dp[left] = number of ways to make sum `left` using coins from
// index i onward (order doesn't matter -> outer loop over coins, inner
// over sums), rolling 2-row array on i parity: dp[i][left] = ways using
// coin i (stay on i, left -= coins[i]) + ways skipping coin i
// (dp[i+1][left]). Base case dp[left=0] = 1 for every i.
