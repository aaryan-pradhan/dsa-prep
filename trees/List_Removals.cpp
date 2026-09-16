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

You are given a list consisting of n integers. Your task is to remove elements from the list at given positions, and report the removed elements.
Input
The first input line has an integer n: the initial size of the list. During the process, the elements are numbered 1,2,\dots,k where k is the current size of the list.
The second line has n integers x_1,x_2,\dots,x_n: the contents of the list.
The last line has n integers p_1,p_2,\dots,p_n: the positions of the elements to be removed.
Output
Print the elements in the order they are removed.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x_i \le 10^9
1 \le p_i \le n-i+1

Example
Input:
5
2 6 1 4 2
3 1 3 1 1

Output:
1 2 2 6 4

Explanation: The contents of the list are [2,6,1,4,2], [2,6,4,2], [6,4,2], [6,4], [4] and [].*/
ll n ; 
vector < ll > arr ;
struct stnode{
    ll sum ;
    stnode()
    {
        sum = 0 ; 
    }
};
vector < stnode > st ;
stnode merge(stnode a , stnode b)
{
    stnode res ;
    res.sum = a.sum + b.sum ;
    return res ;
}
void build(ll id , ll l , ll r)
{
    if(l == r)
    {
        st[id].sum = 1 ; 
    }
    else   
    {
        ll mid = l + ( r - l) / 2 ;
        build(2 * id , l , mid) ;
        build(2 * id + 1 , mid + 1 , r) ;
        st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
    }
}
void update(ll id , ll l , ll r , ll pos)
{
    if(pos < l )
    {
        return ; 
    }
    else if (pos > r)
    {
        return ; 
    }
    else if(l == r && l == pos)
    {
        st[id].sum = 0 ; 
        return ; 
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        update(2 * id , l , mid , pos) ;
        update(2 * id + 1 , mid + 1 , r , pos) ;
        st[id] = merge(st[2 * id] , st[2 * id + 1]) ;
    }
}
ll query(ll id , ll l , ll r , ll k)
{
    if(k > st[id].sum)
    {
        // if k is greater than the number of elements in the current segment, then we cannot find the kth element in this segment, so we return -1
        return -1 ; 
    }
    else if(l == r && k == 1)
    {
        return l ; 
    }
    else if(l == r && k != 1)
    {
        return -1 ; 
    }
    else
    {
        ll mid = l + (r - l) / 2 ;
        if(st[2 * id].sum >= k)
        {
            return query(2 * id , l , mid , k) ;
        }
        else
        {
            // if the number of elements in the left child is less than k, then we need to find the (k - st[2 * id].sum)th element in the right child, because we have already counted st[2 * id].sum elements in the left child
            return query(2 * id + 1 , mid + 1 , r , k - st[2 * id].sum) ;
        }
    }
}

void solve() 
{
    
    cin >> n ; 
    arr.resize(n + 1) ;
    st.resize(4 * n + 5) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> arr[i] ;
    }
    build(1 , 1 , n) ;
    for(ll i = 1 ; i <= n ; i++)
    {
        ll k ; 
        cin >> k ; 
        ll index = query(1 , 1 , n , k) ;
        cout << arr[index] << " " ;
        update(1 , 1 , n , index) ;
    }
   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  