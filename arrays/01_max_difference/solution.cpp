// Problem: Maximum Difference
// Pattern: single pass, running min — max(arr[j] - min_so_far) over i < j
// Time: O(N)  Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxDifference(vector<int>& arr) {
    int minSoFar = arr[0];
    int maxDiff = arr[1] - arr[0];

    for (int i = 1; i < (int)arr.size(); i++) {
        maxDiff = max(maxDiff, arr[i] - minSoFar);
        minSoFar = min(minSoFar, arr[i]);
    }

    return maxDiff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << maxDifference(arr) << "\n";
    return 0;
}
