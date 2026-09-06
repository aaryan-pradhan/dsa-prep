// orz
#include <bits/stdc++.h>
#define LOG 30
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
Your task is to process q queries of the form: when you begin on planet x and travel through k teleporters, which planet will you reach?
Input
The first input line has two integers n and q: the number of planets and queries. The planets are numbered 1,2,\dots,n.
The second line has n integers t_1,t_2,\dots,t_n: for each planet, the destination of the teleporter. It is possible that t_i=i.
Finally, there are q lines describing the queries. Each line has two integers x and k: you start on planet x and travel through k teleporters.
Output
Print the answer to each query.
Constraints

1 \le n, q \le 2 \cdot 10^5
1 \le t_i \le n
1 \le x \le n
0 \le k \le 10^9

Example
Input:
4 3
2 1 1 4
1 2
3 4
4 1

Output:
1
2
4*/
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
        // for each node, we will find the 2^k th ancestor of that node
        // 2^k th ancestor of node = 2^(k-1) th ancestor of 2^(k-1) th ancestor of node
        for(ll node = 1 ; node <= n ; node++)
        {
            // 2 raise to k-1th ancestor of all nodes is already calculated in the previous iteration, so we can use that to calculate the 2^k th ancestor of all nodes
            up[k][node] = up[k-1][up[k-1][node]] ;
        }
    }
    while(qu--)
    {
        ll node , k ; 
        cin >> node >> k ;
        for(ll j = LOG ; j >= 0 ; j--)
        {
            // if the jth bit of k is set, we will move to the 2^j th ancestor of node
            ll bit = (k >> j) & 1 ;
            if(bit)
            {
                node = up[j][node] ;
            }
        }
        cout << node << endl ;
    }
    




    



   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  