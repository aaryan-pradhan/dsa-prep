/*
 * Accenture OA: 4Sum (Four Values Sum)
 *
 * Description:
 * You are given an array of n integers, and your task is to find four values 
 * (at distinct positions) whose sum is x.
 *
 * Input Format:
 * The first input line has two integers n and x: the array size and the target sum.
 * The second line has n integers a_1, a_2, ..., a_n: the array values.
 *
 * Output Format:
 * Print YES if such four values exist, otherwise NO.
 *
 * Constraints:
 * 1 <= n <= 1000
 * 1 <= x, a_i <= 10^9
 *
 * Sample Input 1:
 * 8 15
 * 3 2 5 8 1 3 2 3
 * 
 * Sample Output 1:
 * YES
 *
 * Note:
 * Store sums of pairs of elements seen so far in a hash table keyed by their sum. 
 * For each new pair (i, j) with larger indices, check if x - (a_i + a_j) exists 
 * in the table (ensuring indices are distinct). If such an entry exists, four 
 * elements summing to x are found, so print YES. Otherwise continue and finally 
 * print NO if no such quadruple is found.
 */

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
    ll n, x ;
    cin >> n >> x ;

    vector < ll > a(n) ;
    for(ll i = 0 ; i < n ; i++) cin >> a[i] ;

    map < ll , pll > pos ;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = i + 1 ; j < n ; j++)
        {
            ll rem = x - a[i] - a[j] ;

            if(pos.find(rem) != pos.end())
            {
                py ; 
                return ;
            }
        }
        for(ll j = 0 ; j < i ; j++)
        {
            ll sum = a[i] + a[j] ;
            pos[sum] = {i, j} ;
        }
        

        
    }

    pn ;
}
    


    
   




signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;
    while(t--)
    {
        solve() ; 
    }
}
    
  