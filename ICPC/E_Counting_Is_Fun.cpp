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

using namespace std ; 

struct node{
    ll mn ; 
    ll idx ; 
    node()
    {
        mn = INF ; 
    }
}; 
const int MAX = 200005 ;
node seg[4 * MAX] ;
ll arr[MAX] ;
ll n ; 
vector < pll > ns ; 
node merge(node a , node b)
{
    node ans ; 
    ans.mn = min(a.mn , b.mn) ; 
    if(ans.mn == a.mn)
    {
        ans.idx = a.idx ; 
    }
    else
    {
        ans.idx = b.idx ; 
    }
    return ans ; 
}
void build(ll id , ll l , ll r)
{
    if(l == r)
    {
        seg[id].mn = arr[l] ; 
        seg[id].idx = l ; 
        return ; 
    }
    ll mid = (l + r) / 2 ;
    build(id * 2 , l , mid) ;
    build(id * 2 + 1 , mid + 1 , r) ;
    seg[id] = merge(seg[id * 2] , seg[id * 2 + 1]) ; 
}
node query(ll id , ll l , ll r , ll lq , ll rq)
{
    if ( lq > r || rq < l )
    {
        return node() ; 
    }
    if( lq <= l && r <= rq )
    {
        return seg[id] ; 
    }
    ll mid = (l + r) / 2 ;
    node left = query(id * 2 , l , mid , lq , rq) ; 
    node right = query(id * 2 + 1 , mid + 1 , r , lq , rq) ; 
    return merge(left , right) ;
}

ll rec(ll l , ll r)
{
    if(l > r)
    {
        return 0 ; 
    }
    if(l == r)
    {
        return 0 ; 
    }
    cout << "l = " << l << " r = " << r << endl ;
    node ans = query(1 , 1 , n , l , r) ;
    ll idx = ans.idx ;
    ll min = ans.mn ;
    cout << "idx = " << idx << " min = " << min << endl ;
    ll cost = 0 ; 
    if( idx > l ) 
    {
        cost += abs(ns[idx].fr - ns[idx - 1].fr) * min ;
    }
    if( idx < r )
    {
        cost += abs(ns[idx].fr - ns[idx + 1].fr) * min ; 
    }
    cost += rec(l , idx - 1) ;
    cost += rec(idx + 1 , r) ;
    cout << "cost = " << cost << endl ;
    return cost ;
}

void solve() 
{

    cin >> n ;  
    ns.resize(n + 1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> ns[i].fr ; 
        // this is pos
    }
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> ns[i].sc ;
        // this is cost 
    }
    sort(ns.begin() + 1 , ns.end(), [&](pll a , pll b)
    {
        return a.fr < b.fr ;
    }) ;
    // for(auto x : ns)
    // {
    //     cout << x.fr << " " << x.sc << endl ; 
    // }
    for( ll i = 1 ; i <= n ; i++)
    {
        arr[i] = ns[i].sc ;
    }
    build(1 , 1 , n) ;
    cout << rec(1 , n) << endl ;


   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t ; 
    cin >> t ;
    while(t--)
    {
        solve() ; 
    }
}
    
  