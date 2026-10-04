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
void print(vector<ll> &a)
{
    for(auto x : a)
    {
        cout << x << " " ;
    }
    cout << endl ;
}
void solve() 
{
    
   ll n ; 
   cin >> n ;
   vector<ll> a ;
   for(ll i = 1 ; i <= n ; i++)
   {
       a.push_back(i) ;
   }
   cout << n/2 << endl ;
   for(ll i = 0 ; i < n/2 ; i++)
   {
        print(a) ;
        swap(a[i] , a[n - i - 1]) ;
   }
   







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t; 
    cin >> t;
    while(t--)
    {
        solve() ; 
    }
}
    
  