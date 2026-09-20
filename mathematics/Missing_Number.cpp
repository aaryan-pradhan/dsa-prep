// Problem: Missing Number
// Link: CSES 1083
// Pattern: XOR 1..n with the given values — duplicates cancel, only the missing one survives
// Time: O(n)  Space: O(1)
//
// Given n and n-1 distinct values from 1..n, find the missing one.
//
// Example:
//     n=5, [2 3 1 5] -> 4

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    long long x = 0;
    for (int i = 1; i <= n; i++) x ^= i;

    int v;
    for (int i = 0; i < n - 1; i++) {
        cin >> v;
        x ^= v;
    }

    cout << x << '\n';
    return 0;
}

// Recall Trail
// - XOR everything from 1..n together, then XOR every input value into the
//   same accumulator. Every present value appears twice (once from the 1..n
//   sweep, once from input) and cancels via x ^ x = 0; only the missing
//   value's contribution survives.
// - No need to store the input array — fold each value into the accumulator
//   as it's read.
