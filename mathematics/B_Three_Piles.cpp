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
    ll a , b , c ; 
    cin >> a >> b >> c ;
    // if a > b then alice will take all c stones and then the game ends with a+c and b and the score is a+c-b
    if(a > b)
    {
        cout << a + c - b << endl;
    }
    else 
    {
        ll c1 = abs(a + c - b) ;
        ll c3 = abs(a - b) ; 
        cout << max(c1 , c3) << endl;
    }
    
   






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
    
  