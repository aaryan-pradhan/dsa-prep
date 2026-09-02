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
/*Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.
Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.
Input
The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n. City 1 is Syrjälä, and city n is Lehmälä.
After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.
Output
First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
2 5
1 3
3 4
4 5

Output:
4
1 3 4 5*/
// ll n , m ;
// vector<vector<ll>> g ;
// vector<ll> dp ; 
// ll rec(ll node)
// {
//     if(dp[node] != -1)
//     {
//         return dp[node] ;
//     }
//     if(node == n)
//     {
//         return dp[node] = 1 ; 
//     }
//     ll ans = 0 ; 
//     for(auto child : g[node])
//     {
//        ll r = rec(child) ;
//        // if r==0 then you can't reach
//        if(r != 0)
//        {
//             ans = max(ans, r + 1) ;
//        }
//     }
//     return dp[node] = ans ; 

// }
void solve() 
{

    ll n , m ;
    cin >> n >> m ;
    vector<vector<ll>> g(n + 1) ;
    vector<ll> dp(n + 1, -1) ;


    vector<ll> topo ;
    vector<ll> indeg(n + 1, 0) ;
    for(ll i = 0 ; i < m ; i++)
    {
        ll a , b ; 
        cin >> a >> b ;
        g[a].push_back(b) ;
        indeg[b]++ ;
    }
    
    queue <ll> q ;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i) ;
        }
    }

    while(!q.empty())
    {
        ll node = q.front() ;
        q.pop() ;
        topo.push_back(node) ;
        for(auto child : g[node])
        {
            indeg[child]-- ;

            if(indeg[child] == 0)
            {
                q.push(child) ;

            }
        }
    }

    
    reverse(topo.begin(), topo.end()) ;
    for(auto node : topo)
    {
        if(node == n)
        {
            dp[node] = 1 ;
        }
        else 
        {
            ll ans = 0 ;
            for(auto child : g[node])
            {
                ll r = dp[child] ;
                if(r != 0)
                {
                    ans = max(ans, r + 1) ;
                }
            }
            dp[node] = ans ;

        }  
    }
    if(dp[1] == 0)
    {
        cout << "IMPOSSIBLE" << endl ;
        return ; 
    }
    cout << dp[1] << endl ;
    ll node = 1 ;
    while(node != n)
    {
        cout << node << " " ;
        for(auto child : g[node])
        {
            if(dp[child] == dp[node] - 1)
            {
                node = child ;
                break ; 
            }
        }
    }
    cout << n << endl ;



   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  