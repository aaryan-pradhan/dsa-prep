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
/*
You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.
Input
The first input line has two integers n and m: the height and width of the map.
After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.
Output
First print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R). You can print any path, as long as its length is at most n \cdot m steps.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Output:
YES
5
RRDDR
*/
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

void solve() 
{
    ll n , m ;
    cin >> n >> m ;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<ll>> distM(n, vector<ll>(m, -INF));
    vector<vector<ll>> distA(n, vector<ll>(m, -INF));
    vector<vector<pll>> par(n, vector<pll>(m, {-1, -1}));
    queue <pll > qm ; 
    queue <pll > qa ;
    for (ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            cin >> grid[i][j] ;
            if (grid[i][j] == 'M')
            {
                distM[i][j] = 0 ;
                qm.push({i, j}) ;
            }
            else if (grid[i][j] == 'A')
            {
                distA[i][j] = 0 ;
                qa.push({i, j}) ;
                par[i][j] = {-1, -1} ;
            }

        }
    }
    while(!qm.empty())
    {
        pll node = qm.front() ;
        qm.pop() ;
        for (ll i = 0 ; i < 4 ; i++)
        {
            ll nx = node.fr + dx[i] ;
            ll ny = node.sc + dy[i] ;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && distM[nx][ny] == -INF)
            {
                distM[nx][ny] = distM[node.fr][node.sc] + 1 ;
                qm.push({nx, ny}) ;
            }
        }
    }
    while(!qa.empty())
    {
        pll node = qa.front() ;
        qa.pop() ;
        for (ll i = 0 ; i < 4 ; i++)
        {
            ll nx = node.fr + dx[i] ;
            ll ny = node.sc + dy[i] ;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && distA[nx][ny] == -INF)
            {
                par[nx][ny] = {node.fr, node.sc} ;
                distA[nx][ny] = distA[node.fr][node.sc] + 1 ;
                qa.push({nx, ny}) ;
            }
        }
    }
    for (ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if(distA[i][j] != -INF && (distM[i][j] == -INF || distA[i][j] < distM[i][j]))
                {
                    py ; 
                    vector<char> ans ;
                    pll node = {i, j} ;
                    while(node.fr != -1 && node.sc != -1)
                    {
                        pll pnode = par[node.fr][node.sc] ;
                        if(pnode.fr != -1 && pnode.sc != -1)
                        {
                            if(pnode.fr == node.fr + 1)
                            {
                                ans.push_back('U') ;
                            }
                            else if(pnode.fr == node.fr - 1)
                            {
                                ans.push_back('D') ;
                            }
                            else if(pnode.sc == node.sc + 1)
                            {
                                ans.push_back('L') ;
                            }
                            else if(pnode.sc == node.sc - 1)
                            {
                                ans.push_back('R') ;
                            }
                        }
                        node = pnode ;
                    }
                    reverse(ans.begin(), ans.end()) ;
                    cout << ans.size() << endl ;
                    for(auto x : ans)
                    {
                        cout << x ;
                    }
                    cout << endl ;
                    return ; 
                }
            }
        }
    }
    pn ; 

    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  