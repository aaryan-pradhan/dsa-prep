// Problem: Static Range Minimum Queries
// Pattern: segment tree, same template as templates/segment_tree.cpp,
// merge swapped to min (identity = +infinity instead of 0)
// Time: O((n + q) log n)  Space: O(n)

#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 200020;
const ll INF = 2e18;

struct node {
    ll mn;
    node() { mn = INF; }
};

node t[4 * MAXN];
ll arr[MAXN];
int n;

node merge(node a, node b) {
    node res;
    res.mn = min(a.mn, b.mn);
    return res;
}

void build(ll id, ll l, ll r) {
    if (l == r) {
        t[id].mn = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
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
        int a, b;
        cin >> a >> b;
        cout << query(1, 0, n - 1, a - 1, b - 1).mn << '\n';
    }

    return 0;
}
