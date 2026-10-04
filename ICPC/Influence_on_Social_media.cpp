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
#define pn cout << "No supporter found." << endl
#define pll pair<ll,ll>

using namespace std;
vector <ll> ps ; 
ll primes[1000001] ; 
ll divr[1000001] ;
vector <ll> pr ; 
ll pow(ll a , ll b)
{
    ll ans = 1 ; 
    while( b-- )
    {
        if( ans > 2e12 / a ) return 2e12 ; 
        ans *= a ; 
    }
    return ans ; 
}
void precompute()
{
    
    for(ll i = 2 ; i <= 1000000 ; i++)
    {
        if(primes[i] == 0)
        {
            for(ll j = i * i ; j <= 1000000 ; j += i)
            {
                primes[j] = 1 ; 
            }
        }
    }
    for(ll i = 2 ; i <= 1000000 ; i++)
    {
        if(primes[i] == 0)
        {
            pr.push_back(i) ; 
        }
    }

    for(auto x : pr)
    {
        for(ll y = 3 ; y <= 100 ; y++)
        {
            if(primes[y] == 1)
            {
                continue ; 
            }
            ll p = pow(x , y - 1 ) ; 
            if( p > 1e12 + 10 )
            {
                break ; 
            }
            ps.push_back(p) ; 
        }
    }
    sort(ps.begin() , ps.end()) ;
}


void solve() 
{
    ll n ; 
    cin >> n ;
    vector< ll > a(n + 1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ; 
    }
    vector < pll > b(n + 1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        b[i] = mp(a[i] , i) ; 
    }
    sort(b.begin() + 1 , b.end()) ;
    reverse(b.begin() + 1 , b.end()) ;
    queue <ll> ans ; 
    for(ll i = 1 ; i <= n ; i++)
    {
        if(binary_search(ps.begin() , ps.end() , b[i].fr)== false)
        {
            continue ; 
        }
        
        ans.push(i) ;
    }

    if(ans.empty())
    {
        pn ; 
        return ; 
    }
    while(!ans.empty())
    {
        cout << ans.front() << " " ; 
        ans.pop() ; 
    }
    cout << endl ;
}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t; 
    cin >> t;
    int c = 0 ; 
    precompute() ;
    while(t--)
    {
        solve() ; 
    }
}