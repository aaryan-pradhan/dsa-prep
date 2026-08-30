// Problem: Maximum Difference
// Pattern: single pass, running min — max(arr[j] - min_so_far) over i < j
// Time: O(N)  Space: O(1)
//
// Given N elements in an array, select two indexes i and j such that i < j
// and arr[j] - arr[i] is maximum possible. Output that maximum difference.
//
// Example:
//     [1,2,3,4,5] -> 4   (i=0, j=4: 5-1=4)

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

// Recall Trail
// - Not "global max - global min" — that ignores i < j. Counterexample:
//   [5,1], global max=5 comes before global min=1, so the only valid pair
//   gives 1-5=-4, not 5-1=4.
// - Single pass: track min_so_far (min of everything strictly before the
//   current index). At each j, candidate answer is arr[j] - min_so_far;
//   keep the max seen. No clamping to 0 — a strictly decreasing array yields
//   a negative answer, which is correct (least-bad achievable pair).
// - Loop must start at i=1 with min_so_far = arr[0], maxDiff seeded
//   from the first real pair (arr[1]-arr[0]). Starting the loop at i=0
//   with min_so_far already arr[0] lets index 0 pair with itself
//   (arr[0]-arr[0]=0), which can inflate the answer above what any real
//   i<j pair achieves on a decreasing array.
