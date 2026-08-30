// Problem: Collecting Numbers II
// Link: CSES 2217
// Pattern: same break-counting formula as Collecting Numbers I, but
// maintained incrementally — a swap only changes pos[] for the two
// swapped values, so only their up-to-4 adjacent edges can flip status
// Time: O((n + m) log n)  Space: O(n)
//
// Same "rounds" formula as Collecting Numbers I, but m swaps (positions a,
// b) are applied one at a time, reporting rounds after each. Naive O(n) per
// swap is too slow for n, m up to 2e5.
//
// Example:
//     4 2 1 5 3, swaps (2,3) (1,5) (2,3) -> 2 3 4

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> x(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }

    // edge k means the pair (k-1, k); value w only affects edges k=w and
    // k=w+1, since those are the only pairs w appears in
    auto isBad = [&](int k) {
        return pos[k] < pos[k - 1] ? 1 : 0;
    };

    long long breaks = 1;
    for (int k = 2; k <= n; k++) breaks += isBad(k);

    for (int q = 0; q < m; q++) {
        int a, b;
        cin >> a >> b;
        int u = x[a], v = x[b];

        set<int> edges;
        for (int w : {u, v}) {
            if (w >= 2) edges.insert(w);
            if (w + 1 <= n) edges.insert(w + 1);
        }

        for (int k : edges) breaks -= isBad(k);

        swap(pos[u], pos[v]);
        swap(x[a], x[b]);

        for (int k : edges) breaks += isBad(k);

        cout << breaks  << '\n';
    }

    return 0;
}

// Recall Trail
// - a, b in a query are *array positions*, not values — the values that
//   actually move are u = x[a], v = x[b]. Only pos[u] and pos[v]
//   change.
// - For a single changed value w, exactly two "edges" (break-pairs) can
//   flip: (w-1, w) and (w, w+1) — edge index k means pair (k-1,k),
//   so those are edges k=w and k=w+1. Two changed values -> up to 4
//   candidate edges, but they can overlap if u, v are close in value.
// - Dedupe with a std::set<int> holding the candidate edge indices
//   {u, u+1, v, v+1} (filtered to [2,n]) — no manual overlap casework
//   needed, the set just absorbs duplicates.
// - Update order matters: subtract each edge's old bad/good status from the
//   running break count *before* swapping pos[], then add back each edge's
//   new status *after* — recomputing "after" only, without first undoing
//   "before", double-counts.
// - Answer per query = breaks + 1, same as problem I.
