// Problem: Beautiful Permutation
// Link: CSES 1070
// Pattern: split by parity — evens ascending then odds ascending, so within
// each half consecutive prints differ by 2, and the halves' boundary values
// (largest even, 1) are far apart
// Time: O(n)  Space: O(n) for output buffer
//
// Permutation of 1..n with no adjacent elements differing by exactly 1.
// Print any valid one, or "NO SOLUTION" if none exists.
//
// Example:
//     5 -> 4 2 5 3 1   (any valid beautiful permutation accepted)

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for (int i = 2; i <= n; i += 2) cout << i << ' ';
    for (int i = 1; i <= n; i += 2) cout << i << ' ';
    cout << '\n';

    return 0;
}

// Recall Trail
// - Impossible only for n == 2 and n == 3 — checked all permutations by hand,
//   every arrangement has some adjacent diff of 1. n == 1 is trivially fine
//   (no adjacent pair to violate) despite looking like a small-n edge case.
// - Construction for everything else: print all even numbers ascending, then
//   all odd numbers ascending. Within a half, consecutive values differ by 2.
//   At the boundary (largest even -> 1), the gap is always large enough once
//   n >= 4.
