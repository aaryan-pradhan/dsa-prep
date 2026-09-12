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

There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.
You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.
What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
Input
The first input line contains an integer n: the number of customers.
Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.
Output
Print first an integer k: the minimum number of rooms required.
After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,\ldots,k. You can print any valid solution.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a \le b \le 10^9

Example
Input:
3
1 2
2 4
4 4

Output:
2
1 2 1*/
void solve() 
{
    ll n ; 
    cin >> n ; 
    vector < array<ll, 3> > v ; 
    for( ll i = 0 ; i < n ; i++ ) 
    {
        ll a , b ; 
        cin >> a >> b ; 
        v.push_back({a , 1, i }) ; 
        v.push_back({b , -1, i }) ;
        
    }
    sort( v.begin() , v.end() , [&]( const array<ll, 3> &a , const array<ll, 3> &b ) 
    {
        if( a[0] != b[0] ) 
            return a[0] < b[0] ;
        return a[1] > b[1] ;
    }) ;
    ll c = 0 , k = 0 ;
    for( const auto &x : v)
    {
        c += x[1] ; 
        k = max( k , c ) ;
    }
    cout << k << endl ;
    vector < ll > ans(n) ;
    vector < ll > rooms(k) ;
    for( ll i = 0 ; i < k ; i++ ) 
        rooms[i] = k - i  ;
    for(const auto &x : v ) 
    {
        ll type = x[1] , idx = x[2] ;
        if( type == 1 )
        {
            // it is the arrival 
            ans[idx] = rooms.back() ;
            // remove the room from the available rooms
            rooms.pop_back() ;
        }
        else 
        {
            // it is the departure 
            rooms.push_back(ans[idx]) ;
        }
    }
    for (const auto &x : ans ) 
        cout << x << " " ;
    cout << endl ;
    
    

    

   






}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  