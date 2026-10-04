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


void solve() 
{
    

    ll n ;
    cin >> n ;
    vector<ll> a(n + 1) ; 
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ; 
    }
    ll msw = 2 * n - 2  ; 
    vector < vector < vector <ll> > > dp(2 , vector < vector < ll > > (n + 1 , vector < ll > (msw + 1, -1) ) ) ;
    vector < vector < vector <ll> > > dp2(2 , vector < vector < ll > > (n + 1 , vector < ll > (msw + 1, -1) ) ) ;

    for(ll t = n + 1 ; t >= 1 ; t--)
    {
        for(ll j = n; j >= 0 ; j--)
        {
            for(ll u = msw ; u >= 0 ; u--)
            {
                if(t == n + 1 )
                {
                    dp[(t&1)][j][u] = 0 ;
                    continue ;
                }
                ll ans = -1 ; 
                if(j != 0 && u + 1 <= t)
                {
                    ans = dp[(t + 1)&1][j][u + 1] + a[j] ;
                }
                for(ll k = max(j + 1 , t) ; k <= n ; k++)
                {
                    ll c = k - t ; 
                    if( u + c <= t )
                    {
                        ans = max(ans , dp[(t + 1)&1][k][u + c] + a[k] ) ; 
                    }
                }
                dp[(t&1)][j][u] = ans ;

                
            }
        }
    }
    cout << dp[1][0][0] << endl ;

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  