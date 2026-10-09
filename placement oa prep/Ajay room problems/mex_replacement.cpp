// orz
#include <bits/stdc++.h>
#include "algodebug.h"
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
ll n ; 
vector < pll > freq ; 

ll ts ; 

vector < ll > dp1 ; 
vector < vector < ll > > dp2 ;
ll rec(ll i , ll req)
{

    if(req > ts)
    {
        return INF ; 
    }
    if(i == -1)
    {
        return req ; 
    }
    ll ans = 0 ; 
    ll pres = freq[i].sc ;
    ll nreq = req ;
    if ( pres < req)
    {
        nreq += nreq - pres ;
    }
    ll g = 0 ; 
    if(i)
    {
        g = dp1[i] - dp1[i - 1] ; 
    }
    else 
    {
        g = dp1[i] ; 
    }
    while(g > 0 && nreq <= ts)
    {
        nreq*= 2;  
        g-- ; 
    }
    ans = rec(i - 1 , nreq) ;
    return ans ;
    

    
}
bool check1(ll x)
{
    if ( M == 0 )
    {
        return true ; 
    }
    ll lo = 0 ; 
    ll hi = n - 1 ;
    ll ans = n ;
    while(lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2 ; 
        if(!(freq[mid].fr <= x))
        {
            ans = mid ; 
            hi = mid - 1 ; 
        }
        {
            ans = mid ; 
            hi = mid - 1 ;
        }
        else 
        {
            lo = mid + 1 ;
        }
    }
    idx = ans - 1 ; 
    ll g = 
    
}
bool check2(ll x)
{
    return !check1(x) ;
}
void solve() 
{
    cin >> n ;
    freq.assign(n  , {0,0}) ; 
    dp1.assign(n , 0) ;
    for(ll i = 0 ; i < n ; i++)
    {
        ll x , y ;
        cin >> x >> y ;
        freq[i] = {x,y} ;
        ts += y ;
    }
    sort(freq.begin() , freq.end()) ;

    for(ll i = 0 ; i < n ; i++)
    {
        if(i == 0)
        {
            if(freq[i].fr == 0)
            {
                dp1[i] = 0 ; 
            }
            else 
            {
                dp1[i] = freq[i].fr ; 
            }
            continue ;
        }
        ll ans = dp1[i - 1] ;

        ll m = freq[i].fr - freq[i - 1].fr - 1 ; 
        ans += m ; 
        dp1[i] = ans ;
    }
    ll lo = 0 , hi = ts ;
    ll ans = -1 ;
    while(lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2 ;
        if(check2(mid))
        {
            hi = mid - 1 ; 
            ans = mid ; 
        }
        else 
        {
            lo = mid + 1 ; 
        }
    }
    cout << ans - 1 << endl ;
    


    
    

 






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;
    while(t--)
    {
        solve() ; 
    }
}
    
  