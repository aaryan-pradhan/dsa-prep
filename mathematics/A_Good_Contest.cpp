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
/*The next programming contest has three problems and 𝑛
 participants.

Problem 1
 is easy, problem 2
 is medium, and problem 3
 is hard.

A participant is called weak if they did not solve all three problems.

Unfortunately, the scoreboard was lost. The only remaining information is an array 𝑎
 of length 3
, where 𝑎𝑖
 is the number of participants who solved problem 𝑖
.

Among all scoreboards consistent with this information, find the minimum possible number of weak participants.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤3000
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤9
) — the number of participants.

The second line of each test case contains three integers 𝑎1,𝑎2,𝑎3
 (0≤𝑎𝑖≤𝑛
), where 𝑎𝑖
 is the number of participants who solved problem 𝑖
.

Output
For each test case, print a single integer — the minimum possible number of weak participants.

Example
InputCopy
6
3
3 3 3
4
4 4 3
1
1 1 1
9
9 8 9
5
0 5 5
6
4 3 2
OutputCopy
0
1
0
1
5
4
Note
In the first test case, all 3
 participants can have solved all three problems, so the answer is 0
.

In the second test case, participant 1
 could have solved only problems 1
 and 2
, while participants 2
, 3
, and 4
 solved all three problems. Therefore, participant 1
 is the only participant who is weak, so the answer is 1
. It can be shown that this is minimal.*/
void solve() 
{
    
   ll n ; 
   cin >> n ;
   ll maxi = 0 ;
   for(ll i = 0 ; i < 3 ; i++)
   {
       ll x ; 
       cin >> x ;
       maxi = max(maxi , n - x ) ; 
   }
   cout << maxi << endl ;






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
    
  
