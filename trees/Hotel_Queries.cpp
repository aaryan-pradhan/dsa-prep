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
/*Time limit: 1.00 s
Memory limit: 512 MB

There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.
The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.
Input
The first input line contains two integers n and m: the number of hotels and the number of groups. The hotels are numbered 1,2,\ldots,n.
The next line contains n integers h_1,h_2,\ldots,h_n: the number of free rooms in each hotel.
The last line contains m integers r_1,r_2,\ldots,r_m: the number of rooms each group requires.
Output
Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.
Constraints

1 \le n,m \le 2 \cdot 10^5
1 \le h_i \le 10^9
1 \le r_i \le 10^9

Example
Input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

Output:
3 5 0 1 1*/
ll n , q ;
vector < ll > h ; 
vector < ll > r ;
struct stnode{
    ll mx ; 
    stnode()
    {
        mx = -INF; 
    }
};
vector < stnode > st ;
stnode merge(stnode a , stnode b)
{
    stnode res ;
    res.mx = max(a.mx , b.mx) ;
    return res ;
}
void build( ll id , ll l , ll r)
{
    if(l == r)
    {
        st[id].mx = h[l] ;
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
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l )
    {
        return ; 
    }
    else if(pos > r)
    {
        return ; 
    }
    else if(l == r && l == pos)
    {
        st[id].mx = val ; 
        return ; 
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        update(2 * id , l , mid , pos , val) ; 
        update(2 * id + 1 , mid + 1 , r , pos , val) ;
        st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
    }
}
ll query(ll id , ll l , ll r , ll val)
{
    if(st[id].mx < val)
    {
        // if the maximum value in this segment is less than val, then there is no hotel in this segment that can accommodate the group, so we return 0
        return -1 ;
    }
    else if(l == r)
    {
        // we are at a leaf node, so we return the index of the hotel
        if(st[id].mx >= val)
        {
            return l ; 
        }
        else
        {
            return -1 ; 
        }
        
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        // we first check the left child, because we want to find the first hotel that can accommodate the group
        ll left = query(2 * id , l , mid , val) ; 
        if(left != -1)
        {
            return left ; 
        }
        else
        {
            return query(2 * id + 1 , mid + 1 , r , val) ;
        }
    }

}
void solve() 
{
    
    cin >> n >> q ;
    h.resize(n + 1) ;
    r.resize(q + 1) ;
    st.resize(4 * n + 5) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> h[i] ;
    }
    build(1 , 1 , n) ;
    for(ll i = 1 ; i <= q ; i++)
    {
        cin >> r[i] ;
        ll hotel = query(1 , 1 , n , r[i]) ;
        if(hotel == -1)
        {
            cout << 0 << " " ;
        }
        else
        {
            cout << hotel << " " ;
            h[hotel] -= r[i] ;
            update(1 , 1 , n , hotel , h[hotel]) ;
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
    
  