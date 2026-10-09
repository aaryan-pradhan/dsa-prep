/*
IIT Roorkee Square Point (DQA) - Odd and Even Operations

Problem Description:
There is an array and we have to perform certain operations until the array becomes empty, and we want to maximize the score. 
- In an odd operation (1st, 3rd, 5th...), we add the sum of all elements present in the array at that time to the score.
- In an even operation (2nd, 4th, 6th...), we subtract the sum of all elements present in the array at that time from the score.
- After each operation, we must remove either the leftmost or the rightmost element from the array.

Return the maximum score that can be possible.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll s = 0 ; 

vector < ll > A ;
vector < vector < ll > > dp ;
ll rec( ll l , ll r)
{
    ll tu = A.size() - (r - l + 1) ;
    if(l > r)
    {
        return 0 ; 
    }
₹
    if(dp[l][r] != -1)
    {
        return dp[l][r] ; 
    }
    ll ans = 0 ; 
    if(tu%2)
    {
        ans = max(A[l] + rec(l + 1 , r) , A[r] + rec(l , r - 1)) ;

    }
    else 
    {
        ans = max(rec(l + 1 , r) , rec(l , r - 1) ) ;
    }
    dp[l][r] = ans ;
    return ans ;
}
void solve() 
{
    ll n ;
    cin >> n ;
    A.assign(n , 0) ;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> A[i] ;
    }
    dp.assign(n , vector < ll > (n , -1)) ;
    ll ans = rec(0 , n - 1) ;
    cout << ans << endl ;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
