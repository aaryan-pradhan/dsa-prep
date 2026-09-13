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
/*You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. Your reward for a task is d-f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?
Input
The first input line has an integer n: the number of tasks.
After this, there are n lines that describe the tasks. Each line has two integers a and d: the duration and deadline of the task.
Output
Print one integer: the maximum reward.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a,d \le 10^6

Example
Input:
3
6 10
8 15
5 12

Output:
2*/
void solve() 
{
    ll n ; 
    cin >> n ; 
    vector < ll > f(n) ;
    ll d = 0 ; 
    for (ll i = 0 ; i < n ; i++)
    {
        ll a , b ;
        cin >> a >> b ;
        f[i] = a ;
        d += b ; 
    }
    sort(f.begin() , f.end()) ;
    
    for (ll i = 0 ; i < n ; i++)
    {
        if(i)   f[i] += f[i-1] ; 
    }
    for(ll i = 0 ; i < n ; i++)
    {
        d -= f[i] ; 
    }
    cout << d << endl ;
    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  