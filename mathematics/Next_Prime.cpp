// orz
#include <bits/stdc++.h>

#define ll unsigned long long 
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
/*Given a positive integer n, find the next prime number after it.
Input
The first line has an integer t: the number of tests.
After that, each line has a positive integer n.
Output
For each test, print the next prime after n.
Constraints

1 \le t \le 20
1 \le n \le 10^{12}

Example
Input:
5
1
2
3
42
1337

Output:
2
3
5
43
1361*/

bool iscomposite[1000100] ;
vector < ll > primes ;
void sieve()
{
    for(ll i = 2 ; i < 1000100 ; i++)
    {
        
        if(!iscomposite[i])
        {
            
            for(ll j = i * i ; j < 1000100 ; j += i)
            {
                iscomposite[j] = true ;
            }
        }
    }
}
void solve() 
{
    ll n ; 
    cin >> n ;
    if(n < 1000100)
    {
        cout << *upper_bound(primes.begin() , primes.end() , n) << endl ;
    }
    else
    {
        ll ans ;
        if(n%2 == 0)
        {
            ans = n + 1 ;
        }
        else 
        {
            ans = n + 2 ;
        }
        while(true)
        {
            bool isprime = true ;
            for(auto &x : primes)
            {
                if(x * x > ans)
                {
                    break ;
                }
                if(ans % x == 0)
                {
                    isprime = false ;
                    break ;
                }
                
            }
            if(isprime)
            {
                cout << ans << endl ;
                break ;
            }
            else 
            {
                ans += 2 ;
            }
        }
    }

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve() ;
    for(ll i = 2 ; i < 1000100 ; i++)
    {
        if(!iscomposite[i])
        {
            primes.push_back(i) ;
        }
    }
    
 
    ll t ;
    cin >> t ;
    while(t--)
    {
        solve() ; 
    }
}
    
