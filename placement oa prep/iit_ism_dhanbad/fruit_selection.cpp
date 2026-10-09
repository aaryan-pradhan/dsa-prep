/*
 * Eternal IIT ISM Dhanbad (SDE)
 * Problem 2: Fruit Selection with Discount Coupons
 *
 * Description:
 * You are given N different fruits. Each fruit has:
 * • price[i] — the cost of the i-th fruit.
 * • nutrition[i] — the nutritional value you gain by eating the i-th fruit.
 *
 * You have:
 * • M units of money.
 * • K discount coupons.
 *
 * You want to maximize the total nutritional value of the fruits you purchase.
 *
 * Coupon Rule:
 * • Each fruit can be purchased at most once.
 * • If you purchase a fruit without using a coupon, you pay its full price price[i].
 * • If you purchase a fruit using one coupon, you pay half its price, i.e. floor(price[i] / 2).
 * • Each coupon can be used on at most one fruit.
 * • You can choose not to use all your coupons.
 * • The total amount spent must not exceed M.
 *
 * Return the maximum total nutrition you can obtain.
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"


// ll rec(ll i , ll cl , ll ml)
// {
//     if(i == n)
//         return 0;
//     if (dp[i][cl][ml] != -1)
//         return dp[i][cl][ml];
//     // take without coupon
//     ll ans = 0;
//     if(ml >= p[i])
//     {
//         ans = n[i] + rec(i + 1 , cl , ml - p[i]);
//     }
//     // take with coupon
//     if(cl > 0 && ml >= p[i] / 2)
//     {
//         ans = max(ans , n[i] + rec(i + 1 , cl - 1 , ml - p[i] / 2));
//     }
//     // don't take
//     ans = max(ans , rec(i + 1 , cl , ml));
//     return dp[i][cl][ml] = ans;
// }
void solve() 
{
    ll n, m , k ; 
    cin >> n >> m >> k ;
    vector < ll > p(n) , nu(n) ;
    for(ll i = 0 ; i < n ; i++) cin >> p[i] ; 
    for(ll i = 0 ; i < n ; i++) cin >> nu[i] ;
    vector < vector < vector < ll > > > dp(2 , vector < vector < ll > > (k + 1 , vector < ll > (m + 1 , 0))) ;
    for(ll i = n - 1 ; i >= 0 ; i--)
    {
        for(ll cl = 0 ; cl <= k ; cl++)
        {
            for(ll ml = 0 ; ml <= m ; ml++)
            {
                if(i == n)
                {
                    dp[(i&1)][cl][ml] = 0 ;
                    continue ;
                }
                ll ans = 0 ;
                if(ml >= p[i])
                {
                    ans = nu[i] + dp[(i + 1)&1][cl][ml - p[i]] ;
                }
                if(cl > 0 && ml >= p[i] / 2)
                {
                    ans = max(ans , nu[i] + dp[(i + 1)&1][cl - 1][ml - p[i] / 2]) ;
                }
                if(ml >= 0)
                {
                    ans = max(ans , dp[(i + 1)&1][cl][ml]) ;
                }
                dp[(i&1)][cl][ml] = ans ;
                

            
            }
        }
    }
    cout << dp[0][k][m] << endl ;

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
