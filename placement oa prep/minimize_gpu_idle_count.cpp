/*
Minimize GPU Idle Count (Min-Max Continuous Sequence)

Problem Description:
You are given a string s consisting only of the characters 'a' and 'b', representing the usage sequence of two GPUs over time. The "idle count" of the system is defined as the maximum length of a contiguous block of identical characters (i.e., the longest continuous sequence of a single GPU running without the other).
You are also given an integer switchCount, which represents the maximum number of operations you can perform. In one operation, you can flip any character from 'a' to 'b' or from 'b' to 'a'.

Find the minimum possible idle count (maximum consecutive identical characters) you can achieve after performing at most switchCount operations.

Example:
Input: s = "aabbbaaaa", switchCount = 2
Output: 2
Explanation: Change the 4th character (b to a) and the 7th character (a to b). The string becomes "aabababaa". The longest contiguous block of identical characters is now 2 ("aa" at the start and the end).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
string s ; 
ll temp ; 
ll check(ll x)
{
    // this returns true if the idle count of x can be achieved  with at most switchCount operations
    ll n = s.size() ;
    if(x == 1)
    {
        if(temp >= n - 1)
        {
            return true ; 
        }
        else 
        {
            return false ; 
        }
    }
    ll idle = 1 ;
    ll switchCount = temp ; 
    char p = s[0] ;
    for(ll i = 1 ; i < n ; i++)
    {
        
        char c = s[i] ;
        if(c == p && idle < x)
        {
            idle++ ; 
            p = c ;
        }
        else if(c == p && idle == x)
        {
            switchCount-- ; 
            if(switchCount < 0)
            {
                return false ; 
            }
            idle = 1 ; 
            p = c ;
        }
        else 
        {
            p = c ; 
            idle = 1 ; 
        }

        
    }
    if (switchCount < 0)
    {
        return false ; 
    }
    return true ;
    

}
void solve() {

    cin >> s >> temp ; 
    ll n = s.size();
    ll lo = 1 , hi = n , ans = n;
    while(lo <= hi) 
    {
        ll mid = lo + (hi - lo) / 2;
        if(check(mid))
        {
            ans = mid ; 
            hi = mid - 1 ; 
        }
        else 
        {
            lo = mid + 1 ; 
        }
    }
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
