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
/*You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU*/
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
void solve() 
{
    ll n , m ;
    cin >> n >> m ; 
    vector<vector<ll>> dist(n, vector<ll>(m, -INF));
    vector<vector<pll>> par(n, vector<pll>(m, mp(-1, -1)));
    vector<string> a(n);

    for(ll i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(a[i][j] == 'A')
            {
                queue<pll> q ;
                q.push(mp(i, j));
                dist[i][j] =  0; 
                par[i][j] = mp(-1, -1) ;
                while(!q.empty())
                {
                    pll p = q.front() ;
                    q.pop() ;
                    ll x = p.fr ;
                    ll y = p.sc ;
                    for(ll k = 0 ; k < 4 ; k++)
                    {
                        ll nx = x + dx[k];
                        ll ny = y + dy[k];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -INF && a[nx][ny] != '#')
                        {
                            dist[nx][ny] = dist[x][y] + 1;
                            par[nx][ny] = mp(x, y) ; 
                            q.push(mp(nx, ny));
                        }
                    }
                }
            }
        }
    }
    
    
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            if(a[i][j] == 'B')
            {
                if(dist[i][j] == -INF)
                {
                    pn ; 
                    return ;
                }
                else
                {
                    py ; 
                    cout << dist[i][j] << endl ;
                    ll cx = i ;
                    ll cy = j ;
                    string ans = "" ;

                    while (a[cx][cy] != 'A')
                    {
                        ll parx = par[cx][cy].fr ;
                        ll pary = par[cx][cy].sc ;
                        if(parx == cx)
                        {
                            if(pary < cy)
                            {
                                ans += 'R' ; 
                            }
                            else
                            {
                                ans += 'L' ; 
                            }
                        }
                        else
                        {
                            if(parx < cx)
                            {
                                ans += 'D' ; 
                            }
                            else
                            {
                                ans += 'U' ; 
                            }
                        }
                        cx = parx ;
                        cy = pary ;
                    }

                    reverse(ans.begin(), ans.end()) ;
                    cout << ans << endl ;
                }
            }
        }
    }

    


    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  