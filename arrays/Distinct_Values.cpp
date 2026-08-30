// Problem: Distinct Values
// Link: CSES 1621
// Pattern: sort, count runs of equal adjacent values
// Time: O(n log n)  Space: O(n)
//
// unordered_set with the default hash is vulnerable to CSES's anti-hash
// test (collisions force O(n) per op) -> TLE. Sort is immune to that.
//
// Count distinct values in a list of n integers.
//
// Example:
//     2 3 2 2 3 -> 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    int distinct = n > 0 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (x[i] != x[i - 1]) distinct++;
    }

    cout << distinct << '\n';
    return 0;
}

// Recall Trail
// - First pass used unordered_set — TLE'd on CSES's final test case.
//   CSES includes an anti-hash test targeting the default unordered_set/
//   unordered_map hash on integers, forcing collisions and O(n) per op.
//   Fixed by sorting instead: count runs of equal adjacent values after
//   sort(). Immune to adversarial input, same O(n log n).
