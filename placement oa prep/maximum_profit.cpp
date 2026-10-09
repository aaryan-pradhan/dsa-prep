/*
HackerRank OA - Maximum Profit

Problem Description:
A shop owner in the city of Hackerland has n items for sale. 
The items are numbered from 1 to n. The i-th item is in category[i] and has a selling price of price[i].
The owner wishes to sell these items in some order. The profit made on the sale of an item is equal to the 
product of the price of that item and the number of different categories whose items have been sold before 
(including this item's category). Find the maximum possible total profit that can be made by selling the 
items in the optimal order.

Example:
n = 4, category = [3, 1, 2, 3], price = [2, 1, 4, 4]
Output: 29
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long findMaximumProfit(vector<int> c, vector<int> p) {
    map < ll , vector < ll > > g ;
    for(ll i = 0 ; i < c.size() ; i++)
    {
        g[c[i]].push_back(p[i]) ;
    }
    
    vector < ll > fst ; 
    
    // check the first element in every category 
    for(auto &[k , v] : g)
    {
        sort(v.begin() , v.end()) ; 
        fst.push_back(v[0]) ;

    }
    sort(fst.begin() , fst.end()) ;
    ll ans = 0 ;
    for(ll i = 0 ; i < fst.size() ; i++)
    {
        ans += (i + 1) * fst[i] ; 
    }
    for(auto &[k , v] : g)
    {
        for(ll i = 1 ; i < v.size() ; i++)
        {
            ans += v[i] * fst.size() ;
        }
    }
    return ans ;




    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> category = {3, 1, 2, 3};
    vector<int> price = {2, 1, 4, 4};
    cout << findMaximumProfit(category, price) << "\n";
    
    return 0;
}
