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
/*Time limit: 1.00 s Memory limit: 512 MB
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65*/
vector < vector < ll > > v(8, vector < ll >(8, 0)) ;
ll ans = 0 ;
bool check(ll row , ll col)
{
    for(ll i = 0 ; i < row ; i++)
    {
        if(v[i][col] == 1)
        {
            return false ;
        }
    }
    for(ll i = row - 1 , j = col - 1 ; i >= 0 && j >= 0 ; i-- , j--)
    {
        if(v[i][j] == 1)
        {
            return false ;
        }
    }
    for(ll i = row - 1 , j = col + 1 ; i >= 0 && j < 8 ; i-- , j++)
    {
        if(v[i][j] == 1)
        {
            return false ;
        }
    }
    return true ;
}
ll rec(ll row)
{
    // this function will return the number of ways to place queens from row to 7
    if(row == 8)
    {
        return 1 ;
    }
    ll cnt = 0 ;
    for(ll col = 0 ; col < 8 ; col++)
    {
        if(v[row][col] == 0 && check(row , col))
        {
            v[row][col] = 1 ;
            cnt += rec(row + 1) ;
            v[row][col] = 0 ;
        }
    }
    return cnt ;
}
void solve() 
{
    for(ll i = 0 ; i < 8 ; i++)
    {
        string s ; 
        cin >> s ;
        for(ll j = 0 ; j < 8 ; j++)
        {
            if(s[j] == '*')
            {
                v[i][j] = 2 ;
            }
        }
    }
    ans = rec(0) ;
    cout << ans << endl ;
    
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  