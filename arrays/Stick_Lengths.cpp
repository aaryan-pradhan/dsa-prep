// Problem: Stick Lengths
// Link: CSES 1074
// Pattern: sort, target = median, sum absolute deviations
// Time: O(n log n)  Space: O(n)
//
// Minimum total cost to make all sticks equal length, cost per stick =
// |new - old|.
//
// Example:
//     2 3 1 5 2 -> 5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p.begin(), p.end());
    long long median = p[n / 2];

    long long cost = 0;
    for (int i = 0; i < n; i++) cost += abs(p[i] - median);

    cout << cost << '\n';
    return 0;
}

// Recall Trail
// - Minimizing Σ|p_i - m| over m is minimized at the median — proved via
//   pairing smallest with largest after sorting: each pair (p_i,
//   p_{n+1-i}) forces m into [p_i, p_{n+1-i}] to hit that pair's lower
//   bound p_{n+1-i}-p_i, these intervals nest, and their intersection is
//   exactly the median (a point if n odd, a range if n even — either
//   endpoint of that range works since sticks are integers, no averaging
//   needed).
// - Implementation: sort, take p[n/2] as the target (works for both parities
//   since any median value in the tie range gives the same minimal cost), sum
//   abs(p[i] - median).
