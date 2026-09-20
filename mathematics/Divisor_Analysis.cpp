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
/*Time limit: 1.00 s
Memory limit: 512 MB

Given an integer, your task is to find the number, sum and product of its divisors. As an example, let us consider the number 12:

the number of divisors is 6 (they are 1, 2, 3, 4, 6, 12)
the sum of divisors is 1+2+3+4+6+12=28
the product of divisors is 1 \cdot 2 \cdot 3 \cdot 4 \cdot 6 \cdot 12 = 1728

Since the input number may be large, it is given as a prime factorization.
Input
The first line has an integer n: the number of parts in the prime factorization.
After this, there are n lines that describe the factorization. Each line has two numbers x and k where x is a prime and k is its power.
Output
Print three integers modulo 10^9+7: the number, sum and product of the divisors.
Constraints

1 \le n \le 10^5
2 \le x \le 10^6
each x is a distinct prime
1 \le k \le 10^9

Example
Input:
2
2 2
3 1

Output:
6 28 1728*/
ll madd(ll a, ll b) 
{
    return (a%MOD + b%MOD) % MOD;
}
ll mmul(ll a, ll b)
{
    return (a%MOD * b%MOD) % MOD;
}
ll mpow( ll a, ll b)
{
    ll res =1 ; 
    while(b)
    {
        if(b&1) res = mmul(res,a);
        a = mmul(a,a);
        b >>= 1;
    }
    return res ; 
}
ll minv(ll a)
{
    return mpow(a,MOD-2);
}
ll mdiv(ll a, ll b)
{
    return mmul(a,minv(b));
}
ll msub(ll a, ll b)
{
    return (a%MOD - b%MOD + MOD) % MOD;
}
ll mcorr(ll a)
{
    return (a%MOD + MOD) % MOD;
}
// a ^ ( b * c) = x find x mod M 
ll mpowmul(ll a , ll b , ll c)
{
    ll exp = (b % (MOD-1) * c % (MOD-1)) % (MOD-1) ;
    return mpow(a,exp) ;

}
// a ^ ( b / c) = x find x mod M // there is no general function 
// a ^ ( b / 2) = x find x mod M 
ll mpowdiv( ll a , ll b)
{
    ll exp = ( b % (2 * (MOD-1)) ) / 2 ;
    return mpow(a,exp) ;
}

struct PrimeFactorization
{
    vector <ll> primes ; 
    vector <ll> powers ; 
    ll n ; 
    PrimeFactorization(ll n)
    {
        this->n = n ; 
        for(ll i = 0 ; i < n ; i++)
        {
            ll x , k ; 
            cin >> x >> k ; 
            primes.push_back(x) ; 
            powers.push_back(k) ; 
        }
    }
    ll no_of_divisors()
    {
        ll ans = 1 ; 
        for(ll i = 0 ; i < n ; i++)
        {
            ans = mmul(ans,powers[i]+1) ; 
        }
        return ans ; 
    }
    
    
    ll sum_of_divisors()
    {
        ll ans = 1 ; 
        for(ll i = 0 ; i < n ; i++)
        {
            // 1 + p + p^2 + ... + p^k = (p^(k+1) - 1) / (p - 1)
            ll p = primes[i] ;
            ll k = powers[i] ;
            ll pow = mpow(p,k+1) ;
            ll sum = mdiv(msub(pow,1),msub(p,1)) ;
            ans = mmul(ans,sum) ;
        }
        return ans ; 
    }
    bool perfect_square()
    {
        for(ll i = 0 ; i < n ; i++)
        {
            if(powers[i] % 2 != 0) return false ; 
        }
        return true ; 
    }
    ll product_of_divisors()
    {
        ll ans = 1 ; 
        ll rootn = 1 ; 
         
        if(!perfect_square())
        {
            ll num_divisors = no_of_divisors() ; 
             
            for(ll i = 0 ; i < n ; i++)
            {
                ll p = primes[i] ;
                ll k = powers[i] ;
                ll pow = mpow(p,k) ;
                rootn = mmul(rootn,pow) ; 
            }
            ans = mpow(rootn,exp) ; 
        }
        else
        {
            for(ll i = 0 ; i < n ; i++)
            {
                ll p = primes[i] ;
                ll k = powers[i] ;
                ll pow = mpow(p,k/2) ;
                rootn = mmul(rootn,pow) ; 
            }
            ans = mpowmul(rootn,no_of_divisors(),1) ; 
        }
        
        
    }
};
void solve() 
{
    ll n ; 
    cin >> n ;
    vector <pll> v(n) ;
    PrimeFactorization pf(n) ;
    cout << pf.no_of_divisors() << " " << pf.sum_of_divisors() << " " << pf.product_of_divisors() << endl ;
    


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  