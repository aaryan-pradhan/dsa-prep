// Problem: Dynamic Range Sum Queries
// Link: CSES 1648
// Pattern: segment tree, same as templates/segment_tree.cpp — point
// update (set, not add) + range sum query
// Time: O((n + q) log n)  Space: O(n)
//
// Array supports point updates (set position k to u) interleaved with range
// sum queries.
//
// Example:
//     3 2 4 5 1 1 5 3, sum(1,4)=14, sum(5,6)=2, set(3,1), sum(1,4)=11

#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 200020;

struct node {
    ll sum;
    node() { sum = 0; }
};

node t[4 * MAXN];
ll arr[MAXN];
int n;

node merge(node a, node b) {
    node res;
    res.sum = a.sum + b.sum;
    return res;
}

void build(ll id, ll l, ll r) {
    if (l == r) {
        t[id].sum = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

void update(ll id, ll l, ll r, ll pos, ll val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        t[id].sum = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq) {
    if (l > rq || r < lq) return node();
    if (l >= lq && r <= rq) return t[id];
    ll mid = (l + r) / 2;
    node left = query(2 * id, l, mid, lq, rq);
    node right = query(2 * id + 1, mid + 1, r, lq, rq);
    return merge(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            update(1, 0, n - 1, k - 1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1).sum << '\n';
        }
    }

    return 0;
}

// Recall Trail
// - Direct application of templates/segment_tree.cpp unmodified (sum
//   merge, update sets — not adds — a position's value). No adaptation
//   needed beyond wiring up the two query types.
// - 1-indexed queries (k, a, b) map to 0-indexed tree positions via
//   -1, same convention as arrays/23_static_range_minimum_queries.
