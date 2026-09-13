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
/*You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 5000
1 \le x,a_i \le 10^9

Example
Input:
4 8
2 7 5 1

Output:
1 3 4*/
void solve() 
{
    ll n ;
    cin >> n ;
    ll x ;
    cin >> x ;
    vector < pll > v(n) ;
    for (ll i = 0 ; i < n ; i++)
    {
        cin >> v[i].fr ;
        v[i].sc = i + 1 ; 
    }
    sort(v.begin() , v.end(), [&](const pll &a, const pll &b) {
        return a.fr < b.fr;
    });
    for (ll i = 0 ; i < n ; i++)
    {
        ll l = i + 1 , r = n - 1 ;
        while(l < r)
        {
            ll sum = v[i].fr + v[l].fr + v[r].fr ;
            if(sum == x)
            {
                cout << v[i].sc << " " << v[l].sc << " " << v[r].sc << endl ;
                return ;
            }
            else if(sum < x)
            {
                l++ ;
            }
            else
            {
                r-- ;
            }
        }
        
    }
    cout << "IMPOSSIBLE" << endl ;
    
}   
// void solve()
// {
//     ll n ; 
//     cin >> n ; 
//     ll tar ; 
//     cin >> tar ;
//     vector < ll > v(n) ;
//     map < ll , ll > m ;
//     for (ll i = 0 ; i < n ; i++)
//     {
//         cin >> v[i] ; 
//         m[v[i]] = i ; 
//     }
//     for(auto& ele : m)
//     {
//         cout << ele.fr << " " << ele.sc << endl ;
//     }
//     // for(auto &x : v)
//     // {
//     //     ll rem = tar - x ; 
//     //     if(m.find(rem) != m.end())
//     //     {
//     //         cout <<  << " " << m[x] << endl ;
//     //         return ; 
//     //     }



//     // }
//     for(ll i = 0 ; i < n ; i++)
//     {
//         ll rem = tar - v[i] ;
//         if(m.find(rem) != m.end())
//         {
//             cout << i << " " << m[v[i]] << endl ;
//             return ; 
//         }
//     }
// }
    
  
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}

// how to solve 2 SUM 
