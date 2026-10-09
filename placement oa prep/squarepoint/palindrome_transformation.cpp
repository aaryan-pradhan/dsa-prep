/*
 * Squarepoint: Palindrome Transformation
 *
 * Description:
 * Given an array of integers data of size n, the objective is to convert the array into a 
 * palindromic sequence. 
 *
 * The operation for manipulating the array is:
 * - Choose two integers x and y.
 * - Replace every occurrence of x in the array with y.
 *
 * The task is to determine the minimum number of operations required to transform the array 
 * data into a palindrome.
 *
 * Example:
 * n = 6
 * data = [1, 2, 3, 3, 1, 4]
 *
 * 1) x=1, y=4 -> [4, 2, 3, 3, 4, 4]
 * 2) x=2, y=4 -> [4, 4, 3, 3, 4, 4] (which is a palindrome)
 * Therefore, the minimum operations needed is 2.
 *
 * Function Description:
 * Complete the function getMinOperations(vector<int> data)
 *
 * Constraints:
 * 1 <= n <= 2 * 10^5
 * 1 <= data[i] <= 10^9
 */

// orz
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
struct DSU{
    vector < ll > par , 
}
int getMinOperations(vector<int> data) {
    // Write your solution here
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    cout << getMinOperations(data) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

