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
/*Your task is to count the number of one bits in the binary representations of integers between 1 and n.
Input
The only input line has an integer n.
Output
Print the number of one bits in the binary representations of integers between 1 and n.
Constraints

1 \le n \le 10^{15}

Example
Input:
7

Output:
12

Explanation: The binary representations of 1 \ldots 7 are 1, 10, 11, 100, 101, 110, and 111, so there are a total of 12 one bits.*/
void solve() 
{
    ll n;
    cin >> n;
    // ll count = 0;
    // for (ll i = 1; i <= n; i++)
    // {
    //     count += __builtin_popcountll(i);
    //     // __builtin_popcountll is a built-in function that counts the number of one bits in the binary representation of an integer this takes O(1) time complexity
    // }
    // cout << count << endl;
    // // but n is up to 10^15 so we need to optimize the solution
    // for n = 5, 0th bit has contributed in 1 , 3 and 5 so 3 times, 1st bit has contributed in 2 and 3 so 2 times, 2nd bit has contributed in 4 and 5 so 2 times. Therefore the total number of one bits is 3 + 2 + 2 = 7.
    //0 0 0 , 0 0 1 , 0 1 0 , 0 1 1 , 1 0 0 , 1 0 1 , 1 1 0 , 1 1 1
    // so there are blocks of 2^k numbers where k is the bit position, and in each block, half of the numbers have the k-th bit set to 1. We can use this observation to count the number of one bits in O(log n) time complexity.
    ll ans = 0 ; 
    for(ll i = 0; (1LL << i) <= n; i++)
    {
        ll block_size = 1LL << (i + 1);
        ll full_blocks = n / block_size;
        ll remainder = n % block_size;
        ll count = full_blocks * (block_size / 2) ;
        if(remainder >= (block_size / 2))
        {
            count += (remainder - (block_size / 2) + 1);
        }
        ans += count;
        
    }
    cout << ans << endl;






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  