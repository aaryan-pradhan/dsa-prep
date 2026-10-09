

#include <bits/stdc++.h>

#define ll long long 
#define endl "\n"
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

using namespace std;

void solve() 
{
    ll p, q;
    cin >> p >> q;
    
    if (p % q == 0 && (p / q) >= 2) 
    {
        py;
    } 
    else 
    {
        pn;
    }
}

signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll t; 
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}
