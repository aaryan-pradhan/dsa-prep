// Problem: C5. Divisor Walk (QuantFest 2026 Mock Regionals, Test 1)
// Link: ../QuantFest_2026_Mock_Regionals.md
// Start at n. Each step, replace the current number x by a uniformly random divisor of x (1 and x itself included). Output the expected number of steps until the number is 1.
//
// Input: q, then q lines each with n (1 ≤ q ≤ 10⁵, 1 ≤ n ≤ 10⁶). Output: one real number per query.
//
// | Input | Output |
// |---|---|
// | 5 / 1 / 2 / 4 / 6 / 12 | 0.000000 2.000000 2.500000 2.666667 3.033333 |
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
#define ld long double
using namespace std;
vector <ll> div[1000001];
void precompute()
{
    for(ll i = 1; i <= 1000000; i++)
    {
        for(ll j = i; j <= 1000000; j += i)
        {
            div[j].push_back(i);
        }
    }
}
// ll rec(ll i )
// {
//     // expected value of the number of steps to reach 1 from i is 1 + sum over all divisors of i of (expected value of the number of steps to reach 1 from that divisor) / (number of divisors of i)
//     vector <ll> divisors;
//     for(ll j = 1; j * j <= i; j++)
//     {
//         if(i % j == 0)
//         {
//             divisors.push_back(j);
//             if(j != i / j)
//                 divisors.push_back(i / j);
//         }
//     }
//     for(auto d : divisors)
//     {
//         if(d == i) continue;
//         return 1 + rec(d) / divisors.size();
//     }
//     return 0;


// }
void solve()
{
    ll n;
    cin >> n;
    vector <ld> dp(n + 1, 0);
    for(ll i = 1; i <= n; i++)
    {
        if(i == 1) { dp[i] = 0; continue; }
        ld sum = 0;
        for(auto d : div[i])
        {
            if(d == i) continue;
            sum += dp[d];
        }
        dp[i] = 1 + sum / (div[i].size());
        
    }
    cout << fixed << setprecision(6) << dp[n] << endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    ll t ; 
    cin >> t;
    while(t--)
    {
        solve() ;
    }
}
