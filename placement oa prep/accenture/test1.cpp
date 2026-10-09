/*TLDR
1 sec

Time Limit

256 MB

Memory

0/100

Score

Description
Given a matrix of size 
N
∗
M
N∗M with each cell containing a character, 
′
T
′
,
′
L
′
,
′
D
′
o
r
′
R
′
′
 T 
′
 , 
′
 L 
′
 , 
′
 D 
′
 or 
′
 R 
′
  denoting directions up, left, down and right.

From a cell with character 
T
T, one can move to the top cell.
From a cell with character 
L
L, one can move to the left cell.
From a cell with character 
D
D, one can move to the bottom cell.
From a cell with character 
R
R, one can move to the right cell.
Alice and Bob are at cell 
A
(
x
A
,
y
A
)
A(x 
A
​
 ,y 
A
​
 ) and wants to work together to reach some common cell(
≠
A

=A). But there is a constraint, if they choose to reach some cell 
B
B, Alice follows the directional characters from 
A
A and reach 
B
B, Bob cannot pass through any of the cells Alice passed through other than the destination itself which is 
B
B. As can be understood, it is not possible for Bob to do so following the directional characters, so he decides to disobey the directions sometimes to reach 
B
B from 
A
A. Given cell 
A
A, choose a cell 
B
B for them so that Bob has to disobey the directions a minimum number of times. Answer for 
T
T testcases.

Note: The paths taken by Alice and Bob from 
A
A to 
B
B should be simple paths. Also note that if cell 
B
B is chosen as the cell directed at by cell 
A
A, Bob cannot simply follow that 
1
1 step path as Alice.

Input Format
The first line contains a single integer 
T
T - the number of testcases.
T
T testcases follows, where,
The first line of each testcase contains 4 integers, 
N
N, 
M
M, 
x
A
x 
A
​
  and 
y
A
y 
A
​
 .
N
N line follows where each line contains a string of length 
M
M representing the characters that each cell contains.

Output Format
For each testcase, output a single line representing the minimum number of times Bob has to disobey the directional characters.

Constraints
1
≤
T
≤
1000
1≤T≤1000
4
≤
4≤ sum of 
N
∗
M
N∗M across all tests 
≤
1
0
6
≤10 
6
 
2
≤
N
,
M
≤
1
0
3
2≤N,M≤10 
3
 
Sample Input 1
2
3 3 3 1
RRL
TDT
TRT
2 2 1 2
LD
LT
Sample Output 1
1
3
Note
For the first testcase, we can choose cell 
B
B as (1,3). The path taken by Bob will be (3,1) -> (3,2) -> (3,3) -> (2,3) -> (1,3).He disobeys the direction only one time.

For the second testcase, we can choose cell 
B
B as (2,2). The path taken by Bob will be (1,2) -> (1,1) -> (2,1) -> (2,2). He disobeys the direction 3 times.*/

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

ll n , m , xA , yA;
ll dx[] = {-1 , 0 , 1 , 0};
ll dy[] = {0 , -1 , 0 , 1};

vector<vector<pll>> g;

ll enc(ll x , ll y)
{
    return x * m + y + 1;
}

bool check(ll x , ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

pll dir(char c)
{
    if(c == 'T') return {-1 , 0};
    if(c == 'L') return {0 , -1};
    if(c == 'D') return {1 , 0};
    return {0 , 1};
}

void dfs(ll v , vector<bool> &vis , vector<ll> &path)
{
    vis[v] = true;
    path.push_back(v);

    for(auto [cost , u] : g[v])
    {
        if(cost == 0 && !vis[u])
        {
            dfs(u , vis , path);
            break;
        }
    }
}

void bG(vector<string> &grid)
{
    g.assign(n * m + 2 , {});

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < m ; j++)
        {
            pll d = dir(grid[i][j]);

            for(ll k = 0 ; k < 4 ; k++)
            {
                ll nx = i + dx[k];
                ll ny = j + dy[k];

                if(!check(nx , ny))
                    continue;

                ll cost = (d.fr == dx[k] && d.sc == dy[k] ? 0 : 1);

                g[enc(i , j)].push_back({cost , enc(nx , ny)});
            }
        }
    }
}

void super(vector<ll> &path)
{
    ll S = n * m + 1;

    if(path.size() >= 2)
        g[path[1]].clear();

    for(ll i = 2 ; i < path.size() ; i++)
    {
        ll node = path[i];
        g[node].clear();
        g[node].push_back({0 , S});
    }
}
ll bfs()
{
    ll st = enc(xA , yA);
    ll S = n * m + 1;

    vector<ll> dist(n * m + 2 , INF);
    deque<ll> dq;

    dist[st] = 0;
    dq.push_back(st);

    while(!dq.empty())
    {
        ll u = dq.front();
        dq.pop_front();

        for(auto [cost , v] : g[u])
        {
            if(dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;

                if(cost == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }

    return dist[S];
}

void solve()
{
    cin >> n >> m >> xA >> yA;

    xA--;
    yA--;

    vector<string> grid(n);

    for(ll i = 0 ; i < n ; i++)
        cin >> grid[i];

    bG(grid);

    vector<bool> vis(n * m + 2 , false);
    vector<ll> path;

    dfs(enc(xA , yA) , vis , path);

    super(path);

    cout << bfs() << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while(t--)
        solve();
}