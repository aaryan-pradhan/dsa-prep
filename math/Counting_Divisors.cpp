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
/*Given n integers, your task is to report for each integer the number of its divisors.
For example, if x=18, the correct answer is 6 because its divisors are 1,2,3,6,9,18.
Input
The first input line has an integer n: the number of integers.
After this, there are n lines, each containing an integer x.
Output
For each integer, print the number of its divisors.
Constraints

1 \le n \le 10^5
1 \le x \le 10^6

Example
Input:
3
16
17
18

Output:
5
2
6*/


// void solve()
// {
//     ll n;
//     cin >> n;
//     ll d = 0 ; 
//     for(ll i = 1 ; i * i <= n ; i++)
//     {
//         if(n % i == 0)
//         {
//             d++;
//             if(i != n / i) d++;
//         }
//     } this takes 0(x * sqrt(n)) time complexity which is not good for n = 10^5 and x = 10^6
//     cout << d << endl;
   






// }
ll d[1000001];
void pre()
{
    for(ll i = 1 ; i <= 1000000 ; i++)
    {
        for(ll j = i ; j <= 1000000 ; j += i)
        {
            d[j]++;
        }
    }
}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ;
    cin >> t ;
    pre();
    while(t--)
    {
       ll x;
       cin >> x;
       cout << d[x] << endl;
    }
}
    
  