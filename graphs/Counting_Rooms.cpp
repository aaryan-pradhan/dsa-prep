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
/*You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3*/
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
vector<vector<ll>> vis;
vector<string> v;
ll c = 0 ; 
void dfs(ll x, ll y, ll n, ll m)
{
    vis[x][y] = c;
    for(ll i = 0 ; i < 4 ; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && v[nx][ny] == '.')
        {
            dfs(nx, ny, n, m);
        }
    }
}
void solve() 
{
    ll n ,m;
    cin >> n >> m;
    vis.resize(n, vector<ll>(m, 0));
    v.resize(n);
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }

    for (ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(!vis[i][j] && v[i][j] == '.')
            {
                c++;
                dfs(i, j, n, m);
            }
        }
    }
    ll maxi = 0 ;
    for (ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            maxi = max(maxi, vis[i][j]);
        }
    }
    cout << maxi << endl;



   







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  