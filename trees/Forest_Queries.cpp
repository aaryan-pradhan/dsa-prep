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

You are given an n \times n grid representing the map of a forest. Each square is either empty or contains a tree. The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).
Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?
Input
The first input line has two integers n and q: the size of the forest and the number of queries.
Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.
Finally, there are q lines describing the queries. Each line has four integers y_1, x_1, y_2, x_2 corresponding to the corners of a rectangle.
Output
Print the number of trees inside each rectangle.
Constraints

1 \le n \le 1000
1 \le q \le 2 \cdot 10^5
1 \le y_1 \le y_2 \le n
1 \le x_1 \le x_2 \le n

Example
Input:
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2

Output:
3
1
2*/
void solve() 
{
    ll n , q ; 
    cin >> n >> q ; 
    vector < vector < ll > > f(n + 1 , vector < ll > (n + 1 , 0)) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            char c ; 
            cin >> c ; 
            if(c == '*')
            {
                f[i][j] = 1 ; 
            }
        }
    }
    vector < vector < ll > > ps(n + 1 , vector < ll > (n + 1 , 0)) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            ps[i][j] = f[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] ;
        }
    }
    while(q--)
    {
        ll y1 , x1 , y2 , x2 ; 
        cin >> y1 >> x1 >> y2 >> x2 ; 
        cout << ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1] << endl ;
    }
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  