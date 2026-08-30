// Segment tree: point update, range sum query, 0-indexed [0, n-1].
// findKth is the order-statistics extension — when arr[] holds 0/1 alive
// markers (so node.sum = count of alive elements in that range), it finds
// the position of the k-th alive element in O(log n) by descending the
// tree: go left if the left child's sum already covers k, else subtract
// the left child's sum from k and go right.

typedef long long ll;

const int MAXN = 200020;

struct node {
    ll sum;
    node() { sum = 0; }
};

node t[4 * MAXN];
ll arr[MAXN];

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

// 0-indexed position of the k-th alive element (1-indexed k), given
// arr[]/t[] hold 0/1 alive markers.
ll findKth(ll id, ll l, ll r, ll k) {
    if (l == r) return l;
    ll mid = (l + r) / 2;
    if (t[2 * id].sum >= k) return findKth(2 * id, l, mid, k);
    return findKth(2 * id + 1, mid + 1, r, k - t[2 * id].sum);
}
