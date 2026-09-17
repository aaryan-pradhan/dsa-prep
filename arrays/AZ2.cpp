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
    vector < ll > ne ; 
    vector < ll > ze ; 
    vector < ll > po ; 
    for(ll i = 0 ; i < n ; i++)
    {
        ll x ; 
        cin >> x ; 
        if( x > 0)  po.push_back(x) ; 
        else if ( x == 0 )  ze.push_back(x) ; 
        else    ne.push_back(x) ; 

    }
    for(auto& x : ne)
    {
        cout << x << " " ; 
    }
    for(auto& x : ze)
    {
        cout << x << " " ; 
    }
    for(auto& x : po)
    {
        cout << x << " " ; 
    }
    cout << endl ; 
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;
    // t = 1 ;
    while(t--)
    {
        solve() ; 
    }
}
    
  