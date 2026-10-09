/*
 * Eternal IIT ISM Dhanbad (SDE)
 * Problem 1: Second Most Frequent Element
 *
 * Description:
 * You are given an integer array A of size N.
 * Your task is to find the second most frequent distinct element in the array.
 * The frequency of an element is the number of times it appears in the array.
 *
 * Tie-Breaking Rule:
 * If multiple elements have the same frequency, the greater element should be considered more frequent for ranking purposes.
 *
 * In other words, when comparing two elements:
 * • The element with the higher frequency ranks higher.
 * • If their frequencies are equal, the greater element ranks higher.
 *
 * Return the element that ranks second according to these rules.
 */

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

void solve() 
{
    ll n ; 
    cin >> n ;
    map <ll,ll> mp ;
    for(ll i = 0 ; i < n ; i++)
    {
        ll x ; 
        cin >> x ;
        mp[x]++ ;
    }
    vector < pair < ll , ll > > v ;
    for(auto it : mp)
    {
        v.push_back({it.sc , it.fr}) ;
    }
    sort(v.begin() , v.end()) ;
    if(v.size() < 2)
    {
        cout << -1 << endl ;
    }
    else
    {
        cout << v[v.size() - 2].sc << endl ;
    }
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
    
  