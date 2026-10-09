/* 
 * Accenture OA: Fibonacci Index
 *
 * Description:
 * The Fibonacci Sequence is a series of numbers where the i-th number is defined by 
 * the recurrence relation:
 * F(i) = F(i-1) + F(i-2)
 *
 * with the base cases:
 * F(0) = 0, F(1) = 1
 *
 * Given an integer N >= 2, your task is to determine its index in the Fibonacci 
 * Sequence or print -1 if N is not part of the sequence.
 *
 * Input Format:
 * The first line of input contains one integer T - the number of test cases.
 * The only line of each test case contains an integer N.
 *
 * Output Format:
 * For each test case, print on a new line the index of N in the Fibonacci Sequence, 
 * or -1 if it is not a part of the sequence.
 *
 * Constraints:
 * 1 <= T <= 10
 * 2 <= N <= 10^15
 *
 * Sample Input 1:
 * 2
 * 13
 * 34
 *
 * Sample Output 1:
 * 7
 * 9
 *
 * Sample Input 2:
 * 2
 * 21
 * 10
 *
 * Sample Output 2:
 * 8
 * -1
 *
 * Explanation:
 * Test Case 1:
 * N = 13: 13 is the 7th number in the Fibonacci sequence (0,1,1,2,3,5,8,13,21,34,...). Output: 7.
 * N = 34: 34 is the 9th number in the sequence. Output: 9.
 *
 * Test Case 2:
 * N = 21: 21 is the 8th number in the sequence. Output: 8.
 * N = 10: 10 is not in the sequence. Output: -1.
 */

// orz
#include <bits/stdc++.h>
#include "algodebug.h"
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
map < ll,ll> fib ;
void precompute()
{
    // Precompute Fibonacci numbers up to 10^15
    ll a = 0, b = 1;
    fib[a] = 0; 
    fib[b] = 1; 
    ll index = 2;
    while (true) {
        ll c = a + b;
        if (c > 1e15) break; 
        fib[c] = index; 
        a = b;
        b = c;
        index++;
    }
}
void solve() 
{
    ll n ; 
    cin >> n ;
    ll ans = -1 ;
    if (fib.find(n) != fib.end()) 
    {
        ans = fib[n] ;
    }
    cout << ans << endl ;
    


   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;
    precompute() ;
    while(t--)
    {
        solve() ; 
    }
}
    
  