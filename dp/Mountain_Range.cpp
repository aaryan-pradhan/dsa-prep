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
/*There are n mountains in a row, each with a specific height. You begin your hang gliding route from some mountain.
You can glide from mountain a to mountain b if mountain a is taller than mountain b and all mountains between a and b.
What is the maximum number of mountains you can visit on your route?
Input
The first line has an integer n: the number of mountains.
The next line has n integers h_1, h_2,\dots, h_n: the heights of the mountains.
Output:
Print one integer: the maximum number of mountains.
Constraints

1\le n \le 2 \cdot 10^5
1\le h_i \le 10^9

Example
Input:
10
20 15 17 35 25 40 12 19 13 12

Output:
5*/

const ll N = 2e5 + 5 ;
struct node{
    ll mx ; 
    node()
    {
        mx = 0 ;
    }
    ll idx ; 
};

node t[4 * N] ;
ll h[N] ;
ll n ; 
node merge(node a , node b)
{
    node res ;
    res.mx = max(a.mx , b.mx ) ;
    if(a.mx > b.mx)
    {
        res.idx = a.idx ;
    }
    else
    {
        res.idx = b.idx ;
    }
    return res ;
}
void build(ll id , ll l , ll r)
{
    // this builds the segment tree for maximum height in the range l to r both inclusive and stores it in t[id]
    if(l == r)
    {
        t[id].mx = h[l] ;
        t[id].idx = l ;
        return ; 
    }
    ll mid = l + (r - l) / 2 ;
    build(2 * id , l , mid ) ;
    build(2 * id + 1 , mid + 1 , r ) ; 
    t[id] = merge(t[2 * id] , t[2 * id + 1] ) ;
}
node query( ll id , ll l , ll r , ll lq , ll rq)
{
    // this returns the maximum height in the range lq to rq both inclusive from the segment tree
    if( rq < l || r < lq ) return node() ; // this means the range is completely outside the query range
    if( lq <= l && r <= rq ) return t[id] ; // this means the range is completely inside the query range
    ll mid = l + (r - l) / 2 ;
    node left = query(2 * id , l , mid , lq , rq ) ;
    node right = query(2 * id + 1 , mid + 1 , r , lq , rq ) ;
    return merge(left , right ) ;
}
ll rec(ll l , ll r )
{
    // this returns the maximum number of mountains that can be visited in the range l to r both inclusive
    if(l > r) return 0 ;
    node mx = query(1 , 0 , n - 1 , l , r ) ;
    ll idx = mx.idx ;
    ll maxi = mx.mx ;
    node left = query(1 , 0 , n - 1 , l , idx - 1 ) ;
    node right = query(1 , 0 , n - 1 , idx + 1 , r ) ;
    ll lm = left.mx ;
    ll rm = right.mx ;
    ll ans = 1 ; 
    if(lm == maxi)
    {
        ans = max(ans , rec(l , idx -1)) ; 
    }
    else 
    {
        ans = max(ans , 1 + rec(l , idx - 1 ) ) ;
    }
    if(rm == maxi)
    {
        ans = max(ans , rec(idx + 1 , r ) ) ;
    }
    else
    {
        ans = max(ans , 1 + rec(idx + 1 , r ) ) ;
    }
    return ans ;

}
void solve() 
{

    cin >> n ;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> h[i] ;
    }
    build(1 , 0 , n - 1 ) ;
    cout << rec(0 , n - 1 ) << endl ;



   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  