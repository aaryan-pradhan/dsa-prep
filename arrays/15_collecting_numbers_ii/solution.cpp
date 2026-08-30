// Problem: Collecting Numbers II
// Pattern: same break-counting formula as Collecting Numbers I, but
// maintained incrementally — a swap only changes pos[] for the two
// swapped values, so only their up-to-4 adjacent edges can flip status
// Time: O((n + m) log n)  Space: O(n)

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
