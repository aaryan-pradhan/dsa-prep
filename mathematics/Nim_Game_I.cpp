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
/*There are n heaps of sticks and two players who move alternately. On each move, a player chooses a non-empty heap and removes any number of sticks. The player who removes the last stick wins the game.
Your task is to find out who wins if both players play optimally.
Input
The first input line contains an integer t: the number of tests. After this, t test cases are described:
The first line contains an integer n: the number of heaps.
The next line has n integers x_1,x_2,\ldots,x_n: the number of sticks in each heap.
Output
For each test case, print "first" if the first player wins the game and "second" if the second player wins the game.
Constraints

1 \le t \le 2 \cdot 10^5
1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9
the sum of all n is at most 2 \cdot 10^5

Example
Input:
3
4
5 7 2 5
2
4 1
3
3 5 6

Output:
first
first
second*/
void solve() 
{
    ll n ; 
    cin >> n ;
    ll res = 0 ; 
    for(ll i = 0 ; i < n ; i++)
    {
        ll x ; 
        cin >> x ;
        res ^= x ;
    }
    if(res == 0)
    {
        // then the first player forcibly makes xor non zero and then second player can force it to be zero
        // why? 
        // x1 ^ x2 ^ x3 ^ ... ^ xn = 0
        // then let's say xi -> y then x1 ^ x2 ^ ... ^ xi-1 ^ y ^ xi+1 ^ ... ^ xn is never zero
        // let's say it is zero then x1 ^ x2 ^ ... ^ xi-1 ^ y ^ xi+1 ^ ... ^ xn = 0
        // then x1 ^ x2 ^ ... ^ xi-1 ^ y ^ xi+1 ^ ... ^ xn ^ x1 ^ x2 ^ ... ^ xi-1 ^ x ^ ... ^ xn = 0
        // then y ^ x = 0 => y = x which is not possible since we are removing some sticks 
        // therefore first player will forcibly make it zero
        cout << "second" << endl;
    }
    else 
    {
        // then first player has some way to make this zero
        // let's say x1 ^ x2 ^ ... ^ xn = k != 0
        // then let's say we optimally chose xi and then and then make it y 
        // then x1 ^ x2 ^ ... ^ xi-1 ^ y ^ xi+1 ^ ... ^ xn = 0
        // how to fins such a y?
        // then x1 ^ x2 ^ ... ^ xi-1 ^ y ^ xi+1 ^ ... ^ xn = 0
        // therefore k = x1 ^ x2 ^ ... ^ xi-1 ^ xi ^ xi+1 ^ ... ^ xn ^ x1 ^ x2 ^ ... ^ xi-1 ^ y ^ xi+1 ^ ... ^ xn
        // therefore k = xi ^ y => y = k ^ xi
        // y = k ^ xi < xi 
        // thus we need to just chose any non zero xi and then make it y = k ^ xi
        // this would force the xor to be zero
        cout << "first" << endl;
    }
    // but why is this the optimal strategy?
    // dp[x1 , x2 , ... , xn] = 1 if the current player has a winning strategy and 0 if the current player has a losing strategy
    // then dp[x1 , x2 , ... , xn] = 0 if for all the moves we can do on it the other player has a winning strategy
    // then dp[x1 , x2 , ... , xn] = 1 if there exists a move we can do on it such that the other player has a losing strategy
    // note that on every move we are removing some sticks so S = x1 + x2 + ... + xn is decreasing
    // Base case (S = 0): all heaps are empty and there is no move, so the state is L. Its XOR is 0, which matches the claim.
    // Step: assume the rule "XOR = 0 ⇔ L" holds for every state with total less than S. Take a state with total S.
    // If its XOR is 0, every move leads to a nonzero-XOR state (part 1 of the proof), and those smaller states are W by assumption. All moves lead to W, so this state is L.
    // If its XOR is nonzero, some move leads to a zero-XOR state (part 2), which is L by assumption. One move to an L state is enough, so this state is W.
    
    
   






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
    
  