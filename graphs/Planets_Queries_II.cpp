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
/*You are playing a game consisting of n planets. Each planet has a teleporter to another planet (or the planet itself).
You have to process q queries of the form: You are now on planet a and want to reach planet b. What is the minimum number of teleportations?
Input
The first input line contains two integers n and q: the number of planets and queries. The planets are numbered 1,2,\ldots,n.
The second line contains n integers t_1,t_2,\ldots,t_n: for each planet, the destination of the teleporter.
Finally, there are q lines describing the queries. Each line has two integers a and b: you are now on planet a and want to reach planet b.
Output
For each query, print the minimum number of teleportations. If it is not possible to reach the destination, print -1.
Constraints

1 \le n, q \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
2 3 2 3 2
1 2
1 3
1 4

Output:
1
2
-1*/
void solve() 
{
    ll n , qu ;
    cin >> n >> qu ;

    vector< vector < ll > > up(LOG , vector<ll>(n+1 , 0)) ;
    
    for(ll i = 1 ; i <= n ; i++)
    {
        ll a ; 
        cin >> a ; 
        up[0][i] = a ;
        // up [ j ] [ node ] = the 2^j th ancestor of node
    }
    for(ll k = 1 ; k < LOG ; k++)
    {
        for(ll node = 1 ; node <= n ; node++)
        {
            up[k][node] = up[k-1][up[k-1][node]] ;
        }
    }
    while(qu--)
    {
        
    }
    
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  