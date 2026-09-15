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
void solve() 
{
    ll c ; 
    cin >> c ;

    ll a = c ; 
    ll b ; 
    
    ll check = 0 ; 
    while( c > 0 )
    {
        c /= 2 ; 
        check++ ; 
    }
    
    ll k = 1LL << ( check + 1 ) ;
    b = k * a ;
    cout  << a << " " << b << endl ;
    
    
   
    


    

    

    
   






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
    
  