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
ll gcd(ll a , ll b)
{
    if( b == 0 )
    {
        return a ; 
    }
    return gcd( b , a % b ) ; 
}
ll lcm( ll a , ll b )
{
    return ( a * b ) / gcd( a , b ) ;
}


vector < vector < ll > > d , mn ; 

void solve() 
{
    ll n , k ; 
    cin >> n >> k ; 
    vector < ll > p(n + 1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> p[i] ;
    }

    vector < ll > q(n + 1) ; 
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> q[i] ;
    }

    d.assign(n + 1 , vector < ll > (30)) ;
    mn.assign(n + 1 , vector < ll > (30)) ;
    for(ll i = 0 ; i < 30 ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            if( i == 0 )
            {
                d[j][i] = p[j] ;
                mn[j][i] = j ;
            }
            else
            {
                d[j][i] = d[d[j][i - 1]][i - 1] ;
                mn[j][i] = min( mn[j][i - 1] , mn[d[j][i - 1]][i - 1] ) ;
            }
        }
    }
    
    vector < ll > da(n + 1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        ll c = i ; 
        ll s = 0 ; 
        for(ll j = 29 ; j >= 0 ; j--)
        {
            if( mn[c][j] > mn[i][29] )
            {
                c = d[c][j] ;
                s += (1 << j) ;
            }
        }
        da[i] = s ; 
    }
    
    vector < ll > cl(n + 1) , sr(n + 1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cl[i] = da[p[mn[i][29]]] + 1 ;
        sr[i] = ( mn[q[i]][29] == mn[i][29] ) ? da[i] - da[q[i]] + cl[i] : -1 ;
    }
    ll B = 450;

    vector<ll> cnt(k + 1, 0);
    vector<vector<ll>> freq(B + 1);

    for(ll i = 1; i <= n; i++)
    {
        if(sr[i] == -1) continue;

        ll req = sr[i] % cl[i];
        if (req == 0) req = cl[i]; 
        if (req > k) continue;

        if(cl[i] <= B)
        {
            if(freq[cl[i]].empty())
                freq[cl[i]].assign(cl[i], 0);

            freq[cl[i]][req % cl[i]]++;
        }
        else
        {
            for(ll x = req; x <= k; x += cl[i])
                cnt[x]++;
        }
    }

    for(ll len = 1; len <= B; len++)
    {
        if(freq[len].empty()) continue;

        for(ll x = 1; x <= k; x++)
            cnt[x] += freq[len][x % len];
    }

    ll ans = 0;

    for(ll x = 1; x <= k; x++)
        ans = max(ans, cnt[x]);

    cout << ans << endl;
}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ;
    cin >> t ;
    while( t-- )
    {
        solve() ; 
    }
}