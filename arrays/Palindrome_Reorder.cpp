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
/*Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
Input
The only input line has a string of length n consisting of characters A–Z.
Output
Print a palindrome consisting of the characters of the original string. You may print any valid solution. If there are no solutions, print "NO SOLUTION".
Constraints

1 \le n \le 10^6

Example
Input:
AAAACACBA

Output:
AACABACAA*/
void solve() 
{

   string s ; 
   cin >> s ;
   ll n = s.size() ;
   vector < ll > v(26, 0) ;
   for(ll i = 0 ; i < n ; i++)
   {
        v[s[i] - 'A']++ ;
   }
   ll odd = 0 , index = -1  ; 
   for(ll i = 0 ; i < 26 ; i++)
   {
        if(v[i] % 2 == 1)
        {
            odd++ ;
            index = i ;
        }
   }
   if(odd > 1)
   {
        cout << "NO SOLUTION" << endl ;
        return ;
   }
   deque < char > dq ;
   if(index != -1)
   {
        dq.push_back('A' + index) ;
   }
   v[index]-- ;
   for(ll i = 0 ; i < 26 ; i++)
   {
        while(v[i] > 0)
        {
            dq.push_front('A' + i) ;
            dq.push_back('A' + i) ;
            v[i] -= 2 ;
        }
   }
   for(auto& x : dq)
   {
        cout << x ;
   }
   cout << endl ;







}
signed main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    solve() ; 
}
    
  