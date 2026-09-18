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

Consider a two player game where each player has n cards numbered 1,2,\dots,n. On each turn both players place one of their cards on the table. The player who placed the higher card gets one point. If the cards are equal, neither player gets a point. The game continues until all cards have been played.
You are given the number of cards n and the players' scores at the end of the game, a and b. Your task is to give an example of how the game could have played out.
Input
The first line contains one integer t: the number of tests.
Then there are t lines, each with three integers n, a and b.
Output
For each test case print YES if there is a game with the given outcome and NO otherwise.
If the answer is YES, print an example of one possible game. Print two lines representing the order in which the players place their cards. You can give any valid example.
Constraints

1 \le t \le 1000
1 \le n \le 100
0 \le a,b \le n

Example
Input:
5
4 1 2
2 0 1
3 0 0
2 1 1
4 4 1

Output:
YES
1 4 3 2
2 1 3 4
NO
YES
1 2 3
1 2 3
YES
1 2
2 1*/
void solve() 
{
    ll n ; 
    ll a , b ;
    cin >> n >> a >> b ;
    if(a + b > n)
    {
        pn ;
        return ;
    }
    if(a == 0 && b > 0)
    {
        pn ;
        return ;
    }
    if(b == 0 && a > 0)
    {
        pn ;
        return ;
    }
    vector < ll > v1 , v2 ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(i <= b)
        {
            v2.push_back(a + i ) ; 
            v1.push_back(i)  ;  
            // player 2 wins b times 
            // b - 1 + 1 
            // 1 , a + 1 
            // 2 , a + 2
            // ..
            // b , a + b
        }
        else if (i <= a + b)
        {
            v2.push_back(i - b) ; 
            v1.push_back(i) ; 
            // player 1 wins a times
            // a + b - b - 1 + 1 
            // b + 1 , 1
            // b + 2 , 2
            // .. 
            // b + a , a
        }
        else
        {
            v1.push_back(i) ; 
            v2.push_back(i) ; 
            
        }
    }
    py ; 
    for(auto& x : v1)
    {
        cout << x << " " ; 
    }
    cout << endl ;
    for(auto& x : v2)
    {
        cout << x << " " ;
    }
    cout << endl ;
   






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
    
  