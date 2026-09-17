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
/*Maximize Minimum Difference
you need to find the maximum of the minimum absolute differences between any two elements in a subsequence of size K.*/
vector < ll > v ;
ll n , k ;
bool check(ll x )
{
    // if we can chose atleast k elements such that the minimum absolute difference between any two elements is greater than or equal to x then we return false else we return true
    
    ll cnt = 1 , last = v[0] ;
    for(ll i = 1 ; i < n ; i++)
    {
        if(v[i] - last >= x)
        {
            cnt++ ;
            last = v[i] ;
        }
    }
    if( cnt >= k)
    {
        return false ;
    }
    else
    {
        return true ;
    }
    
    
}
void solve() 
{
    cin >> n >> k ;
    v.resize(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }
    sort(v.begin(), v.end()) ;
    ll lo = 1 , hi = INF , ans = 0 ;
    while(lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2 ;
        if(check(mid))
        {
            ans = mid ;
            hi = mid - 1 ;
        }
        else
        {
            lo = mid + 1 ;
        }
    }
    cout << ans << endl ;
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t; 
    cin >> t ; 
    while(t--)
    {
        solve() ;
    }
}
    
  