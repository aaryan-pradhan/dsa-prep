// Problem: Static Range Sum Queries
// Link: CSES 1646
// Pattern: prefix sums — prefix[i] = sum of first i elements (1-indexed),
// answer for [a,b] is prefix[b] - prefix[a-1]
// Time: O(n + q)  Space: O(n)
//
// Array never changes; answer q range-sum queries.
//
// Example:
//     3 2 4 5 1 1 5 3, query (2,4) -> 11, (5,6) -> 2, (1,8) -> 24, (3,3) -> 4

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}

// Recall Trail
// - prefix[] sized n+1, both indexed 1..n consistently with the
//   1-indexed queries — prefix[0] = 0 as the base case, prefix[i] =
//   prefix[i-1] + x[i].
// - Answer for [a,b] is prefix[b] - prefix[a-1] — no special-casing
//   a == 1 needed since prefix[0] = 0 handles it for free.
