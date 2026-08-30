// Problem: Parity-Constrained Sort (Boys/Girls Line)
// Pattern: split by parity, sort each group independently, re-merge on a
//          second pass keyed on the same parity check (no stored indices)
// Time: O(N log N) per test case  Space: O(N)
//
// T test cases. Each has N integers. Only same-parity elements may be
// swapped with each other (evens with evens, odds with odds). Output the
// permutation closest to fully non-decreasing achievable under that
// constraint. Multiple answers accepted if tied.
//
// Example:
//     [2,3,9,1,2,7] -> [2,1,3,7,2,9]
//         [4,2,8]       -> [2,4,8]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> evens, odds;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) evens.push_back(a[i]);
            else odds.push_back(a[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());

        int ei = 0, oi = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) a[i] = evens[ei++];
            else a[i] = odds[oi++];
        }

        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}

// Recall Trail
// - Same-parity swaps mean any permutation *within* a parity class is
//   reachable, but nothing crosses classes — a position that started even
//   can never end up odd. So the fixed structure is "which positions belong
//   to which class," not the values themselves.
// - Within each class, full freedom → sort that class ascending eliminates
//   all inversions inside it; cross-class inversions are unavoidable
//   regardless of internal order, so sorting each class is optimal.
// - Don't store index/position arrays. Two passes over the same array:
//   pass 1 buckets values into evens/odds by a[i]%2; sort both; pass 2
//   re-checks a[i]%2 (same test, not stored) to decide which sorted
//   bucket's next value to overwrite a[i] with, via two pointers
//   (ei, oi). No map, no stored positions — the parity check itself is
//   cheap enough to just redo.
// - Naturally handles all-even / all-odd arrays with no special-casing — one
//   bucket just stays empty and its pointer is never advanced.
