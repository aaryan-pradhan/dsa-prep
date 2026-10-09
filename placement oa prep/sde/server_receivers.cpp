/*
 * SDE - Q2: Servers and Receivers
 *
 * Description:
 * There are n servers and m receivers.
 * An array of size m is given where array[i] tells at which server the i-th receiver can go, 
 * and on that server each receiver takes 1 sec of time.
 * To change the server of any receiver the time taken is 2 sec. 
 * So minimize the time in which all the receivers are attended using those n servers.
 */

// orz
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define INF 1e18
vector < ll > a , s ; 
ll n , m ; 
bool check(ll time)
{
    ll mm , c ; 
    mm = c = 0 ; 
    for(ll i = 0 ; i < n ; i++)
    {
        if(s[i] > time)
        {
            mm += s[i] - time ; 
        }
        else if (s[i] < time)
        {
            c += (time - s[i]) / 2 ; 
        }
    }
    return mm <= c ; 
}
void solve()
{
    cin >> n >> m ; 
    a.assign(m , 0 ) ; 
    s.assign(n , 0 ) ; 
    for( ll i = 0 ; i < m ; i++)
    {
        cin >> a[i] ; 
        s[a[i]]++ ; 
    }
    ll lo = 0 ; 
    ll hi = INF ; 
    ll ans = 0 ; 
    while( lo <= hi)
    {
        ll mid = lo + (hi - lo ) / 2 ; 
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

