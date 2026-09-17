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
ll n ; 
/*Time limit: 1.00 s
Memory limit: 512 MB

The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.
The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
Your task is to find a solution that minimizes the number of moves.
Input
The only input line has an integer n: the number of disks.
Output
First print an integer k: the minimum number of moves.
After this, print k lines that describe the moves. Each line has two integers a and b: you move a disk from stack a to stack b.
Constraints

1 \le n \le 16

Example
Input:
2

Output:
3
1 2
1 3
2 3*/
vector < pll > ans ;
void rec( ll nod , ll from , ll aux , ll to)
{
    // this function will move nod disks from stack a to stack c using stack b as auxiliary
    if(nod==1)
    {
        ans.push_back({from,to}) ;
        return ;
    }
    else 
    {
        rec(nod-1,from,to,aux) ;
        ans.push_back({from,to}) ;
        rec(nod-1,aux,from,to) ;
    }


    

}
void solve() 
{
    cin >> n ;
    rec(n,1,2,3) ;
    cout << ans.size() << endl ;
    for(auto& x : ans)
    {
        cout << x.fr << " " << x.sc << endl ;
    }

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  