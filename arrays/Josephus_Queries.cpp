// Problem: Josephus Queries (children in a circle)
// Link: CSES 2163
// Pattern: segment tree order-statistics query — find the k-th alive
// element by rank in O(log n), instead of O(n) list simulation
// Time: O(n log n)  Space: O(n)
//
// n children in a circle, indices 1..n. Repeatedly skip k, remove the next
// child. Print the removal order. n up to 2e5, k up to 1e9.
//
// Example:
//     n=7, k=2 -> 3 6 2 7 5 1 4

#include <iostream>
#include <vector>
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

// 0-indexed position of the k-th alive element (1-indexed k).
ll findKth(ll id, ll l, ll r, ll k) {
    if (l == r) return l;
    ll mid = (l + r) / 2;
    if (t[2 * id].sum >= k) return findKth(2 * id, l, mid, k);
    return findKth(2 * id + 1, mid + 1, r, k - t[2 * id].sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) arr[i] = 1;
    build(1, 0, n - 1);

    vector<ll> order(n);
    ll idx = 0;
    int rem = n;
    for (int step = 0; step < n; step++) {
        ll nextRank = (idx + k) % rem + 1;
        ll removed = findKth(1, 0, n - 1, nextRank);
        order[step] = removed;

        update(1, 0, n - 1, removed, 0);
        idx = nextRank - 1;
        rem--;
    }

    for (int i = 0; i < n; i++) cout << order[i] + 1 << (i + 1 < n ? ' ' : '\n');

    return 0;
}

// Recall Trail
// - Direct circular-list simulation is O(n) per removal worst case (k can
//   be far larger than n, forcing a full lap or more), O(n^2) total — too
//   slow. Need O(log n) per removal.
// - Segment tree over an array of 1s (alive)/0s (removed), node.sum = count
//   of alive in that range. findKth(k) descends from the root: if the left
//   child's sum >= k, the answer is in the left half (recurse left, same
//   k); else recurse right with k -= leftChild.sum (skip past everything
//   already counted on the left). O(log n), one path down, no backtracking.
// - Recurrence for which *rank* (not position) gets removed each step:
//   track idx (the rank, among current survivors, "just after" the last
//   removal) and rem (survivor count). nextRank = (idx + k) % rem + 1;
//   removed position = findKth(nextRank). After removing: idx =
//   nextRank - 1, rem-- — the removed rank becomes the new "just after"
//   pointer for the shrunk survivor set, since everyone past it shifts down
//   by one rank.
// - See templates/segment_tree.cpp for the reusable structure — this repo
//   standardizes on segment tree over Fenwick tree/BIT for this family of
//   problems (point-update + order-statistics), since a segment tree covers
//   everything a BIT does plus range queries, with one structure to
//   remember instead of two.
