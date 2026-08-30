// Problem: Missing Coin Sum
// Link: CSES 1745
// Pattern: sort ascending, greedily extend the contiguous achievable-sum
// range [0, R]; a coin x extends it iff x <= R+1, else R+1 is the answer
// Time: O(n log n)  Space: O(n)
//
// Smallest positive sum not formable as a subset sum of the given coins.
//
// Example:
//     2 9 1 2 7 -> 6

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    long long r = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > r + 1) break;
        r += x[i];
    }

    cout << r + 1 << '\n';
    return 0;
}

// Recall Trail
// - Sort coins ascending. Invariant: after processing some prefix, every sum
//   in [0, R] is achievable.
// - Next coin x extends the range iff x <= R+1 (equality included — x ==
//   R+1 still closes the gap, since [0,R] ∪ {R+1..R+1+x} stays
//   contiguous). If x > R+1, R+1 is unreachable and nothing after it
//   (all sorted larger) can fix that — answer is R+1, stop immediately.
// - If the loop finishes without a gap, all coins summed and R+1 is still
//   the answer (the range covers everything the coins can build).
