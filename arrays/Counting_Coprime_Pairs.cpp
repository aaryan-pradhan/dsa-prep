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
/*Given a list of n positive integers, your task is to count the number of pairs of integers that are coprime (i.e., their greatest common divisor is one).
Input
The first input line has an integer n: the number of elements.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the list.
Output
Print one integer: the answer for the task.
Constraints

1 \le n \le 10^5
1 \le x_i \le 10^6

Example
Input:
8
5 4 20 1 16 17 5 15

Output:
19*/
const ll MAX = 1e6 + 5 ;
ll spf[MAX] ;
void sieve()
{
    for(ll i = 2 ; i < MAX ; i++)
    {
        if(spf[i] == 0)
        {
            for(ll j = i ; j < MAX ; j += i)
            {
                if(spf[j] == 0)
                {
                    spf[j] = i ;
                }
            }
        }
    }
}
ll reduce(ll a)
{
    ll ans = 1 ; 
    while(a > 1)
    {
        ll p = spf[a] ; 
        ans *= p ; 
        while(a % p == 0)
        {
            a /= p ; 
        }
    }
    return ans ;
}
ll nopd(ll a)
{
    ll cnt = 0 ; 
    while(a > 1)
    {
        ll p = spf[a] ; 
        cnt++ ; 
        while(a % p == 0)
        {
            a /= p ; 
        }
    }
    return cnt ;
}

void solve() 
{
    
   ll n ; 
   cin >> n ;
   vector < ll > v(n) ;
   ll maxi = 0 ;
   for(ll i = 0 ; i < n ; i++)
   {
        ll x ; 
        cin >> x ; 
        v[i] = reduce(x) ;
        maxi = max(maxi , v[i]) ;
   }
   vector < ll > freq(maxi + 1 , 0) ;
   for(ll i = 0 ; i < n ; i++)
   {
        freq[v[i]]++ ; 
   }
   vector < ll > dp(maxi + 1 , 0) ;
   for(ll d = 1 ; d <= maxi ; d++)
   {
        for(ll j = d ; j <= maxi ; j += d)
        {
            dp[d] += freq[j] ;   
        }
   }
   
    

   ll ans = 0 ; 
   for(ll d = 1 ; d <= maxi ; d++)
   {
        ll cnt = dp[d] ; 
        ll pairs = (cnt * (cnt - 1)) / 2 ; 
        if(pairs == 0)
        {
            continue ; 
        }
        if(nopd(d) % 2 == 0)
        {
            ans += pairs ;
        }
        else
        {
            ans -= pairs ;
        }
        
   }
   cout << ans << endl ;







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve() ;
    solve() ; 
}
    
  