/*
Count the Number of Fair Pairs

Problem Description:
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
A pair (i, j) is fair if:
0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper

Example 1:
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
-10^9 <= lower <= upper <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end()); 
    ll n = nums.size() ; 
    ll t = 0 ; 
    ll h = -1 ; 
    ll target = upper ; 
    ll ans = 0 ; 
    

    }


    return 0;
}

void solve() {
    // Example test case 1
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    cout << countFairPairs(nums, lower, upper) << "\n";
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
