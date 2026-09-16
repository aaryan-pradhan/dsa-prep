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
/*Given an array of n integers, your task is to process q queries of the following types:

increase each value in range [a,b] by u
what is the value at position k?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Finally, there are q lines describing the queries. The format of each line is either "1 a b u" or "2 k".
Output
Print the result of each query of type 2.
Constraints

1 \le n,q \le 2 \cdot 10^5
1 \le x_i, u \le 10^9
1 \le k \le n
1 \le a \le b \le n

Example
Input:
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

Output:
5
6*/
ll n , q ; 
vector < ll > arr ;

struct stnode{
    ll sum ; 
    ll lazy ;
    stnode()
    {
        sum = 0 ; 
        lazy = 0 ; 
    }
};
vector < stnode > st ;
stnode merge(stnode a , stnode b)
{
    stnode res ;
    res.sum = a.sum + b.sum ;
    return res ;
}
void push(ll id , ll l , ll r)
{
    if(st[id].lazy != 0)
    {
        st[id].sum += (r - l + 1) * st[id].lazy ;
        if(l != r)
        {
            st[2 * id].lazy += st[id].lazy ;
            st[2 * id + 1].lazy += st[id].lazy ;
        }
        st[id].lazy = 0 ;
    }
}
void build(ll id , ll l , ll r)
{
    if(l == r)
    {
        st[id].sum = arr[l] ; 
        return ; 
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        build(2 * id , l , mid) ; 
        build(2 * id + 1 , mid + 1 , r) ;
        st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
    }
    
}
void update(ll id, ll l , ll r , ll lq , ll rq, ll val)
{
    push(id , l , r) ;
    if(rq < l || lq > r)
    {
        return ; 
    }
    else if(lq <= l && r <= rq)
    {
        st[id].lazy += val ;
        // why do we need to push here? because we need to update the current node's sum value as well, since we are adding a lazy value to it. If we don't push here, the sum value will not be updated and will be incorrect when we query it later.
        push(id , l , r) ;
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        update(2 * id , l , mid , lq , rq, val) ; 
        update(2 * id + 1 , mid + 1 , r , lq , rq, val) ;
        st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
    }
}
void query(ll id , ll l , ll r , ll pos)
{
    push(id , l , r) ;
    if(pos < l || pos > r)
    {
        return ; 
    }
    else if(l == r && l == pos)
    {
        cout << st[id].sum << endl ;
        return ; 
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        query(2 * id , l , mid , pos) ; 
        query(2 * id + 1 , mid + 1 , r , pos) ;
    }
}
void solve() 
{
    cin >> n >> q ;
    arr.resize(n+1) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> arr[i] ;
    }
    st.resize(4 * n + 5) ;
    build(1 , 1 , n) ;
    while(q--)
    {
        ll type ; 
        cin >> type ; 
        if(type == 1)
        {
            ll a , b , u ; 
            cin >> a >> b >> u ;
            update(1 , 1 , n , a , b , u) ;
        }
        else
        {
            ll k ; 
            cin >> k ; 
            query(1 , 1 , n , k) ;
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
    
  